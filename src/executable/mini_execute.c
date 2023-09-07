/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:52:51 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/07 17:43:48 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool is_buil(t_shell *msh)
{
    if (!msh->cmnd)
        return (false);
    else if (!ft_strcmp(msh->cmnd[0], "exit") || (!ft_strcmp(msh->cmnd[0], "exit") && msh->cmnd[1] != NULL))
        return (true);
    else if (!ft_strcmp(msh->cmnd[0], "env") || (!ft_strcmp(msh->cmnd[0], "env") && msh->cmnd[1] != NULL))
        return (true);
    return (false);
}

void extra_command(t_shell *cmd)
{
    if (!ft_strcmp(cmd->cmnd[0], "PWD"))
        printf("%s\n", cmd->_pwd);
    else if (!ft_strcmp(cmd->cmnd[0], "OLDPWD"))
        printf("%s\n", cmd->_oldpwd);
    else if (!ft_strcmp(cmd->cmnd[0], "PATH"))
        printf("%s\n", cmd->path);
    else
        printf("%s : command not found\n", cmd->cmnd[0]);
}

void mini_exec(t_shell *m_sh)
{
    if (is_buil(m_sh) == true)
    {
        if (!ft_strcmp(m_sh->cmnd[0], "exit") || (!ft_strcmp(m_sh->cmnd[0], "exit") && m_sh->cmnd[1]))
            shell_exit(m_sh);
        if (!ft_strcmp(m_sh->cmnd[0], "env") || (!ft_strcmp(m_sh->cmnd[0], "env") && m_sh->cmnd[1]))
            shell_env(m_sh);
    }
    else
        extra_command(m_sh);
}