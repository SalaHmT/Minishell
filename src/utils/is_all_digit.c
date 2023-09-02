/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:55:52 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/02 13:56:41 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_all_digit(char *s)
{
	int	i;

	i = 0;
	if (*s == '+')
		i++;
	while (*(s + i))
	{
		if (!ft_isdigit(*(s + i)))
			return (0);
		i++;
	}
	return (1);
}
