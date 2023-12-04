/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:47:51 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/04 23:11:47 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_quotes_exist(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (0);
		i++;
	}
	return (1);
}

//  It iterates through the string and counts the number of sequences of
// non-space characters separated by spaces or tabs.
int	cont_no_wspace(char *str)
{
	int	i;
	int	x;
	int	flg;

	i = 0;
	x = 0;
	flg = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i] != '\t' && str[i] != ' ') && flg == 0)
		{
			x++;
			flg = 1;
		}
		if ((str[i] == '\t' || str[i] == ' '))
			flg = 0;
		i++;
	}
	return (x);
}
