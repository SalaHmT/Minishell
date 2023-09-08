/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:28:51 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/08 17:29:07 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
#include "minishell.h"
#include "lexer.h"
typdef struct s_tools
{

}t_tools;


typedef struct pars_tools
{
    t_lex   *lex_list;
    t_lex   *redir;
    int     id_redir;
    t_tools *tools;
}t_pars


#endif