/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : /home/cross/workspace/djondb_tx/db/grammars/filter_expression.g
 *     -                            On : 2013-05-29 19:53:06
 *     -                 for the lexer : filter_expressionLexerLexer
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The lexer 
filter_expressionLexer

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pfilter_expressionLexer, which is returned from a call to filter_expressionLexerNew().
 *
 * As this is a generated lexer, it is unlikely you will call it 'manually'. However
 * the methods are provided anyway.
 *
 * The methods in pfilter_expressionLexer are  as follows:
 *
 *  - 
 void
      pfilter_expressionLexer->NOT(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->TRUE(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->FALSE(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->OPER(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->OR(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->AND(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->EXISTS(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->NUMBER(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->FLOAT(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->COMMENT(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->WS(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->STRING(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->DOLLAR(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->XPATH(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->EXPONENT(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->HEX_DIGIT(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->ESC_SEQ(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->OCTAL_ESC(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->UNICODE_ESC(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->COMMA(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->LPAREN(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->RPAREN(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->LBRAN(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->RBRAN(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->LBRAK(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->RBRAK(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->COLON(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->SEMICOLON(pfilter_expressionLexer)
 *  - 
 void
      pfilter_expressionLexer->Tokens(pfilter_expressionLexer)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_filter_expressionLexer_H
#define _filter_expressionLexer_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct filter_expressionLexer_Ctx_struct filter_expressionLexer, * pfilter_expressionLexer;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/** Context tracking structure for 
filter_expressionLexer

 */
struct filter_expressionLexer_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_LEXER    pLexer;

     void
     (*mNOT)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mTRUE)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mFALSE)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mOPER)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mOR)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mAND)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mEXISTS)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mNUMBER)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mFLOAT)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mCOMMENT)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mWS)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mSTRING)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mDOLLAR)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mXPATH)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mEXPONENT)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mHEX_DIGIT)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mESC_SEQ)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mOCTAL_ESC)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mUNICODE_ESC)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mCOMMA)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mLPAREN)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mRPAREN)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mLBRAN)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mRBRAN)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mLBRAK)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mRBRAK)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mCOLON)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mSEMICOLON)	(struct filter_expressionLexer_Ctx_struct * ctx);

     void
     (*mTokens)	(struct filter_expressionLexer_Ctx_struct * ctx);
    const char * (*getGrammarFileName)();
    void            (*reset)  (struct filter_expressionLexer_Ctx_struct * ctx);
    void	    (*free)   (struct filter_expressionLexer_Ctx_struct * ctx);
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pfilter_expressionLexer filter_expressionLexerNew         (
pANTLR3_INPUT_STREAM
 instream);
ANTLR3_API pfilter_expressionLexer filter_expressionLexerNewSSD      (
pANTLR3_INPUT_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
lexer
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define AND      4
#define COLON      5
#define COMMA      6
#define COMMENT      7
#define DOLLAR      8
#define ESC_SEQ      9
#define EXISTS      10
#define EXPONENT      11
#define FALSE      12
#define FLOAT      13
#define HEX_DIGIT      14
#define LBRAK      15
#define LBRAN      16
#define LPAREN      17
#define NOT      18
#define NUMBER      19
#define OCTAL_ESC      20
#define OPER      21
#define OR      22
#define RBRAK      23
#define RBRAN      24
#define RPAREN      25
#define SEMICOLON      26
#define STRING      27
#define TRUE      28
#define UNICODE_ESC      29
#define WS      30
#define XPATH      31
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for filter_expressionLexer
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
