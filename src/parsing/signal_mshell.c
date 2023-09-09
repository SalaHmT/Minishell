/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_mshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:24:48 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/09 14:39:16 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	search(t_shell *cmd)
{
	search_p_o_p(cmd); 
}

void	sig_ctlc(int input_sig)
{
	if (input_sig == SIGINT)
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		rl_replace_line("", STDIN_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
}
