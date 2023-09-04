/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:58:02 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/04 22:23:23 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>      // for printf
#include <stdlib.h>     // for malloc and free getenv
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
#include <curses.h>     // for terminal handling functions (curses library)
#include <readline/readline.h> // for rl_on_new_line rl_replace_line rl_redisplay
#include <readline/history.h> // for rl_clear_history add_history
#include <limits.h> // for LLONG_MAX and LLONG_MIN

typedef struct s_shell t_shell;
typedef struct s_list t_list;

# define PIPE		0
# define DQ			1
# define SQ			2
# define WORD		3
# define RDIN		4
# define RDOUT		5
# define RDHER		6
# define RDAPP		7
# define VARIABLE	8
# define AND		9
# define OR			10
# define PRTOPEN	11
# define PRTCLOSE	12
# define WILD		13
# define SPACES		14
# define LIST		15
# define RDARG		16
# define IN			0
# define OUT		1

// utils-minishell
void	ft_putstr_fd(char *s, int fd);
int	    ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int	    is_all_digit(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
int	    count(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
char	**ft_split(char const *s, char c);
void	freesplit(char **s, int i);
void	ft_putstr_fd(char *s, int fd);
int	    set_size_arg(char **s);

//handler signal 
void sig_ctlc(int input_sig); //handler signal ctlc

// minishell fonction
void mini_shell_w(t_shell *cmd);

///////////////////////////////////
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

int	ft_strcmp(char *s1, char *s2);
int	lst_size_cmd(t_list *lst);


typedef struct s_shell
{
    char **cmnd;
    t_list *cmd_list; // Pointer to the linked list of commands
    struct s_shell *next;
}			t_shell;

//exec_minishell
bool is_buil(t_shell *msh);
void mini_exec(t_shell *m_sh);
char	**ft_comdup(char **str);
void	input_cmd(t_shell *m_shell, char *input);
t_list	*ft_lstlast(t_list *lst);
long long int	atoi_exit(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new_cmd);
t_list	*ft_lstnew(int content);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void shell_exit(t_shell *cmnd);

#endif
