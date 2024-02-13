.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100
	ldc 11
	istore 0
	iload 0
	goto L_switch_begin_0
L_case_0:
	ldc "A"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_switch_end_0
L_case_1:
	ldc "B"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_switch_end_0
L_case_2:
	ldc "C"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_switch_end_0
L_case_3:
	ldc "D"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_switch_end_0
L_case_4:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	goto L_switch_end_0
L_switch_begin_0:
	lookupswitch
	0: L_case_0
	1: L_case_1
	2: L_case_2
	3: L_case_3
	default: L_case_4
L_switch_end_0:
	iload 0
	goto L_switch_begin_1
L_case_5:
	ldc "A"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_switch_end_1
L_case_6:
	ldc "B"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_switch_end_1
L_case_7:
	ldc "C"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_switch_end_1
L_case_8:
	ldc "D"
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	goto L_switch_end_1
L_case_9:
	iload 0
	getstatic java/lang/System/out Ljava/io/PrintStream;
	swap
	invokevirtual java/io/PrintStream/println(I)V
	goto L_switch_end_1
L_switch_begin_1:
	lookupswitch
	10: L_case_5
	11: L_case_6
	12: L_case_7
	13: L_case_8
	default: L_case_9
L_switch_end_1:
	return
.end method
