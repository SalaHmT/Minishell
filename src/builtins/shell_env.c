/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:58:12 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/05 18:39:23 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void shell_env(t_shell *cmd)
{
    int i;

    i = 0;
    while (cmd->str[i])
    {
		ft_putstr_fd(cmd->str[i], STDOUT_FILENO);
        ft_putchar_fd('\n', STDIN_FILENO);
		i++;
    }
}
