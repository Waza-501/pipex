/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_and_exit.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/08 12:33:11 by owen          #+#    #+#                 */
/*   Updated: 2025/04/15 12:54:31 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "err_msg.h"
#include <errno.h>

void	free_array(char **array, int i)
{
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->args_1)
		free_array(data->args_1, i);
	if (data->args_2)
		free_array(data->args_2, i);
	if (data->cmd_1)
		free(data->cmd_1);
	if (data->cmd_2)
		free(data->cmd_2);
	if (data->paths)
		free_array(data->paths, i);
}

int	exit_error(char *msg, int code, t_data *data)
{
	if (data)
		free_data(data);
	if (code == 126 || code == 127)
	{
		ft_putendl_fd(msg, 2);
		free(msg);
		exit(code);
	}
	if (!msg)
	{
		perror("Error");
		exit(errno);
	}
	ft_putendl_fd(msg, 2);
	free(msg);
	perror("Error");
	exit(errno);
}
