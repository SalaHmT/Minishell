/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:43:13 by mdoulahi          #+#    #+#             */
/*   Updated: 2023/12/26 17:51:28 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	ft_pwd(t_info *data, t_comd *cmd)
{
	ft_putstr(data->pwd_value, cmd->outp);
	ft_putstr("\n", cmd->outp);
	g_ext_status = 0;
}
