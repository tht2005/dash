/**
 * @file
 * @brief Dash shell interpreter
 *
 *      Command grammar:
 *          $VAR or ${VAR}: value of VAR in environment
 *          $(( arithmetic expression )) 
 *          
 *          if [[ expression ]]; then
 */

#ifndef __INTERPRETER_H
#define __INTERPRETER_H

#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "cpp_string.h"

// debug
#include <stdio.h>

typedef
enum token_type
{
    COMMAND,

    //FILE,

    AND,            // &
    OR,             // |

    DOUBLE_AND,     // &&
    DOUBLE_OR,      // ||

    OPEN_BRACKET_LEFT, // (
    OPEN_BRACKET_RIGHT, // )

    // SQUARE_BRACKET_LEFT, // [
    // SQUARE_BRACKET_RIGHT, // ]

    PARENTHESIS_LEFT, // {
    PARENTHESIS_RIGHT, // }

    EXPRESSION_BEGIN, // [[
    EXPRESSION_END, // ]]

    // DOUBLE_PARENTHESIS_LEFT, // {{
    // DOUBLE_PARENTHESIS_RIGHT, // }}
    
    SUBSTITUTION_BEGIN, // ${
    // SUBSTITUTION_END = PARENTHESIS_RIGHT,   // }
                        //
    COMMAND_BEGIN, // $(
    // COMMAND_END = OPEN_BRACKET_RIGHT, // )

    ARITHMETIC_BEGIN, // $((
    ARITHMETIC_END, // ))

    // DOLLAR_SIGN, // $
    // NUMBER_SIGN, // #

    PERCENT, // %
    
    LESS, // <
    GREATER, // >
    
    DOT, // .
    COLON, // :
    SEMICOLON, // ;

    BASHSLASH, // \
    
    SINGLE_QUOTE, // '
    DOUBLE_QUOTE, // "

    IF, // if
    ELSE, // else
    ENDIF, // endif
    FOR, // for
    WHILE, // while
    DO, // do

    ENDFILE,

    UNDEFINED,

}
token_type;

typedef enum token_type_duplicate
{
    COMMAND_END = OPEN_BRACKET_RIGHT, // )
    SUBSTITUTION_END = PARENTHESIS_RIGHT,   // }
}
token_type_duplicate;

typedef
struct token
{
    token_type type;
    char *str;
}
token;

void
init_interpreter (char *command);

token
next_token ();

#endif
