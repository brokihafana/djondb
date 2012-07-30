grammar filter_expression;

options {
	language = C;
}

@parser::includes {
//#include <stdlib.h>
   #include "filterparser.h"
   #include "filterdefs.h"
   #include "constantexpression.h"
   #include "unaryexpression.h"
   #include "simpleexpression.h"
   #include "binaryexpression.h"
   #include <stdlib.h>
   #include <stdio.h>
   #include <strings.h>
   #include <iostream>
}

@postinclude {
static void displayRecognitionErrorNew  (pANTLR3_BASE_RECOGNIZER recognizer, pANTLR3_UINT8 * tokenNames) throw(ParseException)
{ 
cout << "Override the fucking errors " << endl;
/*
    switch (recognizer->state->exception->type) {
    	case ANTLR3_UNWANTED_TOKEN_EXCEPTION:
		break;
	default:
		throw ParseException(1, (char*)recognizer->state->exception->message);
    }
    */
}
static void reportOverride(pANTLR3_BASE_RECOGNIZER recognizer) {
 cout << "overrideing report" << endl;
}
 }

@parser::apifuncs {
 RECOGNIZER->displayRecognitionError       = displayRecognitionErrorNew;
// RECOGNIZER->reportError = reportOverride;
//  RECOGNIZER->antlr3RecognitionExceptionNew = antlr3RecognitionExceptionNewNew;
//  RECOGNIZER->mismatch                      = mismatchNew;
}

@rulecatch {
   cout << "Nothing" << endl;
}

start_point returns [BaseExpression* val]
        @init{
	} : filter_expr EOF
	{
	    $val = $filter_expr.val;
	};
	
filter_expr returns [BaseExpression* val]
	:
	boolean_expr {
	$val = $boolean_expr.val;
	} ;

boolean_expr returns [BaseExpression* val]
@init {
   BaseExpression* result = NULL;
}
@after {
   $val = result;
}
	:	b1=boolean_term 
	{
	   result = $b1.val;
	}
	(OR b2=boolean_term {
	   BinaryExpression* be = new BinaryExpression(FO_OR);
	   be->push(result);
	   be->push($b2.val);
	   result = be;
	})*;

boolean_term returns [BaseExpression* val]
@init {
   BaseExpression* result = NULL;
}
@after {
   $val = result;
}
	:	b1=boolean_value
	{
	   result = $b1.val;
	}
	 (AND b2=boolean_value
	 {
	   BinaryExpression* be = new BinaryExpression(FO_AND);
	   be->push(result);
	   be->push($b2.val);
	   result = be;
	 })*;
	
boolean_value returns [BaseExpression* val]
	:	parenthesized_boolean {
	   $val = $parenthesized_boolean.val;
	} |
	nonparentherized_boolean{
	   $val = $nonparentherized_boolean.val;
	};	
	
parenthesized_boolean returns [BaseExpression* val]
	: LPAREN boolean_expr {
	   $val = $boolean_expr.val;
	} RPAREN;
	
nonparentherized_boolean returns [BaseExpression* val]
@init {
   BaseExpression* result = NULL;
}
@after {
   $val = result;
}
	: u1=unary_expr {
	   result = $u1.val;
	} ( OPER u2=unary_expr {
	   FILTER_OPERATORS oper = parseFilterOperator((char*)$OPER.text->chars);
	   BinaryExpression* be = new BinaryExpression(oper);
	   be->push(result);
	   be->push($u2.val);
	   result = be;
	})*;


		
unary_expr returns [BaseExpression* val]
	@init {
	     val = NULL;
	}
	: (c1=constant_expr {
	        $val = c1;
	} | x1=xpath_expr {
	        $val = x1;
	});
	
xpath_expr returns [BaseExpression* val]
	: XPATH {
	     char* text = (char*)$XPATH.text->chars;
	     SimpleExpression* result = new SimpleExpression(text);
	     $val = result;
	};

constant_expr returns [BaseExpression* val]
	: (INT
	{
	    int i = atoi((char*)$INT.text->chars);
	    $val = new ConstantExpression(i);
	} | STRING{
	    char* ptext = (char*)$STRING.text->chars;
	    char* text = (char*)malloc(strlen(ptext) - 1);
	    memset(text, 0, strlen(ptext) - 1);
	    memcpy(text, ptext + 1, strlen(ptext) - 2);
	    
	    $val = new ConstantExpression(text);
	    free (text);
	});

operand_expr returns [BaseExpression* val]
	: OPER;
	
NOT	:	'not';

OPER	:	('==' | '>' | '>=' | '<' | '<=' );
OR	:	'or';
AND	:	'and';

INT :	'0'..'9'+;

FLOAT
    :   ('0'..'9')+ '.' ('0'..'9')* EXPONENT?
    |   '.' ('0'..'9')+ EXPONENT?
    |   ('0'..'9')+ EXPONENT
    ;

COMMENT
    :   '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
    |   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
    ;

WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;

STRING 		: 	'\"' ( options{ greedy=false; }: (~('\"') | ('\\"')) )* '\"' | '\'' ( options{ greedy=false; }: (~('\'') | ('\\\'')) )* '\'' ;

DOLLAR 	:	 '$';
XPATH
    : DOLLAR STRING;


fragment
EXPONENT : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

fragment
HEX_DIGIT : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
ESC_SEQ
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    |   UNICODE_ESC
        |   OCTAL_ESC
    ;

fragment
OCTAL_ESC
    :   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7') ('0'..'7')
    |   '\\' ('0'..'7')
    ;

fragment
UNICODE_ESC
    :   '\\' 'u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT
    ;

COMMA
	:	',';
LPAREN :	'(';
RPAREN :	')';
LBRAN :	'{';
RBRAN :	'}';
LBRAK
	:	'[';
RBRAK
	:	']';
COLON
	:	':';
SEMICOLON
        :       ';';

// CHAR:  '\'' ( ESC_SEQ | ~('\''|'\\') ) '\''
//    ;
