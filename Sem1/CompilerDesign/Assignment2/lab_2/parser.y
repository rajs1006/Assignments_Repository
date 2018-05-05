/* Sourabh Raj 397371 */

/* Types that are used in %union should be defined in this code block. */
%code requires {
#include <stdbool.h>
}

/* Everything else can go in this code block. */
%code {
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int line_number;
extern FILE *yyin;
extern int yylex();
static void checkStateMethod(char *methodName, char *stateName, int stateOrder);
static void checkStateVariable(char *stateVarName, char *stateName, int stateOrder);
static void yyerror(const char *s);

char *identName;
char *funcName;
char *typeName;
char *stateVarName;
char *stateName;
int stateOrder;
}

/* Enable verbose error messages. */
%define parse.error verbose

/* Declare type for semantic value. You may need to extend this. */
%union {
    bool bval;
    int ival;
    double fval;
    char *str;
};

/* Declare tokens with semantic values */
%token<bval> BOOL
%token<ival> INT
%token<fval> FLOAT
%token<str> TYPE STATE IDENTIFIER ERROR

/* Declare tokens without semantic values */
%token BREAK CONTINUE DO FOR WHILE SWITCH CASE DEFAULT IF ELSE RETURN STRUCT
%token ATTRIBUTE CONST UNIFORM VARYING BUFFER SHARED COHERENT VOLATILE RESTRICT
%token READONLY WRITEONLY LAYOUT CENTROID FLAT SMOOTH NOPERSPECTIVE PATCH SAMPLE
%token SUBROUTINE IN OUT INOUT INVARIANT PRECISE DISCARD LOWP MEDIUMP HIGHP PRECISION

%token CLASS ILLUMINANCE AMBIENT PUBLIC PRIVATE SCRATCH
%token RT_PRIMITIVE RT_CAMERA RT_MATERIAL RT_TEXTURE RT_LIGHT

%token LEFT_OP RIGHT_OP INC_OP DEC_OP LE_OP GE_OP EQ_OP NE_OP AND_OP OR_OP XOR_OP

%token MUL_ASSIGN DIV_ASSIGN ADD_ASSIGN MOD_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN
%token AND_ASSIGN XOR_ASSIGN OR_ASSIGN SUB_ASSIGN

/* You can specify the type for a production using %type.
 * For example, if "function_header" should have a "str" value, use:
 * %type<str> function_header
 */

/* Start production. */
%type<str> variable_identifier

%start class_identifier

%%
class_identifier
	: state_definition translation_unit 
	| state_definition	
	;

state_variable
	: RT_PRIMITIVE { stateName = "primitive";stateOrder=0; printf ( "of type RT_PRIMITIVE \n ");}
    | RT_CAMERA { stateName = "camera";stateOrder=1; printf ( "of type RT_CAMERA \n ");}
	| RT_MATERIAL  { stateName = "material"; stateOrder=2; printf ( "of type RT_MATERIAL \n ");}
    | RT_TEXTURE  { stateName = "texture";stateOrder=3; printf ( "of type RT_TEXTURE \n ");}
	| RT_LIGHT  { stateName = "light"; stateOrder=4; printf ( "of type RT_LIGHT \n ");}
	;

state_definition
	: CLASS { printf ( " CLASS ");} variable_identifier {printf ( "%s ", identName);} ':' state_variable ';'
	;
	
variable_identifier
    : IDENTIFIER {identName = $1; } 
    ;
	
state_var_identifier
    : STATE {
				stateVarName = $1; 
				checkStateVariable(stateVarName, stateName, stateOrder);
			} 
    ;

primary_expression
    : variable_identifier
	| state_var_identifier
    | INT
    | FLOAT
    | BOOL
	| '(' expression ')' 
    ;
	 
postfix_expression
    : primary_expression 
    | postfix_expression '(' expression ')' 
    | function_call 
	| postfix_expression '.' IDENTIFIER  
    | postfix_expression INC_OP 
    | postfix_expression DEC_OP 
	;
	
