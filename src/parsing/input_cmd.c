/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:37:40 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/09 14:16:10 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void input_cmd(t_shell *m_shell, char *input)
{
    m_shell->cmnd = ft_split(input, ' ');

    // Check if cmnd is NULL or if the first element is NULL
    if (!m_shell->cmnd || !m_shell->cmnd[0]) {
        // Handle error or return as needed
        // For example: free the memory, set an error code, and return
        return;
    }

    int len = set_size_arg(m_shell->cmnd);
    t_list *cmd_list = NULL; // Initialize an empty linked list

    while (len)
    {
        // Convert the token to an integer
        int content = atoi_exit(m_shell->cmnd[--len]);

        // Create a new t_list node and add it to the linked list
        t_list *new_cmd = ft_lstnew(content);
        if (!new_cmd)
        {
            // Handle memory allocation error
            // You can free the already allocated memory before returning
            // and set an error code if needed
            return;
        }
        // Add the new node to the end of the linked list
        ft_lstadd_back(&cmd_list, new_cmd);
    }
    // Assign the linked list to m_shell->cmd_list
    m_shell->cmd_list = cmd_list; // Corrected assignment here
}
