/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/03 15:55:18 by owhearn       #+#    #+#                 */
/*   Updated: 2025/04/07 16:54:23 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_input(t_data data, char **argv, char **envp)
{
	data.fd1 = open(argv[1], O_RDONLY);
	data.fd2 = open(argv[4], O_RDONLY);
	if (data.fd1 == -1 || data.fd2 == -1)
		error_exit("haha funny can't open file");
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	mario;
	pid_t	luigi;
	t_data	data;

	if (argc != 5)
	{
		ft_putendl_fd("Error. Expected: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(-1);
	}
	parse_input(data, argv, envp);
	return (0);
}

/*some notes
When the command its not found, return 127 When the command is found, but not
executable, return 126 Remember to call WEXITSTATUS in the parent This is up to
you but I would advise handling path commands too (like ./script.sh)
Be careful to close all opened file descriptors.  It's usefull to only open
fds in the child process that actually needs them (Where possible)*/