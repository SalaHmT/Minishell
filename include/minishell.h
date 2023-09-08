/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shamsate <shamsate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:28:44 by shamsate          #+#    #+#             */
/*   Updated: 2023/09/08 17:28:55 by shamsate         ###   ########.fr       */
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
    char **str;
    char **cmnd;
    char *_pwd;
    char *_oldpwd;
    char *path;
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
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void shell_env(t_shell *cmd);

// search
void search_PWD(t_shell *cmd);
void search_Path(t_shell *cmd);
void search(t_shell *cmd);

#endif