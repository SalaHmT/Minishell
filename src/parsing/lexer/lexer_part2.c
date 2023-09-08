/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:29:17 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/08 17:29:30 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
#include "../../../include/lexer.h"

int wrds_reading(char *str, int i, t_lex **lex_list)
{
    int j;
    
    j = 0;
    while (str[i + j] && !(token_check(str[i + j])))
    {
        j = j + check_quotes(str, i + j, 34);
        j = j + check_quotes(str, i + j, 39);
        if (is_space_tab(str[i + j]))
            break;
        else
            j++;
    }
    if (!add_nd(ft_substr(str, i, j), 0, lex_list))
        return(-1);
    return (j);
}