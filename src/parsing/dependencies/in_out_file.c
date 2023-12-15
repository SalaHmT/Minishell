/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:52:12 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/15 20:13:14 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

// the function seems to handle file input redirection for a shell-like program.
//  It first checks if the value is a backspace character, and if not,
//   it attempts to open the file specified by value for reading.
//  It also handles error scenarios by setting appropriate error codes
//and messages.

void	check_red_open(t_comd **cmd, char *val, t_tkn *ptr)
{
	if (!ft_strcmp(val, "\b"))
	{
		g_lb_data.ext_status = 1;
		ft_putstr("bashn't: ambiguous redirect\n", 2);
		(*cmd)->inp = -1;
		(*cmd)->errp = 0;
		g_lb_data.ext_status = ERRR;
		ptr->error = 1;
	}
	if ((*cmd)->inp != -1)
	{
		(*cmd)->inp = open(val, O_RDONLY);
		if ((*cmd)->inp == -1)
		{
			g_lb_data.ext_status = 1;
			ft_putstr("bashn't: ", 2);
			perror(val);
			(*cmd)->errp = 0;
			g_lb_data.ext_status = ERRR;
			ptr->error = 1;
		}
	}
}
