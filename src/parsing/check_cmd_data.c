/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:55:46 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/08 22:52:43 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	set_type_arg(t_tkn **data)
{
	if (ft_strcmp((*data)->val, "|") == 0)
		(*data)->type = PIPE;
	else if (ft_strcmp((*data)->val, "<<") == 0)
		(*data)->type = HERDOC;
	else if (ft_strcmp((*data)->val, ">>") == 0)
		(*data)->type = PEND;
	else if (ft_strcmp((*data)->val, "<") == 0)
		(*data)->type = INP;
	else if (ft_strcmp((*data)->val, ">") == 0)
		(*data)->type = OUTP;
	else if ((*data)->prev && (*data)->prev->type == PIPE)
		(*data)->type = CMD;
	else if ((*data)->prev && (*data)->prev->type == HERDOC)
		(*data)->type = DELIM;
	else if ((*data)->prev && (*data)->prev->type == PEND)
		(*data)->type = OUTP ;
	else if ((*data)->prev && (*data)->prev->type == OUTP)
		(*data)->type = OUTF;
	else if ((*data)->prev && (*data)->prev->type == INP)
		(*data)->type = INF;
	else
		(*data)->type = ARG;
	return (1);
}


