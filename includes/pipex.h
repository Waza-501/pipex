/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owhearn <owhearn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/03 15:55:40 by owhearn       #+#    #+#                 */
/*   Updated: 2025/04/07 16:46:16 by owhearn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libraries/libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>

# define X_INPUT	"Error. Wrong input was given."

typedef struct s_data
{
	int		fd1;
	int		fd2;
	int		pid1;
	int		pid2;

}			t_data;


#endif