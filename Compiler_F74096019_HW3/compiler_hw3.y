/* Please feel free to modify any content */

/* Definition section */
%{
    #include "compiler_hw_common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;
	typedef struct symbol {
		int Index;
        char *Name;
		char *Type;
		int Addr;
		int Lineno;
		char *Fs;
    }Symbol;
    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    int yylex_destroy ();
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* Used to generate code */
    /* As printf; the usage: CODEGEN("%d - %s\n", 100, "Hello world"); */
    /* We do not enforce the use of this macro */
    #define CODEGEN(...) \
        do { \
            for (int i = 0; i < g_indent_cnt; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    /* Symbol table function - you can add new functions if needed. */
    /* parameters and return type can be changed */
    static void create_symbol();
    static void insert_symbol();
    static struct symbol lookup_symbol();
    static void dump_symbol();
	static char *top();
	static void pop_op();
	static void print_operator();
	static void error_check();

	static void CODEGEN_load();
	static void CODEGEN_store();	
	static void CODEGEN_print();
	static void CODEGEN_op();
	

    /* Global variables */
    bool g_has_error = false;
    FILE *fout = NULL;
    int g_indent_cnt = 0;
	bool HAS_ERROR = false;
    int num_of_symbol[10] = {0};
	struct symbol symbol_table[10][10];
    int scope_level = -1;
	int address = 0;
	char func_sig[10][10];
	char *tmp_type;
	char *func_name;
	char *operation;
	char *tmp_str;
	int top_op = -1;
	char *op_stack[100];
	int precedence_stack[100];
	char *type_stack[100];
	int type_top = -1;

	bool func_return;
	int L_cmp_num = 0;
	int L_switch_num = -1;
	int L_case_num = -1;
	int last_case = 0;
	int cases[20];
	int L_for_num = -1;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 *  - you can add new fields if needed.
 */
%union {
    int i_val;
    float f_val;
    char *s_val;
    bool b_val;
}

/* Token without return */
%token VAR NEWLINE
%token INT FLOAT BOOL STRING TRUE FALSE
%token INC DEC GEQ LOR LAND LEQ EQL NEQ
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token IF ELSE FOR SWITCH CASE DEFAULT
%token PRINT PRINTLN
%token PACKAGE FUNC RETURN

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT
%token <s_val> STRING_LIT
%token <b_val> BOOL_LIT
%token <s_val> IDENT

/* Nonterminal with return, which need to sepcify type */
//%type <s_val> Type

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : GlobalStatementList { dump_symbol(scope_level--); }
;

GlobalStatementList 
    : GlobalStatementList GlobalStatement
    | GlobalStatement
;

GlobalStatement
    : PackageStmt NEWLINE
    | FunctionDeclStmt
    | NEWLINE
;


PackageStmt
    : PACKAGE IDENT { create_symbol(++scope_level); } { printf("package: %s\n", $<s_val>2); }
;

FunctionDeclStmt
    : FuncOpen { create_symbol(++scope_level); strcpy(func_sig[num_of_symbol[scope_level-1]],"("); } '(' 
	  ParameterList ')'{type_top = -1; strcat(func_sig[num_of_symbol[scope_level-1]], ")"); } 
	  ReturnType { printf("func_signature: %s\n", func_sig[num_of_symbol[scope_level-1]]); 
	  if(strcmp(func_name, "main") == 0){ CODEGEN(".method public static main([Ljava/lang/String;)V\n"); }
	  else{ CODEGEN(".method public static %s%s\n", func_name, func_sig[num_of_symbol[scope_level-1]]); }
	  CODEGEN(".limit stack 100\n"); CODEGEN(".limit locals 100\n"); g_indent_cnt++; func_return = false;
	  insert_symbol(func_name, "func", -1, yylineno+1, func_sig[num_of_symbol[scope_level-1]], scope_level-1); } 
	  FuncBlock { dump_symbol(scope_level); scope_level--; if(!func_return){ CODEGEN("return\n"); } g_indent_cnt--; CODEGEN(".end method\n"); }
;

FuncOpen
	: FUNC IDENT { printf("func: %s\n", $<s_val>2); func_name = $<s_val>2; } 
;

ParameterList
	: IDENT ParamType { printf("param %s, type: %c\n", $<s_val>1, func_sig[num_of_symbol[scope_level-1]][strlen(func_sig[num_of_symbol[scope_level-1]])-1]); 
	  insert_symbol($<s_val>1, type_stack[type_top--], address++, yylineno+1, "-", scope_level); } ParameterList
	| ',' ParameterList 
	| 
;

ParamType
	: INT    { strcat(func_sig[num_of_symbol[scope_level-1]],"I"); type_stack[++type_top] = "int32"; }
    | FLOAT  { strcat(func_sig[num_of_symbol[scope_level-1]],"F"); type_stack[++type_top] = "float32"; } 
    | STRING { strcat(func_sig[num_of_symbol[scope_level-1]],"S"); type_stack[++type_top] = "string"; }
    | BOOL   { strcat(func_sig[num_of_symbol[scope_level-1]],"B"); type_stack[++type_top] = "bool"; }
;

ReturnType
	: INT    { strcat(func_sig[num_of_symbol[scope_level-1]],"I"); }
    | FLOAT  { strcat(func_sig[num_of_symbol[scope_level-1]],"F"); } 
    | STRING { strcat(func_sig[num_of_symbol[scope_level-1]],"S"); }
    | BOOL   { strcat(func_sig[num_of_symbol[scope_level-1]],"B"); }
	| { strcat(func_sig[num_of_symbol[scope_level-1]],"V"); }
;

FuncBlock
	: '{' StatementList '}'
;

ReturnStmt
	: RETURN HaveReturn { func_return = true; }
;

HaveReturn
	: Expression { print_operator(7); if(strcmp(type_stack[type_top--], "int32") == 0){ printf("ireturn\n"); CODEGEN("ireturn\n"); } 
	  if(strcmp(type_stack[type_top--], "float32") == 0){ printf("freturn\n"); CODEGEN("freturn\n"); } }
	| { printf("return\n"); CODEGEN("return\n"); }
;

Statement
	: DeclarationStmt NEWLINE
	| SimpleStmt NEWLINE
	| Block
	| IfStmt
	| ForStmt
	| SwitchStmt
	| CaseStmt
	| PrintStmt NEWLINE
	| ReturnStmt NEWLINE
	| NEWLINE
	| call_func NEWLINE
;

call_func
	: IDENT '(' input_list ')' { Symbol target = lookup_symbol($<s_val>1, 0); printf("call: %s%s\n", $<s_val>1, target.Fs); CODEGEN("invokestatic Main/%s%s\n", target.Name, target.Fs); }
;

input_list
	: input input_list
	| ',' input_list
	|
;

input
	: IDENT { Symbol target = lookup_symbol($<s_val>1); printf("IDENT (name=%s, address=%d)\n", target.Name, target.Addr); CODEGEN_load(target); }
	| INT_LIT { printf("INT_LIT %d\n", $<i_val>1); CODEGEN("ldc %d\n", $<i_val>1); }
	| FLOAT_LIT { printf("FLOAT_LIT %f\n", $<f_val>1); CODEGEN("ldc %f\n", $<f_val>1); }
;

DeclarationStmt
	: VAR IDENT Type Assign_ornot { print_operator(7); Symbol target = lookup_symbol($<s_val>2, 1); 
	  if(strcmp(target.Name, $<s_val>2) == 0){ printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", yylineno, $<s_val>2, target.Lineno); g_has_error = true; } 
	  insert_symbol($<s_val>2, type_stack[type_top--], address++, yylineno, "-", scope_level); CODEGEN_store(lookup_symbol($<s_val>2, 1)); }
;

Assign_ornot
	: '=' Expression
	| { if(strcmp(type_stack[type_top], "int32") == 0){ CODEGEN("ldc 0\n"); }
	  else if(strcmp(type_stack[type_top], "float32") == 0){ CODEGEN("ldc 0.0\n"); }
	  else if(strcmp(type_stack[type_top], "string") == 0){ CODEGEN("ldc \"\"\n"); } }
;

SimpleStmt
	: AssignmentStmt {print_operator(7); type_top = -1; }
	| ExpressionStmt {print_operator(7); type_top = -1; }
	| IncDecStmt
;

AssignmentStmt
	: Expression assign_op Expression {print_operator(7); CODEGEN_store(lookup_symbol($<s_val>1, 0)); }
;

assign_op
	: '='        { tmp_str = "ASSIGN"; op_stack[++top_op] = "ASSIGN"; precedence_stack[top_op] = 7; }
	| ADD_ASSIGN { tmp_str = "ADD"; op_stack[++top_op] = "ADD"; precedence_stack[top_op] = 7; }
	| SUB_ASSIGN { tmp_str = "SUB"; op_stack[++top_op] = "SUB"; precedence_stack[top_op] = 7; }
	| MUL_ASSIGN { tmp_str = "MUL"; op_stack[++top_op] = "MUL"; precedence_stack[top_op] = 7; }
	| QUO_ASSIGN { tmp_str = "QUO"; op_stack[++top_op] = "QUO"; precedence_stack[top_op] = 7; }
	| REM_ASSIGN { tmp_str = "REM"; op_stack[++top_op] = "REM"; precedence_stack[top_op] = 7; }
;

ExpressionStmt
	: Expression
;

IncDecStmt
	: Expression INC_DEC { if(strcmp(type_stack[type_top--], "int32") == 0){CODEGEN("ldc 1\n"); CODEGEN("i%s\n", top()); }
	  else{CODEGEN("ldc 1.0\n"); CODEGEN("f%s\n", top()); } pop_op(); CODEGEN_store(lookup_symbol($<s_val>1, 0)); }
;

INC_DEC
	: INC { printf("INC\n"); op_stack[++top_op] = "add"; }
	| DEC { printf("DEC\n"); op_stack[++top_op] = "sub"; }
;

Block
	: '{' { create_symbol(++scope_level); }  StatementList '}' { dump_symbol(scope_level--); }
;

StatementList
	: Statement StatementList
	| 
;

IfStmt
	: IF Condition { if(strcmp(type_stack[type_top], "bool") != 0){ printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, type_stack[type_top--]); } } Block If_Else
;

If_Else
	: ELSE If_Block
	|
;

If_Block
	: IfStmt
	| Block
;

Condition
	: Expression { print_operator(7); }
;

ForStmt
	: FOR {g_indent_cnt--; CODEGEN("L_for_begin_%d:\n", ++L_for_num); g_indent_cnt++; } ForType
;

ForType
	: Condition { if(strcmp(type_stack[type_top], "bool") != 0){ printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, type_stack[type_top--]); 
	  g_has_error = true; } CODEGEN("ifeq L_for_exit_%d\n", L_for_num); } 
	  Block { CODEGEN("goto L_for_begin_%d\n", L_for_num); g_indent_cnt--; CODEGEN("L_for_exit_%d:\n", L_for_num); g_indent_cnt++; }
	| ForClause Block { CODEGEN("goto L_for_begin_%d\n", L_for_num); g_indent_cnt--; CODEGEN("L_for_exit_%d:\n", L_for_num); g_indent_cnt++; }
;

ForClause
	: InitStmt ';' Condition ';' PostStmt
;

InitStmt
	: SimpleStmt
;

PostStmt
	: SimpleStmt
;

SwitchStmt
	: SWITCH Expression { CODEGEN("goto L_switch_begin_%d\n", ++L_switch_num); } 
	  Block { g_indent_cnt--; CODEGEN("L_switch_begin_%d:\n", L_switch_num); g_indent_cnt++; CODEGEN("lookupswitch\n"); 
	  for(int i = last_case; i < L_case_num; i++){ CODEGEN("%d: L_case_%d\n", cases[i], i); } CODEGEN("default: L_case_%d\n", L_case_num); 
	  g_indent_cnt--; CODEGEN("L_switch_end_%d:\n", L_switch_num); g_indent_cnt++; last_case = L_case_num+1; }
;

CaseStmt
	: CASE INT_LIT { printf("case %d\n", $<i_val>2); g_indent_cnt--; CODEGEN("L_case_%d:\n", ++L_case_num); g_indent_cnt++; } ':' 
	  Block { cases[L_case_num] = $<i_val>2; CODEGEN("goto L_switch_end_%d\n", L_switch_num); }
	| DEFAULT { g_indent_cnt--; CODEGEN("L_case_%d:\n", ++L_case_num); g_indent_cnt++;} ':' Block { CODEGEN("goto L_switch_end_%d\n", L_switch_num); }
;

PrintStmt
	: PRINT '(' Expression ')'   { print_operator(7); CODEGEN_print("print", type_stack[type_top]); printf("PRINT %s\n", type_stack[type_top--]); }
	| PRINTLN '(' Expression ')' { print_operator(7); CODEGEN_print("println", type_stack[type_top]); printf("PRINTLN %s\n", type_stack[type_top--]); };
;

Type
	: INT    { type_stack[++type_top] = "int32"; }
	| FLOAT  { type_stack[++type_top] = "float32"; } 
	| STRING { type_stack[++type_top] = "string"; }
	| BOOL   { type_stack[++type_top] = "bool"; }
;

Expression
	: UnaryExpr
	| Expression binary_op Expression
	| '"' STRING_LIT  '"' { CODEGEN("ldc \"%s\"\n", $<s_val>2); printf("STRING_LIT %s\n", $<s_val>2); type_stack[++type_top] = "string"; }
	| call_func
;

UnaryExpr
	: PrimaryExpr
	| unary_op UnaryExpr
;

binary_op
	: LOR  { print_operator(6); op_stack[++top_op] = "LOR"; precedence_stack[top_op] = 6; }
	| LAND { print_operator(5); op_stack[++top_op] = "LAND"; precedence_stack[top_op] = 5; }
	| cmp_op
	| add_op
	| mul_op
;

cmp_op
	: EQL {	print_operator(4); op_stack[++top_op] = "EQL"; precedence_stack[top_op] = 4; }
	| NEQ { print_operator(4); op_stack[++top_op] = "NEQ"; precedence_stack[top_op] = 4; }
	| '<' { print_operator(4); op_stack[++top_op] = "SLR"; precedence_stack[top_op] = 4; }
	| LEQ { print_operator(4); op_stack[++top_op] = "LEQ"; precedence_stack[top_op] = 4; }
	| '>' { print_operator(4); op_stack[++top_op] = "GTR"; precedence_stack[top_op] = 4; }
	| GEQ { print_operator(4); op_stack[++top_op] = "GEQ"; precedence_stack[top_op] = 4; }
;

add_op
	: '+' { print_operator(3); op_stack[++top_op] = "ADD"; precedence_stack[top_op] = 3; }
	| '-' { print_operator(3); op_stack[++top_op] = "SUB"; precedence_stack[top_op] = 3; }
;

mul_op
	: '*' { print_operator(2); op_stack[++top_op] = "MUL"; precedence_stack[top_op] = 2; }
	| '/' { print_operator(2); op_stack[++top_op] = "QUO"; precedence_stack[top_op] = 2; }	
	| '%' { print_operator(2); op_stack[++top_op] = "REM"; precedence_stack[top_op] = 2; }
;

unary_op
	: '+' { print_operator(1); op_stack[++top_op] = "POS"; precedence_stack[top_op] = 1; }
	| '-' { print_operator(1); op_stack[++top_op] = "NEG"; precedence_stack[top_op] = 1; }
	| { print_operator(1); } Dup_Not
;

Dup_Not
	: '!' { op_stack[++top_op] = "NOT"; precedence_stack[top_op] = 1; } Dup_Not
	|
;

PrimaryExpr
	: Operand
/*	| IndexExpr */
	| ConversionExpr
;

Operand
	: Literal
	| IDENT { Symbol target = lookup_symbol($<s_val>1, 0);
	  if(strcmp(target.Name, "NOT_FOUND") != 0){ type_stack[++type_top] = target.Type; CODEGEN_load(target); 
	  printf("IDENT (name=%s, address=%d)\n", target.Name, target.Addr);} 
	  else{ type_stack[++type_top] = "ERROR"; printf("error:%d: undefined: %s\n", yylineno+1, $<s_val>1); g_has_error = true; } }
	| '('{ op_stack[++top_op] = "L_Bracket"; precedence_stack[top_op] = 7; } 
	  Expression ')' { while(strcmp(op_stack[top_op], "L_Bracket") != 0){ printf("%s\n", top()); CODEGEN_op(); pop_op(); } pop_op(); }
;

Literal
	: INT_LIT   { printf("INT_LIT %d\n", $<i_val>1); CODEGEN("ldc %d\n", $<i_val>1); type_stack[++type_top] = "int32"; }
	| FLOAT_LIT { printf("FLOAT_LIT %f\n", $<f_val>1); CODEGEN("ldc %f\n", $<f_val>1); type_stack[++type_top] = "float32"; }
	| BOOL_LIT  { printf("%s %d\n", yylval.b_val ? "TRUE":"FALSE", yylval.b_val); if(yylval.b_val){ CODEGEN("iconst_1\n"); }else{CODEGEN("iconst_0\n");}  type_stack[++type_top] = "bool"; }
	| STRING_LIT
;

ConversionExpr
	: Type '(' Expression ')' { if(strcmp(type_stack[type_top--], "int32") == 0){ printf("i2f\n"); type_stack[++type_top] = "float32"; CODEGEN("i2f\n"); } 
	  else{ printf("f2i\n"); type_stack[++type_top] = "int32"; CODEGEN("f2i\n");} }
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", argv[1]);
        exit(1);
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    CODEGEN(".source hw3.j\n");
    CODEGEN(".class public Main\n");
    CODEGEN(".super java/lang/Object\n");

    /* Symbol table init */
    // Add your code

    yylineno = 0;
    yyparse();

    /* Symbol table dump */
    // Add your code

	printf("Total lines: %d\n", yylineno);
    fclose(fout);
    fclose(yyin);

    if (g_has_error) {
        remove(bytecode_filename);
    }
    yylex_destroy();
    return 0;
}

static void create_symbol(int level) {
    printf("> Create symbol table (scope level %d)\n", level);
}

static void insert_symbol(char *name, char*type, int addr, int line_num, char *fs, int level) {
	printf("> Insert `%s` (addr: %d) to scope level %d\n", name, addr, level);
	struct symbol newsymbol = { num_of_symbol[level], name, type, addr, line_num, fs};
	symbol_table[level][num_of_symbol[level]] = newsymbol;
	num_of_symbol[level]++;
}

static Symbol lookup_symbol(char *target_name, int only_this_scope) {
	struct symbol to_return = {-1, "NOT_FOUND", "NULL", -1, -1, "-"} ;
	bool isfound = false;
	int level = scope_level;
	for(;!isfound && level >= 0; level--){
		for(int i = 0; i < num_of_symbol[level]; ++i){
        	if(strcmp(target_name, symbol_table[level][i].Name) == 0){
            	to_return = symbol_table[level][i];
				isfound = true;	
			}
    	}
		if(only_this_scope)
			break;
	}
	return to_return;
}

static void dump_symbol(int level) {
    printf("\n> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%-10s\n",
           "Index", "Name", "Type", "Addr", "Lineno", "Func_sig");
    for(int i = 0; i < num_of_symbol[level]; ++i){
		struct symbol st = symbol_table[level][i];
        printf("%-10d%-10s%-10s%-10d%-10d%-10s\n", st.Index, st.Name, st.Type, st.Addr, st.Lineno, st.Fs);
    }
	num_of_symbol[level] = 0;
	printf("\n");
}

static char *top(){
	if(top_op >= 0)
		return op_stack[top_op];
	else
		return "";
}

static void pop_op(){
	if(top_op >= 0)
		top_op--;
}

static void print_operator(int now_precedence){
	while(precedence_stack[top_op] <= now_precedence && top_op >= 0){
		if(type_top >= 1){
			CODEGEN_op();
			error_check();
		}
		printf("%s\n", top());
		pop_op();
	}
}
static void error_check(){
	char *operand2 = type_stack[type_top--], *operand1 = type_stack[type_top--], *op = top();
	char *result = operand1;
	//printf("%s %s %s\n", operand1, operand2, op);
	switch(precedence_stack[top_op]){
		case 1: type_stack[++type_top] = operand1;
				if(strcmp(op, "NOT") == 0){
					result = "bool";
				}
				else{
					if(strcmp(operand2, "int32") == 0)
						result = "int32";
					else
						result = "float32";
				}
				break;
		case 2: if(strcmp(op, "REM") == 0 && strcmp(operand2, "float32") == 0){
					printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno);
					g_has_error = true;
				}
				break;
		case 3: if(strcmp(operand1, operand2) != 0){
                    printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, top(), operand1, operand2);
                	g_has_error = true;
				}
				break;
		case 4: if(strcmp(operand1, "ERROR") == 0 || strcmp(operand2, "ERROR") == 0){
					printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno+1, top(), operand1, operand2);
					g_has_error = true;
				}	
				result = "bool"; 
				break;
		case 5: if(strcmp(operand1, "bool") != 0){
                	printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, operand1);
                	g_has_error = true;
				}   
                else if(strcmp(operand2, "bool") != 0){
                	printf("error:%d: invalid operation: (operator LAND not defined on %s)\n", yylineno, operand2);
                	g_has_error = true;
				}
				result = "bool";
                break;
		case 6: if(strcmp(operand1, "bool") != 0){
					printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, operand1);
					g_has_error = true;
				}
				else if(strcmp(operand2, "bool") != 0){
					printf("error:%d: invalid operation: (operator LOR not defined on %s)\n", yylineno, operand2);
					g_has_error = true;
				}
				result = "bool";
				break;
		case 7: if(strcmp(operand1, operand2) != 0){
                    printf("error:%d: invalid operation: %s (mismatched types %s and %s)\n", yylineno, top(), operand1, operand2);
                	g_has_error = true;
				}
				break;
		default: break;
	}
	type_stack[++type_top] = result;
}

