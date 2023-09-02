/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:03:42 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/02 14:15:33 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

long long	ft_atoi_exit(const char *s)
{
	long long int	n;
	int			            sign;

	n = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= (-1);
		s++;
	}
	while (*s && *s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s++ - '0');
		if (n * sign > INT_X)
			return (-1);
		else if (n * sign < INT_N)
			return (-1);
	}
	return (n * sign);
}