function_call
    : function_call_or_method
	;

function_call_or_method
    : function_call_generic 
	;

function_call_generic
    : function_call_header_with_parameters ')' 
    | function_call_header_no_parameters ')' 
	;

function_call_header_no_parameters
    : function_call_header 
	;

function_call_header_with_parameters
    : function_call_header assignment_expression 
    | function_call_header_with_parameters ',' assignment_expression 
	;
	
function_call_header
    : function_identifier '('
	;
	
function_identifier
    : type_specifier
    //| postfix_expression
	;
	
unary_expression
    : postfix_expression 
    | INC_OP unary_expression 
    | DEC_OP unary_expression 
    | unary_operator unary_expression 
	;

unary_operator
    : '+'
    | '-'
    | '!'
    | '~'
	;

multiplicative_expression
    : unary_expression 
    | multiplicative_expression '*' unary_expression 
    | multiplicative_expression '/' unary_expression
    | multiplicative_expression '%' unary_expression

	;

additive_expression
    : multiplicative_expression 
    | additive_expression '+' multiplicative_expression 
    | additive_expression '-' multiplicative_expression 
	;

shift_expression
    : additive_expression 
    | shift_expression LEFT_OP additive_expression
    | shift_expression RIGHT_OP additive_expression
	;

relational_expression
    : shift_expression 
    | relational_expression '<' shift_expression 
    | relational_expression '>' shift_expression 
    | relational_expression LE_OP shift_expression 
    | relational_expression GE_OP shift_expression 
	;

equality_expression
    : relational_expression 
    | equality_expression EQ_OP relational_expression 
    | equality_expression NE_OP relational_expression 
	;

and_expression
    : equality_expression 
    | and_expression '&' equality_expression
	;

exclusive_or_expression
    : and_expression 
    | exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
    : exclusive_or_expression 
    | inclusive_or_expression '|'  exclusive_or_expression
	;

logical_and_expression
    : inclusive_or_expression 
    | logical_and_expression AND_OP inclusive_or_expression 
	;

logical_xor_expression
    : logical_and_expression 
    | logical_xor_expression XOR_OP logical_and_expression 
	;

logical_or_expression
    : logical_xor_expression 
    | logical_or_expression OR_OP logical_xor_expression 
	;

conditional_expression
    : logical_or_expression 
    | logical_or_expression '?' expression ':' assignment_expression 
	;

assignment_expression
    : conditional_expression 
    | unary_expression assignment_operator assignment_expression
	//| STATE
	;

assignment_operator
    : '='
    | MUL_ASSIGN 
    | DIV_ASSIGN 
    | MOD_ASSIGN 
    | ADD_ASSIGN 
    | SUB_ASSIGN 
    | LEFT_ASSIGN 
    | RIGHT_ASSIGN 
    | AND_ASSIGN 
    | XOR_ASSIGN 
    | OR_ASSIGN
    ;

expression
    : assignment_expression 
    | expression ',' assignment_expression 
	;

constant_expression
    : conditional_expression 
	;

declaration
    : function_prototype '{' expression '}'
    | init_declarator_list ';' 
    | PRECISION PRECISION type_specifier ';' 
    | type_qualifier IDENTIFIER '{' struct_declaration_list '}' ';' 
    | type_qualifier IDENTIFIER '{' struct_declaration_list '}' IDENTIFIER ';'
    | type_qualifier IDENTIFIER '{' struct_declaration_list '}' IDENTIFIER array_specifier ';'
    | type_qualifier ';' 
    | type_qualifier IDENTIFIER ';'
    | type_qualifier IDENTIFIER identifier_list ';'

	;

identifier_list
    : ',' IDENTIFIER
    | identifier_list ',' IDENTIFIER 
	;

function_prototype
    : function_declarator
	;

function_declarator
    : function_header
    | function_header_with_parameters 
	| function_header_with_no_parameters
	;

function_header_with_parameters
    : function_header parameter_declaration 
    | function_header_with_parameters parameter_declaration 
	;

