/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/10 12:19:50 by owen          #+#    #+#                 */
/*   Updated: 2025/04/15 13:08:47 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "err_msg.h"

int	find_valid_cmd(t_data *data, char **cmd, char *copy, int i)
{
	char	*temp;

	temp = NULL;
	if (!copy)
		exit_error(NULL, 1, data);
	while (data->paths[i])
	{
		if (access(*cmd, F_OK) == 0)
			return ((i + 1));
		temp = ft_strjoin(data->paths[i], "/");
		if (!temp)
			exit_error(NULL, 1, data);
		free(*cmd);
		*cmd = ft_strjoin(temp, copy);
		if (!*cmd)
			exit_error(NULL, 1, data);
		free(temp);
		i++;
	}
	return (i);
}

void	set_cmd_path(t_data *data, char **cmd, char **copy)
{
	bool	cmd_found;
	int		i;

	cmd_found = false;
	i = 0;
	while (access(*cmd, X_OK) != 0 && data->paths[i])
	{
		i = find_valid_cmd(data, cmd, copy[0], i);
		if (data->paths[i])
				cmd_found = true;
	}
	if (access(*cmd, X_OK) != 0 && cmd_found == true)
		exit_error(ft_strjoin(copy[0], ERR_126), 126, data);
	else if (access(*cmd, X_OK) != 0)
		exit_error(ft_strjoin(copy[0], ERR_127), 127, data);
	free(data->paths);
	free(copy);
}

void	child_1(t_data *data, char *file, char **envp)
{
	int	fd;

	if (data->cmd_1[0] == ' ')
		exit_error(ft_strjoin(data->args_1[0], ERR_127), 127, data);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(NULL, 1, data);
	set_cmd_path(data, &data->cmd_1, data->args_1);
	if (!data->cmd_1)
		exit_error(NULL, 1, data);
	if (dup2(fd, STDIN_FILENO) == -1)
		exit_error(NULL, 1, data);
	if (dup2(data->pipefd[1], STDOUT_FILENO) == -1)
		exit_error(NULL, 1, data);
	close(data->pipefd[0]);
	if (execve(data->cmd_1, data->args_1, envp) == -1)
		exit_error(NULL, 1, data);
}
void	child_2(t_data *data, char *file, char **envp)
{
	int	fd;

	if (!data->args_2 || data->cmd_2[0] == ' ')
		exit_error(ft_strjoin(data->args_2[0], ERR_127), 127, data);
	fd = open(file, O_CREAT | O_WRONLY| O_TRUNC, 0644);
	if (fd == -1)
		exit_error(NULL, 1, data);
	set_cmd_path(data, &data->cmd_2, data->args_2);
	if (!data->cmd_2)
		exit_error(NULL, 1, data);
	if (dup2(data->pipefd[0], STDIN_FILENO) == -1)
		exit_error(NULL, 1, data);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit_error(NULL, 1, data);
	close(data->pipefd[1]);
	if (execve(data->cmd_2, data->args_2, envp) == -1)
		exit_error(NULL, 1, data);
}
