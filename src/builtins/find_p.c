/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:04:17 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/07 17:33:09 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void search_PWD(t_shell *cmd)
{
    char **s;
    int i;

    s = cmd->str;
    i = 0;
    while (s[i])
    {
        if (!ft_strncmp(s[i], "PWD=", 4))
            cmd->_pwd = ft_substr(s[i], 4, ft_strlen(s[i]) - 4);
        if (!ft_strncmp(s[i], "OLDPWD=", 7))
            cmd->_oldpwd = ft_substr(s[i], 7, ft_strlen(s[i]) - 7);
        i++;
    }  
}

void search_Path(t_shell *cmd)
{
    char **s;
    int i;

    s = cmd->str;
    i = 0;
    while (s[i])
    {
        if (!ft_strncmp(s[i], "PATH=", 5))
            cmd->path = ft_substr(s[i], 5, ft_strlen(s[i]) - 5);   
        i++;
    }
    if (!cmd->_pwd)
        cmd->path = ft_strdup("");
}
