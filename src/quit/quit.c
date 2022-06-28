/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:00:32 by juhur             #+#    #+#             */
/*   Updated: 2022/06/29 11:20:43 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "cub3d.h"
#include "util.h"

int	quit_program(t_error err_no)
{
	const char	*error_msg[STATUS_MAX] = {
		"",
		"Error\n[usage]: ./cub3D <FILE_NAME.cub>\n",
		"Error\n: Cannot file open\n",
		"Error\n: Insufficient memory\n"
	};

	if (err_no != STATUS_OK)
	{
		write(STDOUT_FILENO, error_msg[err_no], _strlen(error_msg[err_no]));
		exit(1);
	}
	exit(0);
}
