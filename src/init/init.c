/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:39:18 by juhur             #+#    #+#             */
/*   Updated: 2022/06/29 10:46:00 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "cub3d.h"
#include "util.h"

static bool	read_data(const int fd, char **map_raw_data)
{
	char	buffer[1000000];
	ssize_t	len;

	*map_raw_data = NULL;
	while (1)
	{
		len = read(fd, buffer, 1000000);
		if (len <= 0)
			break ;
		*map_raw_data = _strexpand(*map_raw_data, buffer);
	}
	if (len == -1)
		return (false);
	return (true);
}

void	init(const char *file_name, t_game *g)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		quit_program(STATUS_ERROR_FILE_OPEN);
	if (!read_data(fd, &g->map_raw_data))
	{
		close(fd);
		quit_program(STATUS_ERROR_FILE_OPEN);
	}
	close(fd);
}
