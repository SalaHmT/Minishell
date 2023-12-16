/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:52:39 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/16 21:24:23 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

//function is responsible for reading input lines, handling
// the interruption signal, writing input lines to a file descriptor,
//  and performing necessary memory management.
int	hdoc_read_handle_write(char *line, char *delim, int fd, char *delimiter)
{
	signal(SIGINT, heredoc_signal);
	line = readline(">");
	if (!line)
		return (g_lb_data.sigflg = 1, free(delim), free(line), 1);
	if (line[0])
	{
		if (!strcmp(line, delim))
			return (free(delim), free(line), 1);
		if (is_quotes_exist(delimiter))
			line = expand_var_char(line);
		ft_putstr(line, fd);
		ft_putstr("\n", fd);
	}
	else if (ft_strlen(delim) == 0)
		return (free(delim), free(line), 1);
	free (line);
	return (0);
}

// From the context provided, it seems like this function is involved
//  in handling a "here document" in the C program. The purpose appears
//   to be to create and write to a file based on the provided delimiter
//    and then return the name of the created file. However, the specific
//     details of the ft_namegenerator,
char	*hdoc_create_wr_tofile(char *delim)
{
	char	*dlim;
	char	*name;
	char	*line;
	int		fd;

	name = generate_name_tmpfile();
	line = NULL;
	fd = open(name, O_TRUNC | O_CREAT | O_RDWR, 0777);
	while (1 && fd != -1)
		if (hdoc_read_handle_write(line, dlim, fd, delim))
			break ;
	close (fd);
	return (name);
}

