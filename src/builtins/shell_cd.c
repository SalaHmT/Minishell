/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamsiah <ylamsiah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:54:01 by ylamsiah          #+#    #+#             */
/*   Updated: 2023/09/09 14:17:02 by ylamsiah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// Function to find a path within the t_shell structure
char	*find_path(char *find, t_shell *mini_s)
{
	int	i;
	int len;
	char **s;

	s = mini_s->str;
	len = ft_strlen(find);
	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s[i], find, len))
			return (ft_substr(s[i], len, ft_strlen(s[i]) - len));
		i++;
	}
	return (NULL);
}

// Function to print error messages
void ft_error_msg(int err_num, char *str, int fd)
{
    char *err_msg;

    if (err_num == ENOENT)
        err_msg = "No such file or directory\n";
    else if (err_num == EACCES)
        err_msg = "Permission denied\n";
    else if (err_num == ENOTDIR)
        err_msg = "Not a directory\n";
    else
        err_msg = "Unknown error\n";
    ft_putstr_fd(str, fd);
    ft_putstr_fd(": ", fd);
    ft_putstr_fd(err_msg, fd);
}

// Function to change the current working directory
int check_way(t_shell *cm, char *str)
{
    char *tmp;
    int ret;

    tmp = find_path(str, cm);
    ret = chdir(tmp);
    free(tmp);
    if (ret == -1)
	{
        perror("chdir");
        ft_error_msg(errno, "chdir", STDERR_FILENO);
    }

    return (ret);
}

// Function to update environment variables
void	add_up_to_env(t_shell *m_shell)
{
	int		i;
	char	*path;
	char **s;

	s = m_shell->str;
	i = 0;
	while (s[i])
	{
		if (!ft_strncmp(s[i], "PWD=", 4))
		{
			path = ft_strjoin("PWD=", m_shell->_pwd);
			free(s[i]);
			s[i] = path;
		}
		else if (!ft_strncmp(s[i], "OLDPWD=", 7) && m_shell->_oldpwd)
		{
			path = ft_strjoin("OLDPWD=", m_shell->_oldpwd);
			free(s[i]);
			s[i] = path;
		}
		i++;
	}
}

// Function to change the working directory
void change_path(t_shell *cmd)
{
    // Duplicate the current working directory path
    char *new_pwd;

	new_pwd = getcwd(NULL, 0);
    // Free the memory previously allocated for '_oldpwd'
    free(cmd->_oldpwd);

    // Update '_oldpwd' to point to the newly duplicated path
    cmd->_oldpwd = cmd->_pwd;

    // Update '_pwd' to the new current working directory path
    cmd->_pwd = new_pwd;
}

// Function for the "cd" command
void shell_cd(t_shell *shell_m) 
{
    int ret;
    char **s;

    s = shell_m->cmnd;
    if (!s[1] || !ft_strcmp(s[1], "-")) // Check if no arguments or argument is "-"
        ret = check_way(shell_m, "HOME=");
    else if (ft_strncmp(s[1], "-", 1) == 0)
        ret = check_way(shell_m, "OLDPWD=");
    else
	{
        ret = check_way(shell_m, s[1]);
        if (ret != 0) {
            ft_putstr_fd("minishell: ", STDERR_FILENO);
            ft_putstr_fd(s[1], STDERR_FILENO);
            perror(" ");
        }
    }

    if (ret != 0)
        return;

    change_path(shell_m);
    add_up_to_env(shell_m);
}
