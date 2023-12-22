/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/12/22 21:48:54 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

// this code is a signal handler specifically designed to handle
//  the SIGINT signal, commonly used to handle Ctrl+C interrupts
//   in a terminal-based program. It updates some internal
//    state (g_lb__data.exit_status) and performs some actions to clear
//     the input line and refresh the display to provide a smooth user
// 	 experience when the program is interrupted.
void	handle_signal_ctrl_c(int sig, t_context *ptr)
{
	static t_context	*context;

	if (sig == -200)
		context = ptr;
	if (sig == SIGINT)
	{
		g_ext_status = 1;
		if (!context->data->sigflg)
			ft_putstr("\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}
// function is responsible for setting up signal handling and managing
// input/output redirection for the program. It redirects standard
//  input and standard output, sets the action for certain
//  signals (ignoring SIGQUIT and using the handler function for SIGINT),
//   and resets some internal state related to signal handling.

void	handle_signal_in_out(t_context *context)
{
	dup2(context->data->f_stdin, 0);
	dup2(context->data->f_stdout, 1);
	context->data->sig = 0;
	signal(SIGQUIT, SIG_IGN);
	handle_signal_ctrl_c(-200, context);
	signal(SIGINT, (void (*)(int))handle_signal_ctrl_c);
}

//simple shell loop that reads input, processes commands, and executes
void	loop_and_process_exec_cmd(t_tkn *data, t_comd *cmd, t_context *context)
{
	char	*ln;

	while (1)
	{
		handle_signal_in_out(context);
		ln = readline(":) Minishell: $ ");
		context->data->sigflg = 0;
		if (!ln)
		{
			printf("exit\n");
			break ;
		}
		if (ln[0])
		{
			if (proc_valid_cmd(ln, data, &cmd, context))
			{
				free_node_clean(&cmd);
			}
		}
		free(ln);
	}
}

int	main(int ac, char **str, char **env)
{
	t_tkn		*data;
	t_comd		*cmd;
	t_context	*context;

	(void)env;
	g_ext_status = 0;
	printf("%s\n", WELCOME);
	if (!isatty(0))
		return (0);
	if (ac == 1)
	{
		context = initialize_context();
		if (context == NULL)
			return (0);
		context->data->f_stdin = dup(0);
		context->data->f_stdout = dup(1);
		(void)str;
		data = malloc(sizeof(t_tkn *));
		cmd = NULL;
		loop_and_process_exec_cmd(data, cmd, context);
		free(data);
		free(context);
	}
	exit(g_ext_status);
}
