/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:52:51 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/04 21:31:52 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool is_buil(t_shell *msh)
{
    if (!msh->cmnd)
        return (false);
    else if (!ft_strcmp(msh->cmnd[0], "exit") || (!ft_strcmp(msh->cmnd[0], "exit") && msh->cmnd[1] != NULL))
        return (true);
    return (false);
}

void mini_exec(t_shell *m_sh)
{
    if ((lst_size_cmd(m_sh->cmd_list) == 1 || lst_size_cmd(m_sh->cmd_list) == 2) && is_buil(m_sh) == true)
    {
        if (!ft_strcmp(m_sh->cmnd[0], "exit") || (!ft_strcmp(m_sh->cmnd[0], "exit") && m_sh->cmnd[1]))
            shell_exit(m_sh);
    }
    else
        printf("%s : command not found\n", m_sh->cmnd[0]);
}

