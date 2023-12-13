/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:27:13 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/13 20:24:30 by shamsate         ###   ########.fr       */
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
