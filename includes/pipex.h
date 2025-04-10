/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/03 15:55:40 by owhearn       #+#    #+#                 */
/*   Updated: 2025/04/09 14:11:27 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libraries/libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	int		fd1;
	int		fd2;
	int		pid1;
	int		pid2;
	int		pipefd[2];
}			t_data;

int		exit_error(char *msg, int code);

#endif