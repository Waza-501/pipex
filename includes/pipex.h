/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/03 15:55:40 by owhearn       #+#    #+#                 */
/*   Updated: 2025/04/15 12:43:08 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libraries/libft/libft.h"
# include <sys/types.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data
{
	int		pid1;
	int		pid2;
	char	*cmd_1;
	char	**args_1;
	char	*cmd_2;
	char	**args_2;
	char	**paths;
	int		pipefd[2];
}			t_data;


void		child_1(t_data *data, char *file, char **envp);
void		child_2(t_data *data, char *file, char **envp);
t_data		init_data(void);
void		free_data(t_data *data);
int			exit_error(char *msg, int code, t_data *data);

#endif