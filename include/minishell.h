/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:28:44 by shamsate          #+#    #+#             */
/*   Updated: 2023/12/16 21:42:54 by shamsate         ###   ########.fr       */
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

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;36m"
# define MAGENTA "\033[1;35m"
# define WHITE "\033[1;37m"
# define BLACK "\033[1;30m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define REVERSE "\033[7m"
# define HIDDEN "\033[8m"
# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define RESET "\033[0m"

# define WELCOME  "\n \
	\033[1;34m╔══════════════════════════════════════════════════════════════════════════════════╗\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m███╗   ███╗ ██╗ ███╗   ██╗ ██╗ ███████╗ ██╗  ██╗  ███████╗ ██║      ██║      \033[34m  \033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m████╗ ████║ ██║ ████╗  ██║ ██║ ██╔════╝ ██║  ██║  ██╔════╝ ██║      ██║        \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m██╔████╔██║ ██║ ██╔██╗ ██║ ██║ ███████╗ ███████║  █████╗   ██║      ██║        \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m██║╚██╔╝██║ ██║ ██║╚██╗██║ ██║ ╚════██║ ██╔══██║  ██╔══╝   ██║      ██║        \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m██║ ╚═╝ ██║ ██║ ██║ ╚████║ ██║ ███████║ ██║  ██║  ███████╗ ███████╗ ███████╗   \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m║\033[34m   \033[1;31m╚═╝     ╚═╝ ╚═╝ ╚═╝  ╚═══╝ ╚═╝ ╚══════╝ ╚═╝  ╚═╝  ╚══════╝ ╚══════╝ ╚══════╝   \033[34m\033[1;34m║\033[34m\n\
	\033[1;34m╚══════════════════════════════════════════════════╝\033[34m\n"

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
t_tkn		*ft_new_tkn(char	*data);
void		ft_add_tkn_back(t_tkn **data, t_tkn *new_dt);
void		free_val_tkn(t_tkn *lst);
void		free_clen_data(t_tkn **lst);
// commande list ...
t_comd		*ft_lastcmd_node(t_comd *cmd);
void		add_cmd_back(t_comd **cmd, t_comd *new_c);
void		free_arg_cmd(t_comd *cmd);
void		free_node_clean(t_comd **cmd);
int			cmd_size(t_comd *cmd);
// parsing ...
int			is_val_char(int c);
int			check_quotes(char *cmd, int idx);
int			check_red_pipe(char c, char *cmd, int idx);
void		check_sin_quotes(char *cmd, int *i, int *check);
int			check_both_quotes(char *cmd);
void		command_init(t_comd	*cmd);
void		check_update_cmd(t_comd **new_c);
void		add_cmd_list(t_comd **cmd, t_comd **new_c);
int			is_reder(int var);
int			check_reder_tkn(t_tkn **data);
int			check_pipe_red_herdoc(t_tkn **data);
int			is_a_directory(char *str);
int			check_cmd_isdretory(char *str);
//in_out_file...
void		update_outfile(t_comd **command, char *file_path, t_tkn *token);
void		check_red_open(t_comd **cmd, char *val, t_tkn *ptr);
void		check_append_outerr(t_comd **cmd, char val, t_tkn *ptr);
int			check_err_pipe(t_tkn *data);
void		handle_in_out(t_tkn *ptr, t_comd **cmd);
//lexer
int			is_red_char(char c);
void		add_operator_tkn(t_tkn **data, char *cmd, int *idx);
void		cmd_to_str_add(t_tkn **data, char *cmd, int *idx);
static int	set_type_arg(t_tkn **data);
void		modify_cmd_if(t_tkn	**data);
//expand....
int			is_quotes_exist(char *str);
int			cont_no_wspace(char *str);
char		*if_contain_env_var(char *str);
char		*extract_value_checkname(char *val, int	*idx);
void		get_val_concat(char	*val, int *i, char **str, int *flg);
void		append_char_str(char *val, char **str, int i);
char		*expand_var_char(char *val);
char		*expand_var_str(char *val);
char		*expand_delim(char *delim);
void		expand_check_update_cmdargs(t_tkn *ptr, t_comd *new_c);
// heredoc.....
char		*generate_name_tmpfile(void);
void		heredoc_signal(int sig);
int			hdoc_rd_handle_wt(char *line, char *delim, int fd, char *delimiter);
char		*hdoc_create_wr_tofile(char *delim);
int			process_heredoc(t_tkn	**data);
// utils_libft....
void		free_tab(char **tab);
size_t		ft_strlen(const char *str);
char		ft_joinchar(char *str, char c);
int			ft_isdigit(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *str);
void		ft_putchar(char c);
void		ft_putstr(char *str, int fd);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strjoin(char *s1, char const *s2);
char		*ft_itoa(int nbr);
char		*ft_strchr(const char *str, int c);
void		*ft_calloc(size_t nbr, size_t size);
void		ft_bzero(void *str, size_t nb);
char		**ft_split(const char *str, char delimiter);
char		**ft_realloc(char **tab, char *str);
void		check_red_open(t_comd **cmd, char *val, t_tkn *ptr);
//execution

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int			ext_status;
	t_list		*env;
	int			sig;
	int			sigflg;
}				t_data;

t_data	g_lb_data;

#endif