static void CODEGEN_load(Symbol s){
	if(strcmp(s.Type, "int32") == 0)
        CODEGEN("iload %d\n", s.Addr);
    else if(strcmp(s.Type, "float32") == 0)
        CODEGEN("fload %d\n", s.Addr);
    else if(strcmp(s.Type, "string") == 0)
        CODEGEN("aload %d\n", s.Addr);	
}

static void CODEGEN_store(Symbol s){
	if(strcmp(s.Type, "int32") == 0)
		CODEGEN("istore %d\n", s.Addr);
	else if(strcmp(s.Type, "float32") == 0)
		CODEGEN("fstore %d\n", s.Addr);
	else if(strcmp(s.Type, "string") == 0)
		CODEGEN("astore %d\n", s.Addr);
}

static void CODEGEN_print(char *print_type, char *element_type){
	char *c;
	if(strcmp(element_type, "int32") == 0)
		c = "I";
	else if(strcmp(element_type, "float32") == 0)
		c = "F";
	else if(strcmp(element_type, "bool") == 0){
		c = "Ljava/lang/String;";
		CODEGEN("ifne L_cmp_%d\n", L_cmp_num);
		CODEGEN("ldc \"false\"\n");
		CODEGEN("goto L_cmp_%d\n", L_cmp_num+1);
		g_indent_cnt--; CODEGEN("L_cmp_%d:\n", L_cmp_num); g_indent_cnt++;
		CODEGEN("ldc \"true\"\n");
		g_indent_cnt--; CODEGEN("L_cmp_%d:\n", ++L_cmp_num); g_indent_cnt++;
		++L_cmp_num;
	}
	else if(strcmp(element_type, "string") == 0)
		c = "Ljava/lang/String;";
	CODEGEN("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
	CODEGEN("swap\n");
	CODEGEN("invokevirtual java/io/PrintStream/%s(%s)V\n", print_type, c);
}

static void CODEGEN_op(){
	char *operand = type_stack[type_top];
	char *op = top();
	char result[4];
	if(strcmp(op, "POS") == 0)
		return;
	/*  + / - * -  */
	if((precedence_stack[top_op] >= 1 && precedence_stack[top_op] <= 3 && strcmp(op, "NOT") != 0) || (precedence_stack[top_op] == 7 && strcmp(op, "ASSIGN") != 0) ){
		if(strcmp(operand, "int32") == 0)
			strcpy(result, "i");
		else if(strcmp(operand, "float32") == 0)
			strcpy(result, "f");
		if(strcmp(op, "QUO") == 0)
			strcat(result,"div");
		else
			for(int i = 0; i < 3; i++){
				result[i+1] = op[i] + 32;
			}
		CODEGEN("%s\n", result);
	}
	else if(precedence_stack[top_op] == 4){
		if(strcmp(operand, "int32") == 0)
			CODEGEN("isub\n");
		else if(strcmp(operand, "float32") == 0)
			CODEGEN("fcmpl\n");
		if(strcmp(op, "EQL") == 0)
			CODEGEN("ifeq L_cmp_%d\n", L_cmp_num);
		else if(strcmp(op, "NEQ") == 0)
            CODEGEN("ifne L_cmp_%d\n", L_cmp_num);
		else if(strcmp(op, "SLR") == 0)
            CODEGEN("iflt L_cmp_%d\n", L_cmp_num);
		else if(strcmp(op, "LEQ") == 0)
            CODEGEN("ifle L_cmp_%d\n", L_cmp_num);
		else if(strcmp(op, "GTR") == 0)
            CODEGEN("ifgt L_cmp_%d\n", L_cmp_num);
		else if(strcmp(op, "GEQ") == 0)
            CODEGEN("ifge L_cmp_%d\n", L_cmp_num);
		CODEGEN("iconst_0\n");
		CODEGEN("goto L_cmp_%d\n", L_cmp_num+1);
		g_indent_cnt--; CODEGEN("L_cmp_%d:\n", L_cmp_num); g_indent_cnt++;
		CODEGEN("iconst_1\n");
		g_indent_cnt--; CODEGEN("L_cmp_%d:\n", ++L_cmp_num); g_indent_cnt++;
		++L_cmp_num;
	}
	else if(strcmp(op, "NOT") == 0){
		CODEGEN("iconst_1\n");
		CODEGEN("ixor\n");
	}
	else if(strcmp(op, "LAND") == 0){
		CODEGEN("iand\n");
	}
	else if(strcmp(op, "LOR") == 0){
		CODEGEN("ior\n");
	}
}




