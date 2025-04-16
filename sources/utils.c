/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/10 17:27:48 by owen          #+#    #+#                 */
/*   Updated: 2025/04/16 16:11:27 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "err_msg.h"
#include <errno.h>

void	free_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_data(t_data *data)
{
	if (data->args_1)
		free_array(data->args_1);
	if (data->args_2)
		free_array(data->args_2);
	if (data->cmd_1)
		free(data->cmd_1);
	if (data->cmd_2)
		free(data->cmd_2);
	if (data->paths)
		free_array(data->paths);
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
		exit(1);
	}
	ft_putendl_fd(msg, 2);
	free(msg);
	exit(code);
}

t_data	init_data(void)
{
	t_data	ret;

	ret.cmd_1 = NULL;
	ret.args_1 = NULL;
	ret.cmd_2 = NULL;
	ret.args_2 = NULL;
	ret.paths = NULL;
	return (ret);
}
