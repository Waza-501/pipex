/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: owen <owen@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/10 17:27:48 by owen          #+#    #+#                 */
/*   Updated: 2025/04/14 14:13:01 by owen          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "err_msg.h"

t_data	init_data(void)
{
	t_data ret;

	ret.cmd_1 = NULL;
	ret.args_1 = NULL;
	ret.cmd_2 = NULL;
	ret.args_2 = NULL;
	ret.paths = NULL;
	return (ret);
}
