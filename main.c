/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/17 02:33:23 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// this code is a signal handler specifically designed to handle
//  the SIGINT signal, commonly used to handle Ctrl+C interrupts
//   in a terminal-based program. It updates some internal
//    state (g_lb__data.exit_status) and performs some actions to clear
//     the input line and refresh the display to provide a smooth user
// 	 experience when the program is interrupted.
void	handle_signal_ctrl_c(int sig)
{
	if (sig == SIGINT)
	{
		g_lb_data.ext_status = 1;
		if (!g_lb_data.sigflg)
			ft_putstr("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
	}
	rl_redisplay();
}
// function is responsible for setting up signal handling and managing
// input/output redirection for the program. It redirects standard
//  input and standard output, sets the action for certain
//  signals (ignoring SIGQUIT and using the handler function for SIGINT),
//   and resets some internal state related to signal handling.

void	handle_signal_in_out(void)
{
	dup2(g_lb_data.f_stdin, 0);
	dup2(g_lb_data.f_stdout, 1);
	g_lb_data.sig = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signal_ctrl_c);
}

int	main(int ac, char **str, char **env)
{
	return (0);
}
