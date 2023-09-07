#ifndef LEXER_H
# define LEXER_H
#include "minishell.h"

typedef enum s_toks
{
    PIPE = 1,
    GREAT,
    LESS,
    GREAT_GREAT,
    LESS_LESS,
} t_toks;


typedef struct  s_lex
{
    char    *str;
    t_toks token;
    int     i;
    struct s_lex *next;
    struct s_lex *prev;
}t_lex;

//function lexer :
int 	check_quotes(char *str, int i, char  fin_range);
t_toks	token_check(int c);

// lexer utils_function 

t_lex *ft_lexnew(char *str, int token);
void ft_lexadd_back(t_lex **lst, t_lex *new);




#endif