function_header_with_no_parameters
    : function_header ')'
	;
	
function_header
    : fully_specified_type variable_identifier {funcName = identName; } '(' 
	;

parameter_declarator
    : type_specifier IDENTIFIER ')'
	| type_specifier IDENTIFIER ','
    | type_specifier IDENTIFIER array_specifier ')'
	| type_specifier IDENTIFIER array_specifier ','
	;

parameter_declaration
    :  type_qualifier parameter_declarator 
    |  parameter_declarator 
    |  type_qualifier parameter_type_specifier 
    |  parameter_type_specifier 
	;

parameter_type_specifier
    : type_specifier 
	;

init_declarator_list
    : single_declaration 
    | init_declarator_list ',' IDENTIFIER
    | init_declarator_list ',' IDENTIFIER array_specifier
    | init_declarator_list ',' IDENTIFIER array_specifier '=' initializer 
    | init_declarator_list ',' IDENTIFIER '=' initializer 
	;

single_declaration
    : fully_specified_type 
    | fully_specified_type variable_identifier {printf ("DECLARATION %s of type %s \n ", identName, typeName);}
    | fully_specified_type IDENTIFIER array_specifier
    | fully_specified_type IDENTIFIER array_specifier '=' initializer
    | fully_specified_type variable_identifier {printf ("DECLARATION %s of type %s with initializer \n ", identName, typeName);} '=' initializer
	;

fully_specified_type
    : type_specifier
    | type_qualifier type_specifier 
	;

invariant_qualifier
    : INVARIANT
	;

interpolation_qualifier
    : SMOOTH 
    | FLAT 
	;

layout_qualifier
    : LAYOUT '(' layout_qualifier_id_list ')'
	;

layout_qualifier_id_list
    : layout_qualifier_id
    | layout_qualifier_id_list ',' layout_qualifier_id
	;

layout_qualifier_id
    : IDENTIFIER
IDENTIFIER '=' constant_expression
    | SHARED
	;

precise_qualifier
    : PRECISE
	;

type_qualifier
    : single_type_qualifier
    | type_qualifier single_type_qualifier
	;
	
single_type_qualifier
    : storage_qualifier
    | layout_qualifier
    //| precision_qualifier
    | interpolation_qualifier
    | invariant_qualifier
    | precise_qualifier
	| access_modifiers
	;

storage_qualifier
    : CONST 
    | INOUT 
    | IN 
    | OUT 
    | CENTROID 
    | PATCH 
    | SAMPLE 
    | UNIFORM
    | BUFFER
    | SHARED
    | COHERENT
    | VOLATILE
    | RESTRICT
    | READONLY
    | WRITEONLY
    | SUBROUTINE
    | SUBROUTINE '(' type_name_list ')' 
    ;

type_name_list
    : type_identifier 
    | type_name_list ',' type_identifier
	;

type_specifier
    : type_specifier_nonarray 
    | type_specifier_nonarray array_specifier
	;

array_specifier
    : '[' ']'
    | '[' constant_expression ']'
    | array_specifier '[' ']'
    | array_specifier '[' constant_expression ']'
	;

type_identifier
	: TYPE {typeName = $1; }
	
type_specifier_nonarray
    : struct_specifier
    | type_identifier
	;

access_modifiers
	: PUBLIC
	| PRIVATE
	


struct_specifier
    : STRUCT IDENTIFIER '{' struct_declaration_list '}' 
    | STRUCT '{' struct_declaration_list '}' 
	;

struct_declaration_list
    : struct_declaration 
    | struct_declaration_list struct_declaration 
	;

struct_declaration
    : type_specifier struct_declarator_list ';' 
    | type_qualifier type_specifier struct_declarator_list ';'
	;

struct_declarator_list
    : struct_declarator 
    | struct_declarator_list ',' struct_declarator 
	;

struct_declarator
    : IDENTIFIER 
    | IDENTIFIER array_specifier
	;
	
initializer
    : assignment_expression 
    | '{' initializer_list '}'
    | '{' initializer_list ',' '}'
	;

