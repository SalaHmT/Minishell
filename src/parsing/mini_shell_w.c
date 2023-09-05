/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_shell_w.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:34:38 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/05 18:34:26 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void mini_shell_w(t_shell *cmd)
{
    char *input;

    signal(SIGINT, SIG_IGN);// ignore clt-c whene you press in your keyboord
    while (1) 
    {
        signal(SIGINT, sig_ctlc);
        input = readline("\033[1;36mminishell\033[34m$ \033[0m");
        if (!input) // Handle EOF or error (e.g., Ctrl+D) whene you press (e.g., Ctrl+D) progreme is finish
        {
            printf("exit\n");
            break;
        }
        add_history(input); // Add the input to the history as before
        input_cmd(cmd, input);
        mini_exec(cmd);
        free(input);// Free the input buffer
    }
}
