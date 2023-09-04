/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:48:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/04 19:57:59 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**ft_comdup(char **str)
{
	char	**s;
	int	    len;
    int     i;

	len = set_size_arg(str);
	s = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!s)
		return (NULL);
	i = 0;
	while (i < len)
    {
        s[i] = ft_strdup(str[i]);
        if (s[i] == NULL)
        {
            freesplit(s, 0); // Free the allocated memory up to this point
            return (NULL);
        }
        i++;
    }
    s[i] = NULL;
	return (s);
}
