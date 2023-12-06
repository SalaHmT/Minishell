/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tkn_data_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:06:13 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/06 21:42:49 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_reder(int var)
{
	if (var == HERDOC || var == OUTP || var == INP || var == PEND)
		return (1);
	return (0);
}

int	check_reder_tkn(t_tkn **data)
{
	t_tkn	*tmp;

	tmp = *data;
	while (tmp)
	{
		if (is_reder(tmp->type) && !tmp->next)
		{
			ft_putstr("bashn't: syntax error near" \
				" unexpected token '", 2);
			return (1);
		}
		if (is_reder(tmp->type) && !tmp->next
			&& (is_reder(tmp->next->type) || tmp->next->type == PIPE))
		{
			ft_putstr("bashn't: syntax error near" \
				" unexpected token '", 2);
			ft_putstr(tmp->next->val, 2);
			ft_putstr("'\n", 2);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