initializer_list
    : initializer
    | initializer_list ',' initializer
	;

declaration_statement
    : declaration 
	;

statement
    : compound_statement 
    | simple_statement 
	;

simple_statement
    : declaration_statement 
    | expression_statement 
    | selection_statement
    | switch_statement 
    | case_label
    | iteration_statement 
    | jump_statement 
	;

compound_statement
    : '{' '}' 
    | '{' statement_list '}' { printf ( "COMPOUND_STATEMENT \n ");}
	;

statement_no_new_scope
    : compound_statement 
    | simple_statement 
	;

compound_statement_no_new_scope
    : '{' '}'
    | '{' statement_list '}'
	;

statement_list
    : statement 
    | statement_list statement 
	;
	
expression_statement
    : ';' 
    | expression ';' { printf ( "EXPRESSION_STATEMENT \n ");}
	;

selection_statement
    : IF '(' expression ')' selection_rest_statement 
	;

selection_rest_statement
    : statement { printf ( "IF_STATEMENT \n ");}
	| statement ELSE statement  { printf ( "IF_ELSE_STATEMENT \n ");}
	;

condition
    : expression 
    | fully_specified_type IDENTIFIER '=' initializer 
	;

switch_statement
    : SWITCH '(' expression ')' '{' switch_statement_list '}'
	;

switch_statement_list
    : /* nothing */
    | statement_list
	;

case_label
    : CASE expression ':'
    | DEFAULT ':'
	;

iteration_statement
    : WHILE '(' condition ')' statement_no_new_scope { printf ( "WHILE_STATEMENT \n ");}
    | DO statement WHILE '(' expression ')' ';' { printf ( "DO_WHILE_STATEMENT \n ");}
    | FOR '(' for_init_statement for_rest_statement ')' statement_no_new_scope { printf ( "FOR_STATEMENT \n ");} 
    ;

for_init_statement
    : expression_statement 
    | declaration_statement 
	;

conditionopt
    : condition 
    | /* empty */
	;

for_rest_statement
    : conditionopt ';' 
    | conditionopt ';' expression 
	;

jump_statement
    : CONTINUE ';' { printf ( "CONTINUE \n ");}
    | BREAK ';' { printf ( "BREAK \n ");}
    | RETURN ';' { printf ( "RETURN_STATEMENT \n ");}
    | RETURN { printf ( "RETURN_STATEMENT \n ");} expression ';' 
    | DISCARD ';'  { printf ( "DISCARD \n ");}
	;

translation_unit
    : external_declaration 
    | translation_unit external_declaration 
	;

external_declaration
    : function_definition
    | declaration 
	;

function_definition
    : function_prototype compound_statement_no_new_scope
		{ 
			printf ( "FUNCTION_DEF %s \n ", funcName); 
			checkStateMethod(funcName, stateName, stateOrder);
		}
	;
	
%%
/* DaRT_LIGHT;ta tables for interface methods and states, so you don't have to extract them yourself.
 * Note: The paper contains a number of errors regarding the allowed state variables. These
 * errors are already corrected here and marked with a comment. */

static const char *camera_methods[] = {
    "constructor",
    "generateRay",
    NULL
};

static const char *primitive_methods[] = {
    "constructor",
    "intersect",
    "computeBounds",
    "computeNormal",
    "computeTextureCoordinates",
    "computeDerivatives",
    "generateSample",
    "samplePDF",
    NULL
};

static const char *texture_methods[] = {
    "constructor",
    "lookup",
    NULL
};

static const char *material_methods[] = {
    "constructor",
    "shade",
    "BSDF",
    "sampleBSDF",
    "evaluatePDF",
    "emission",
    NULL
};

static const char *light_methods[] = {
    "constructor",
    "illumination",
    NULL
};

static const char **interface_methods[] = {
    primitive_methods, camera_methods, material_methods, texture_methods, light_methods, NULL
};

