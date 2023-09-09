/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:29:52 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/09 14:29:03 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "../../../include/lexer.h"

t_lex	*ft_lexnew(char *str, int tkn)
{
	t_lex		*new_elem;
	static int	i;

	i = 0;
	new_elem = (t_lex *)malloc(sizeof(t_lex));
	if (!new_elem)
		return (0);
	new_elem->str = str;
	new_elem->tok = tkn;
	new_elem->i = i++;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	return (new_elem);
}

void	ft_lexadd_back(t_lex **lst, t_lex *new)
{
	t_lex	*tmpo;

	tmpo = lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmpo->next != NULL)
		tmpo = tmpo->next;
	tmpo->next = new;
	new->prev = tmpo;
}

int	add_nd(char *str, t_toks token, t_lex **lex_list)
{
	t_lex	*nd;

	nd = ft_lexnew(str, token);
	if (!nd)
		return (0);
	ft_lexadd_back(lex_list, nd);
	return (1);
}

int	is_space_tab(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	jump_space(char *str, int i)
{
	int	j;

	j = 0;
	while (is_space_tab(str[i + j]))
		j++;
	return (j);
}
