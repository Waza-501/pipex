/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/03 15:55:18 by owhearn       #+#    #+#                 */
/*   Updated: 2025/04/09 14:10:45 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "err_msg.h"
#include <errno.h>

int	parse_input(t_data data, char **argv, char **envp)
{
	/*data.fd1 = open(argv[1], O_RDONLY);
	data.fd2 = open(argv[4], O_RDONLY);
	if (data.fd1 == -1 || data.fd2 == -1)
		exit_error("haha funny can't open file", -1);*/
	
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	mario;
	pid_t	luigi;
	t_data	data;

	if (argc != 5)
	{
		ft_putendl_fd(ERR_INPUT, 2);
		exit(-1);
	}
	parse_input(data, argv, envp);
	if (pipe(data.pipefd) < 0)
		exit_error("pipe failed.");
	return (0);
}

/*some notes
When the command its not found, return 127 When the command is found, but not
executable, return 126 Remember to call WEXITSTATUS in the parent This is up to
you but I would advise handling path commands too (like ./script.sh)
Be careful to close all opened file descriptors.  It's usefull to only open
fds in the child process that actually needs them (Where possible)*/