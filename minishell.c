/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/09 14:12:50 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int main(int ac, char **str, char **env)
{
    (void)str;
    t_shell *cmd;
    if (ac == 1)
    {
        printf("%s\n", Welcome);
        cmd = malloc(sizeof(t_shell));
        if (!cmd)
            return (0);
        cmd->str = ft_comdup(env);
        mini_shell_w(cmd);
    }
    else
    {
		printf("\033[0;31mThis Program Does Not Accept Arguments\n\033[0m");
		exit(0);
	}
    return (0);
}
