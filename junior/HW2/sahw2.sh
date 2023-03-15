#!/usr/local/bin/bash

usage() {
	echo -n -e "\nUsage: sahw2.sh {--sha256 hashes ... | --md5 hashes ...} -i files ...\n\n--sha256: SHA256 hashes to validate input files.\n--md5: MD5 hashes to validate input files.\n-i: Input files.\n"
}

echoerr() {
    echo -n "$@" 1>&2;
}

user_exists() {
    id "$1" &>/dev/null;
}

algorithms=()
hashes=()
files=()
usernames=()
passwords=()
shells=()
groups=()
numOfGroups=()

while getopts 'hi:-:' op; do
    case "$op" in
        -)
            algorithms+=(${OPTARG})
            case "${OPTARG}" in
                md5|sha256)
                    while [[ $(eval "echo \${$OPTIND}") =~ ^[a-zA-Z0-9]+$ ]] ; do
                        hashes+=($(eval "echo \${$OPTIND}"))
                        OPTIND=$((OPTIND+1))
                    done
                        ;;
                *)
                    echoerr "Error: Invalid arguments."
                    usage
                    exit 1
                    ;;
            esac;;
            
        h)
            usage
            exit 0
            ;;
        i)
            files=($OPTARG)
            while [[ $(eval "echo \${$OPTIND}") =~ ^[a-zA-Z0-9/]+$ ]] ; do
                files+=($(eval "echo \${$OPTIND}"))
                OPTIND=$((OPTIND+1))
            done
            ;;
        *)
            echoerr "Error: Invalid arguments."
            usage
            exit 1
            ;;
    esac
done

#check number of hash algorithms
if (( ${#algorithms[@]} > 1 )) ; then
    echoerr "Error: Only one type of hash function is allowed."
    exit 1
fi
#check if the number of hash number and files the same
if (( ${#hashes[@]} != ${#files[@]} )) ; then
    echoerr "Error: Invalid values."
    exit 1
fi
#iterate all files to check if exists, file type and checksum
for i in ${!files[@]} ; do
    if ! [[ -e ${files[i]} ]] ; then
        echoerr "Error: File ${files[i]} not exists"
        exit 1
    else             
        case "`file ${files[i]} | awk '{print $2}'`" in
            JSON)
                while read usr ; do
                    usernames+=( `jq '.username' <<< ${usr} | tr -d '\"'` )
                    passwords+=( `jq '.password' <<< ${usr} | tr -d '\"'` )
                    shells+=(`jq '.shell' <<< ${usr} | tr -d '\"'` )
                    groups+=(`jq '.groups' <<< ${usr} | tr -d '\"\n\r' | sed "s/ //g"` )
                done < <(jq -c '.[]' ${files[i]})
            ;;
            CSV)
                while IFS="," read username password shell group
                do
                    usernames+=(${username})
                    passwords+=(${password})
                    shells+=(${shell})
                    groups+=(\[`echo ${group[@]} | tr -d '\r' | sed "s/ /,/g"`\])
                done < <(tail -n +2 ${files[i]})
            ;;
            *)
                echoerr "Error: Invalid file format."
                exit 1
            ;;
        esac
    fi
    #check the shecksum value
    case "${algorithms[0]}" in
        md5)
            if [ ${hashes[i]} != "`md5sum ${files[i]} | awk '{print $1}'`" ] ; then
                echoerr "Error: Invalid checksum."
                exit 1
            fi ;;
        sha256)
            if [ ${hashes[i]} != "`sha256 ${files[i]} | awk '{print $4}'`" ] ; then
                echoerr "Error: Invalid checksum."
                exit 1
            fi ;;
    esac
done

echo -n "This script will create the following user(s): ${usernames[@]} Do you want to continue? [y/n]: "
read answer

case ${answer} in
    [Yy])
        for i in ${!usernames[@]} ; do
            if user_exists ${usernames[i]} ; then
                echo "Warning: user ${usernames[i]} already exists."
            else
                group_list=""
                for g in `echo ${groups[i]} | tr -d '[]' | sed 's/,/ /g'`;do
                    group_list+="-G ${g} "
                    if ! [ `getent group ${g}` ] ; then
                        pw groupadd ${g}
                    fi
                done
                echo ${passwords[i]} | pw useradd -n ${usernames[i]} ${group_list} -s ${shells[i]} -m -h 0 &>/dev/null 
            fi
        done
    ;;
    [Nn]|"")
        exit 0
    ;;
esac	

exit 0
