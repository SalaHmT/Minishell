/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:58:02 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/02 14:18:03 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>      // for printf
#include <stdlib.h>     // for malloc and free
#include <unistd.h>     // for write, access, open, read, close, fork
#include <sys/wait.h>   // for wait, waitpid
#include <signal.h>     // for signal, sigaction, sigemptyset, sigaddset, kill, exit
#include <sys/types.h>  // for getpid
#include <sys/stat.h>   // for stat, lstat, fstat
#include <fcntl.h>      // for file-related functions
#include <dirent.h>     // for opendir, readdir, closedir
#include <string.h>     // for strerror, perror
#include <termios.h>    // for terminal-related functions
#include <unistd.h>     // for isatty, ttyname, ioctl
#include <stdlib.h>     // for getenv
#include <curses.h>     // for terminal handling functions (curses library)

# define INT_X	+9223372036854775807
# define INT_N	-9223372036854775807

// utils-minishell
void	ft_putstr_fd(char *s, int fd);
int	    ft_isdigit(int c);
int	    is_all_digit(char *s);

#endif
