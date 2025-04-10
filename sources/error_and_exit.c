/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_and_exit.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/08 12:33:11 by owen          #+#    #+#                 */
/*   Updated: 2025/04/08 12:45:17 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "err_msg.h"
#include <errno.h>

int	exit_error(char *msg, int code)
{
	if (!msg)
		perror("Error");
	else
		ft_putendl_fd(msg, 2);
	exit(code);
}
