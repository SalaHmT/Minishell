/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:51:52 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/20 05:37:53 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*ft_strdup(const char *str)
{
	char	*strr;
	size_t	len;

	len = ft_strlen(str);
	strr = (char *)malloc(sizeof(char) * (len + 1));
	if (!strr)
		return (NULL);
	ft_memmove(strr, str, len + 1);
	return (strr);
}
