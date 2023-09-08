/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:28:19 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/08 17:28:24 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
#include "minishell.h"
//struct lixer...
typedef enum s_toks
{
    PIPE = 1,
    GREAT,
    LESS,
    Double_GREAT,
    Double_LESS,
} t_toks;

typedef struct  s_lex
{
    char    *str;
    t_toks tok;
    int     i;
    struct s_lex *next;
    struct s_lex *prev;
}t_lex;

//function lexer :
int 	check_quotes(char *str, int i, char  fin_range);
t_toks	token_check(int c);
int wrds_reading(char *str, int i, t_lex **lex_list);


// lexer utils_function 
t_lex *ft_lexnew(char *str, int tkn);
void ft_lexadd_back(t_lex **lst, t_lex *new);
int add_nd(char *str, t_toks token, t_lex **lex_list);
int is_space_tab(char c);
int jump_space(char *str, int i);

#endif
