/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/03 22:29:45 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int main() {
    char *input;

    signal(SIGINT, SIG_IGN);// ignore clt-c whene you press in your keyboord
    while (1) 
    {
        signal(SIGINT, sig_ctlc);
        input = readline("\033[0;32mminishell-$ \033[0m");
        if (!input) // Handle EOF or error (e.g., Ctrl+D) whene you press (e.g., Ctrl+D) progreme is finish
        {
            printf("exit\n");
            break;
        }
        add_history(input); // Add the input to the history as before
        printf("%s\n", input);// Process the command line (e.g., execute it or parse it)
        free(input);// Free the input buffer
    }
    return (0);
}