static const char *camera_states[] = {
    "RayOrigin",
    "RayDirection",
    "InverseRayDirection",
    "Epsilon",
    "HitDistance",
    "ScreenCoord",
    "LensCoord",
    "du",
    "dv",
    "TimeSeed",
    NULL 
};

static const char *primitive_states[] = {
    "RayOrigin",
    "RayDirection",
    "InverseRayDirection",
    "Epsilon",
    "HitDistance",
    "BoundMin",
    "BoundMax",
    "GeometricNormal",
    "dPdu",
    "dPdv",
    "ShadingNormal",
    "TextureUV",
    "TextureUVW",
    "dsdu",
    "dsdv",
    "PDF",
    "TimeSeed",
    "HitPoint", // missing in paper
    NULL
};

static const char *texture_states[] = {
    "TextureUV",
    "TextureUVW",
    "TextureColor",
    "FloatTextureValue",
    "du",
    "dv",
    "dsdu",
    "dtdu",
    "dsdv",
    "dtdv",
    "dPdu",
    "dPdv",
    "TimeSeed",
    NULL
};

static const char *material_states[] = {
    "RayOrigin",
    "RayDirection",
    "InverseRayDirection",
    "HitPoint",
    "dPdu",
    "dPdv",
    "LightDirection",
    "LightDistance",
    "LightColor",
    "EmissionColor",
    "BSDFSeed",
    "TimeSeed",
    "PDF",
    "SampleColor",
    "BSDFValue",
    "du",
    "dv",
    "ShadingNormal", // missing in paper
    "HitDistance", // missing in paper
    NULL
};

static const char *light_states[] = {
    "HitPoint",
    "GeometricNormal",
    "ShadingNormal",
    "LightDirection",
    "TimeSeed",
    NULL
};

static const char **interface_states[] = {
    primitive_states, camera_states, material_states, texture_states, light_states
};

/* additional functions to implement the semantic checks here. */
 
static void checkStateMethod(char *methodName, char *stateName, int stateOrder){ 
	int i;
	bool isMethodAvailable = false;
	bool isMethodMatched = false;
	for(i=0; i < sizeof(interface_methods)/sizeof(interface_methods[0]) - 1; i++){
		int j = 0;
		while(((interface_methods)[i])[j] != NULL){
			const char *method = ((interface_methods)[i])[j++];
			if( strcmp(method, methodName) == 0) {
				isMethodAvailable = true;
				if(i == stateOrder){
					isMethodMatched = true;
					break;
				}
			}
		}
		if(isMethodMatched){
			break;
		}
	}
	if(isMethodAvailable && !isMethodMatched ){
		fprintf(stderr,"Interface method %s() not allowed in %s \n", methodName, stateName);
	}
}

static void checkStateVariable(char *stateVarName, char *stateName, int stateOrder){ 
	int i;
	bool isVarAvailable = false;
	bool isVarMatched = false;
	// Split STATE Var.
	char *token = strtok(stateVarName,"_");
	while( token != NULL ) {
	  stateVarName = token;
	  token = strtok(NULL,"_");
    } 
	for(i=0; i < sizeof(interface_states)/sizeof(interface_states[0]) - 1; i++){
		int j = 0;
		while(((interface_states)[i])[j] != NULL){
			const char *var = ((interface_states)[i])[j++];
			if( strcmp(var, strtok(stateVarName,"_")) == 0){ 
				isVarAvailable = true; 
				if(i == stateOrder){
					isVarMatched = true;
					break;
				}
			}
		}
		if(isVarMatched){
			break;
		}
	}
	if(isVarAvailable && !isVarMatched){
		fprintf(stderr,"State variable %s not allowed in %s \n", stateVarName, stateName);
	}
}
 
static void yyerror(const char *s) {
    fprintf(stderr, "%s on line %d\n", s, line_number);
    exit(-1);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("File %s not found.\n", argv[1]);
            return 1;
        }
    } else {
        yyin = stdin;
    }
    
    do {
        yyparse();
    } while (!feof(yyin));
    return 1;
}
