#include "interpreter.h"

token new_token (token_type type, char *str)
{
    token ret;
    ret.type = type;
    ret.str = str;
    return ret;
}

int ptr;
int len;
char *str;

void skip_space ()
{
    while (ptr < len && isspace(str[ptr])) {
        ++ptr;
    }
}

void init_interpreter(char *command)
{
    str = command;
    ptr = 0;
    len = strlen (str);
}

void backward ()
{
    --ptr;
}

char next_char ()
{
    if (ptr >= len)
        return 0;
    return str[ptr ++];
}

// &
token case_and ()
{
    token tk = new_token (UNDEFINED, "UNDEFINED");

    switch (next_char())
    {
        case '&':
            tk = new_token (DOUBLE_AND, "DOUBLE_AND");
            break;

        default:
            tk = new_token (AND, "AND");
            backward ();
            break;
    }

    return tk;
}

// |
token case_or ()
{
    token tk = new_token (UNDEFINED, "UNDEFINED");

    switch (next_char ())
    {
        case '|':
            tk = new_token (DOUBLE_OR, "DOUBLE_OR");
            break;
        
        default:
            tk = new_token (OR, "OR");
            backward ();
            break;
    }

    return tk;
}

// $
token case_dollar ()
{
    token tk = new_token (UNDEFINED, "UNDEFINED");

    switch (next_char ())
    {
        case '(':

            switch (next_char ())
            {
                case '(':
                    tk = new_token (ARITHMETIC_BEGIN, "ARITHMETIC_BEGIN");
                    break;
                default:
                    tk = new_token (COMMAND_BEGIN, "COMMAND_BEGIN");
                    backward ();
                    break;
            }

            break;

        case '{':
            tk = new_token (SUBSTITUTION_BEGIN, "SUBSTITUTION_BEGIN");
            break;

        default:
            break;
    }

    return tk;
}

// (
token case_open_bracket ()
{
    token tk = new_token (UNDEFINED, "UNDEFINED");

    switch (next_char ())
    {
        default:
            tk = new_token (OPEN_BRACKET_LEFT, "OPEN_BRACKET_LEFT");
            break;
    }

    return tk;
}

// )
token case_close_bracket ()
{
    token tk = new_token (UNDEFINED, "UNDEFINED");

    switch (next_char ())
    {
        default:
            tk = new_token (OPEN_BRACKET_RIGHT, "OPEN_BRACKET_RIGHT");
            break;
    }

    return tk;
}

token case_single_quote ()
{

}

token next_token ()
{
    skip_space ();

    char c = next_char ();

    if (c == '&')
        return case_and ();
    else if (c == '|')
        return case_or ();
    else if (c == '(')
        return case_open_bracket();
    else if (c == ')')
        return case_close_bracket();
    else if (c == '$')
        return case_dollar ();
    else if (c == '\'')
        return case_single_quote ();
    else if (c == 0)
        return new_token (ENDFILE, "ENDFILE");

    return new_token (ENDFILE, "not covered");
}

