/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:31:32 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/13 11:56:37 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*if_contain_env_var(char *str)
{
	t_list	*ptr;
	int		len;
	char	*copy;

	ptr = g_lb_data.env;
	len = ft_strlen(str);
	while (ptr && str[0])
	{
		copy = ptr->content;
		if (copy[len] && !ft_strncmp(copy, str, len)
			&& copy[len] == '=' && copy[len + 1])
			return (ft_strdup(copy + len + 1));
		ptr = ptr->next;
	}
	return (ft_strdup(""));
}
// function extracts a variable name
// from the input string, searches for its
//  value using the <if_contain_env_var> function,
//   and returns the value. It handles cases
//   where the variable is not in quotes and is
//   followed by alphanumeric characters or underscores.

char	*extract_value_checkname(char *val, int	*idx)
{
	char	*ptr;
	char	*str;
	int		i;

	str = ft_strdup("");
	i = *idx;
	if (!check_quotes(val, i + 2) && !ft_isalnum(val[i + 1])
		&& val[i + 1] != '?' && val[i + 1] != '-')
	{
		while (val[i] && val[i] != '$')
			str = ft_joinchar(str, val[i++]);
	}
	while (val[++i] && (ft_isalnum(val[i]) || val[i] == '-'))
		str = ft_joinchar(str, val[i]);
	i--;
	*idx = i;
	ptr = if_contain_env_var(str);
	free(str);
	return (ptr);
}

void	get_val_concat(char	*val, int *i, char **str, int *flg)
{
	char	*tmp;

	*flg = 1;
	if (val[*i + 1] == '?')
	{
		(*i)++;
		tmp = ft_itoa(g_lb_data.ext_status);
	}
	else
		tmp = extract_value_checkname(val, i);
	*str = ft_strjoin(*str, tmp);
	free (tmp);
}
