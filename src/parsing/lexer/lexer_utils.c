
#include "../../../include/minishell.h"
#include "../../../include/lexer.h"

t_lexnew(char *str, int token)
{
    t_lex   *new_elem;
    static int  i;

    i = 0;
    new_elem = (t_lex *)malloc(sizeof(t_lex));
    if (!new_elem)
        return (0);
    new_elem->str = str;
    new_elem->token = token;
    new_elem->i = i++;
    new_elem-> next = NULL;
    new_elem->prev = NULL;
    return (new_elem);
}

void    ft_lexadd_back(t_lex **lst, t_lex *new)
{
    t_lex *tmp;

    tmp = lst;
    if (*lst == NULL)
    {
        *lst = new;
        return ;
    }
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    new->prev =  tmp;
}


int add_nd(char *str, t_toks token, t_lex **lex_list)
{
    t_lex *node;

    node = ft_lexnew(str, token);
    if (!node)
        return (0);
    ft_lexadd_back(lex_list, node);
    return (1);
}

