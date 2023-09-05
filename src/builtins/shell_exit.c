/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:50:15 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/05 13:49:38 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void shell_exit(t_shell *cmd)
{
    int numb_exit;

    // If no argument is provided, exit with 0
    if (!cmd->cmnd[1])
    {
        ft_putstr_fd("\033[1;32mexit\n\033[0m", STDERR_FILENO);
        exit(STDIN_FILENO);
    }

    // Check if there are too many arguments
    if (is_all_digit(cmd->cmnd[1]) && cmd->cmnd[2])
    {
        ft_putstr_fd("exit: too many arguments\n", STDERR_FILENO);
    }

    // If the argument is a valid integer, convert it to exit code
    else if (is_all_digit(cmd->cmnd[1]))
    {
        ft_putstr_fd("\033[1;34mexit\n\033[0m", STDERR_FILENO);
        numb_exit = atoi_exit(cmd->cmnd[1]);
        exit(numb_exit); // Exit with the specified exit code
    }
    else
    {
        // Print an error message if the argument is not a valid integer
        ft_putstr_fd("minishell: ", STDERR_FILENO);
        ft_putstr_fd("exit: ", STDERR_FILENO);
        ft_putstr_fd(cmd->cmnd[1], STDERR_FILENO);
        ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
        numb_exit = 255;
        exit(numb_exit); // Exit with the specified exit code
    }
}
