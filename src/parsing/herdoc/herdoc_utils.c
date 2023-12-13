/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:52:45 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/13 20:18:04 by shamsate         ###   ########.fr       */
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

void	heredoc_signal(int sig)
{
	if (sig == SIGINT)
	{
		g_lb_data.ext_status = 1;
		g_lb_data.sigflg = 1;
		g_lb_data.sig = 1;
		rl_replace_line("", 0);
		printf("\n");
		close(0);
	}
}
