/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:30:04 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/09 14:33:28 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "../../../include/lexer.h"

int	check_quotes(char *str, int i, char fin_range)
{
	int	j;

	j = 0;
	if (str[i + j] == fin_range)
	{
		j++;
		while (str[i + j] != fin_range && str[i + j])
			j++;
		j++;
	}
	return (j);
}

t_toks	token_check(int c)
{
	int			k;
	static int	tok_list[3][2] = {
		{'|', PIPE},
		{'>', GREAT},
		{'<', LESS},
	};

	k = -1;
	while (++k < 3)
	{
		if (tok_list[k][0] == c)
			return (tok_list[k][1]);
	}
	return (0);
}

int	token_handling(char *str, int i, t_lex **lex_list)
{
	t_toks	tkn;

	tkn = token_check(str[i]);
	if (tkn == GREAT && check_token (str[i + 1]) == GREAT)
	{
		if (!add_nd(NULL, Double_GREAT, lex_list))
			return (-1);
		return (2);
	}
	else if (tkn == LESS && token_check(str[i + 1]) == LESS)
	{
		if (!add_nd(NULL, Double_LESS, lex_list))
			return (-1);
		return (2);
	}
	else if (tkn)
	{
		if (!add_nd(NULL, tkn, lex_list))
			return (-1);
		return (1);
	}
	return (0);
}
