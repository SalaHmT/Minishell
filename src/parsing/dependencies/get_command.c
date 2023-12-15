/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:27:13 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/15 18:48:25 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	command_init(t_comd	*cmd)
{
	cmd->argms = NULL;
	cmd->comd = NULL;
	cmd->errp = 1;
	cmd->next = NULL;
	cmd->inp = 1;
	cmd->outp = 0;
}

void	add_cmd_list(t_comd **cmd, t_comd **new_c)
{
	add_cmd_back(cmd, *new_c);
	*new_c = (t_comd *)malloc(sizeof(t_comd));
	command_init(*new_c);
}

void	check_update_cmd(t_comd **new_c)
{
	if ((*new_c)->comd)
		free ((*new_c)->comd);
	(*new_c)->comd = ft_strdup((*new_c)->argms[0]);
	if (check_cmd_isdretory((*new_c)->comd))
		(*new_c)->inp = -1;
}
