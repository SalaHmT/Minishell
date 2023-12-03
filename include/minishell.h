/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:28:44 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/03 18:12:56 by shamsate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <stdio.h>  // for printf
# include <stdlib.h> // for malloc and free getenv
# include <unistd.h> // for write, access, open, read, close, fork
# include <limits.h> // for LLONG_MAX and LLONG_MIN
# include <signal.h> //for signal,sigaction,sigemptyset,sigaddset,kill,exit
# include <fcntl.h>      // for file-related functions
# include <dirent.h>     // for opendir, readdir, closedir
# include <string.h>     // for strerror, perror
# include <termios.h>    // for terminal-related functions
# include <unistd.h>     // for isatty, ttyname, ioctl
# include <curses.h>     // for terminal handling functions (curses library)
# include <sys/stat.h>   // for stat, lstat, fstat
# include <readline/readline.h> // for rl_on_new_ln rl_repl_line rl_redisp
# include <readline/history.h> // for rl_clear_history add_history
# include <sys/wait.h>   // for wait, waitpid
# include <sys/types.h>  // for getpid
# include <errno.h>

# define WELCOME  "\n \
	\033[1;34m╔══════════════════════════════════════════════════════════════════════════════════╗\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m███╗   ███╗ ██╗ ███╗   ██╗ ██╗ ███████╗ ██╗  ██╗  ███████╗ ██║      ██║      \033[34m  \033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m████╗ ████║ ██║ ████╗  ██║ ██║ ██╔════╝ ██║  ██║  ██╔════╝ ██║      ██║        \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m██╔████╔██║ ██║ ██╔██╗ ██║ ██║ ███████╗ ███████║  █████╗   ██║      ██║        \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m██║╚██╔╝██║ ██║ ██║╚██╗██║ ██║ ╚════██║ ██╔══██║  ██╔══╝   ██║      ██║        \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m██║ ╚═╝ ██║ ██║ ██║ ╚████║ ██║ ███████║ ██║  ██║  ███████╗ ███████╗ ███████╗   \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m╚═╝     ╚═╝ ╚═╝ ╚═╝  ╚═══╝ ╚═╝ ╚══════╝ ╚═╝  ╚═╝  ╚══════╝ ╚══════╝ ╚══════╝   \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m╚══════════════════════════════════════════════════════════════════════════════════╝\033[34m\n"

//parser
typedef struct s_comd
{
	char			*comd;
	char			**argms;
	int				inp;
	int				outp;
	int				errp;
	struct s_comd	*next;
}					t_comd;

typedef struct s_tkn
{
	char			*val;
	t_types			type;
	int				error;
	int				flg;
	struct s_tkn	*next;
	struct s_tkn	*prev;
}					t_tkn;

typedef enum e_err
{
	SUCC,
	ERRR,
	ERR1,
	CMD_EXE_FAILED = 126,
	CMD_NOT_EXIST = 127,
	SNTX_ERR = 258,
}	t_err;

typedef enum e_types
{
	NUl,
	CMD,
	ARG,
	INF,
	OUTF,
	POUT,
	DELIM,
	OUTP,
	PEND,
	INP,
	PIPE,
	HERDOC,
}	t_types;

// tkn & data list...
t_tkn	*ft_new_tkn(char	*data);
void	ft_add_tkn_back(t_tkn **data, t_tkn *new_dt);
void	free_val_tkn(t_tkn *lst);
void	free_clen_data(t_tkn **lst);
// commande list ...
t_comd	*ft_lastcmd_node(t_comd *cmd);
void	add_cmd_back(t_comd **cmd, t_comd *new_c);
void	free_arg_cmd(t_comd *cmd);
void	free_node_clean(t_comd **cmd);
int		cmd_size(t_comd *cmd);
// parsing ...
int		ischar(int c);
int		check_quotes(char *cmd, int idx);
int		check_red_pipe(char c, char *cmd, int idx);
void	check_sin_quotes(char *cmd, int *i, int *check);
int		check_both_quotes(char *cmd);



// utils_libft....
void	free_tab(char **tab);
size_t	ft_strlen(const char *str);
char	ft_joinchar(char *str, char c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *str);

#endif