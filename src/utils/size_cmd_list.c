/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:55:48 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/09 14:14:12 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	lst_size_cmd(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	set_size_arg(char **s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
