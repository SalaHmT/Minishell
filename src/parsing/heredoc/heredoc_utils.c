/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 01:19:33 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/21 04:49:51 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*generate_name_tmpfile(void)
{
	int		i;
	char	*nbr;
	char	*herdoc_namme;

	i = 0;
	nbr = ft_strjoin("/tmp/hd_", nbr);
	free (nbr);
	while (!access(herdoc_namme, F_OK))
	{
		free(herdoc_namme);
		nbr = ft_itoa(i++);
		herdoc_namme = ft_strjoin("/tmp/hd_", nbr);
		free(nbr);
	}
	return (herdoc_namme);
}

void	heredoc_signal(int sig, t_context	*ptr)
{
	static t_context	*context;

	if (sig == -200)
		context = ptr;
	if (sig == SIGINT)
	{
		g_ext_status = 1;
		context->data->sigflg = 1;
		context->data->sig = 1;
		rl_replace_line("", 0);
		printf("\n");
		close(0);
	}
}

t_context	*initialize_context(void)
{
	t_context	*context;

	context = malloc(sizeof(t_context));
	if (!context)
		return (NULL);
	context->data = malloc(sizeof(t_data));
	if (!context->data)
		return (NULL);
	return (context);
}
