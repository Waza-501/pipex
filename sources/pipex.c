/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/03 15:55:18 by owhearn       #+#    #+#                 */
/*   Updated: 2025/04/15 15:37:50 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "err_msg.h"
#include <errno.h>
#include <sys/wait.h>

void	parse_input(t_data *data, int argc, char **argv, char **envp)
{
	int		i;

	i = 0;
	if (argc != 5)
		exit_error(ft_strdup(ERR_INPUT), 1, NULL);
	while (envp[i] && data->paths == NULL)
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			data->paths = ft_split(&envp[i][5], ':');
		i++;
	}
	data->args_1 = ft_split(argv[2], ' ');
	data->cmd_1 = ft_strdup(data->args_1[0]);
	data->args_2 = ft_split(argv[3], ' ');
	data->cmd_2 = ft_strdup(data->args_2[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		status;

	data = init_data();
	parse_input(&data, argc, argv, envp);
	if (pipe(data.pipefd) < 0)
		exit_error(NULL, 1, &data);
	data.pid1 = fork();
	if (data.pid1 == -1)
		exit_error(NULL, 1, &data);
	else if (data.pid1 == 0)
		child_1(&data, argv[1], envp);
	data.pid2 = fork();
	if (data.pid2 == -1)
		exit_error(NULL, 1, &data);
	else if (data.pid2 == 0)
		child_2(&data, argv[4], envp);
	close(data.pipefd[0]);
	close(data.pipefd[1]);
	waitpid(data.pid1, &status, 0);
	waitpid(data.pid2, &status, 0);
	free_data(&data);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	return (0);
}
