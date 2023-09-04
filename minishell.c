/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/04 21:53:16 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int main(int ac, char **str, char **env)
{
    (void)str;
    (void)env;
    t_shell *cmd;
    if (ac == 1)
    {
        cmd = malloc(sizeof(t_shell));
        if (!cmd)
            return (0);
        cmd->cmnd = ft_comdup(env); 
        mini_shell_w(cmd);
    }
    return (0);
}
