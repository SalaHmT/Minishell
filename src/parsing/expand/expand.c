/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:11:27 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/13 12:28:49 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
// function processes each character in the value array, expanding 
// variables and characters based on specific conditions, and finally
//  returns the expanded string after freeing the original value.
char	expand_var_char(char *val)
{
	char	*str;
	int		i;
	int		flg;

	flg = 0;
	i = 0;
	str = ft_strdup("");
	while (val[i])
	{
		if (val[i] == '$' && is_val_char(val[i + 1])
			&& (check_quotes(val, i) == 0 || check_quotes(val, i) == 1))
		{
			if (val[i + 1] != '$' && !ft_isdigit(val[i + 1]))
				get_val_concat(val, &i, &str, &flg);
			else
				append_char_str(val, &str, i);
			i++;
		}
		return (free(val), str);
	}
}
