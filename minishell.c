/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:56:46 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/03 18:36:45 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

int main() {
    char *input;
    char *command_line = NULL;  // To accumulate the command line

    while (1) {
        input = readline("minishell-$ ");

        if (input == NULL) {
            // Handle EOF or error (e.g., Ctrl+D)
            printf("\nExiting Minishell.\n");
            free(command_line);
            break;
        }

        // Add the input to the history as before
        if (strlen(input) > 0) {
            add_history(input);
        }

        // Process the command line (e.g., execute it or parse it)
        // For simplicity, we'll just print the input
        char **s = ft_split(input, ' ');
        int i = 0;
        while (s[i] != NULL) {
            printf("%s.\n", s[i]);
            free(s[i]); // Free each element of the split result
            i++;
        }
        free(s); // Free the split result array

        // Free the input buffer
        free(input);
    }

    // Free the accumulated command line
    free(command_line);

    return 0;
}

