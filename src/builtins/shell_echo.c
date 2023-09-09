/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:55:47 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/09 17:33:21 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	shell_echo(t_shell *cmd)
{
	char	**s;
	int		i;
	bool	n_option;

	n_option = false;
	s = cmd->cmnd;
	i = 1;
	// Check for the -n option in the command-line arguments
	while (s[i] != NULL)
	{
		if (ft_strcmp(s[i], "-n") == 0)
			n_option = true;
		else
		{
			// Print the current argument followed by a space
			ft_putstr_fd(s[i], STDOUT_FILENO);
			if (s[i + 1] != NULL) // Check if there is a next argument
				ft_putchar_fd(' ', STDOUT_FILENO);
		}
		i++;
	}
	// Print a newline character if the -n option was not present
	if (!n_option)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
