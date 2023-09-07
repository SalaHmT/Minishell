/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 21:08:08 by r4v3n             #+#    #+#             */
/*   Updated: 2023/09/07 21:53:22 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "../../../include/lexer.h"

int 	check_quotes(char *str, int i, char  fin_range)
{
	int	j;
	j = 0;
	if (str[i + j] == fin_range)
	{
		j++;
		while (str[i + j] != fin_range && str[i +j])
			j++;
		j++;
	}
	return (j);
}

t_toks	token_check(int c)
{
	static int	token_list[3][2] = {
		{'|', PIPE},
		{'>', GREAT},
		{'<', LESS},
	};
	int		k;
	k = 0;
	while (k < 3)
	{
		if (token_list[k][0] == c)
			return (token_list[k][1]);
		k++;
	}
	return (0);
}

int token_handling(char *str, int i, t_lex  **lex_list)
{
	t_toks token;

	token = token_check(str[i]);
	if (token == GREAT && check_token (str[i + 1]) == GREAT)
	{
		if (!add_nd(NULL, GREAT_GREAT, lex_list))
			return (-1);
		return (2);
	}
	else if (token == LESS && token_check(str[i + 1]) == LESS)
	{
		if (!add_nd(NULL, LESS_LESS, lex_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_nd(NULL, token, lex_list))
			return (-1);
		return (1);
	}	
	return (0);
}

