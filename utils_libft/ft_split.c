/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:17:55 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/15 18:20:09 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	free_strings_and_array(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

static int	count_substrings(const char *str, char delimiter)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != delimiter)
		{
			count++;
			while (str[i] != '\0' && str[i] != delimiter)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	substring_length(const char *str, char delimiter)
{
	int	length;

	length = 0;
	while (str[length] != '\0' && str[length] != delimiter)
		length++;
	return (length);
}

static char	**fill_substrs(char **substrings, const char *str, char delimiter)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && str[i] == delimiter)
			i++;
		if (str[i])
		{
			substrings[j] = malloc(sizeof(char) * (ft_count2((char *)str + i, \
				delimiter) + 1));
			if (!substrings[j])
				return (ft_fre(substrings, j));
			while (str[i] && str[i] != delimiter)
				substrings[j][k++] = str[i++];
			substrings[j++][k] = 0;
			k = 0;
		}
	}
	substrings[j] = 0;
	return (substrings);
}

char	**ft_split(const char *str, char delimiter)
{
	int		substrings_count;
	char	**substrings;

	if (str == NULL)
		return (NULL);
	substrings_count = count_substrings(str, delimiter);
	substrings = (char **)malloc(sizeof(char *) * (substrings_count + 1));
	if (substrings == NULL)
		return (NULL);
	return (fill_substrings(substrings, str, delimiter));
}
