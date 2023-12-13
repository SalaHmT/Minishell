/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_data_check_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:21:50 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/13 20:24:17 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_a_directory(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	check_cmd_isdretory(char *str)
{
	DIR		*dir;

	if (str && is_a_directory(str))
	{
		if (!str)
		{
			(ft_putstr("bashn't: ", 2), ft_putstr(str, 2));
			ft_putstr(" :is a directory\n", 2);
			return (g_lb_data.ext_status = CMD_EXE_FAILED, 1);
		}
		else
		{
			dir = opendir(str);
			if (dir)
			{
				(ft_putstr("bashn't: ", 2), ft_putstr(str, 2));
				ft_putstr(" :is a directory\n", 2);
				if (dir)
					closedir(dir);
				return (g_lb_data.ext_status = CMD_EXE_FAILED, 1);
			}
		}
	}
	return (0);
}
