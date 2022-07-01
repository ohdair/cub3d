/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:03:42 by juhur             #+#    #+#             */
/*   Updated: 2022/07/01 14:46:31 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "cub3d.h"

static bool	raw_data_to_list(const int fd, t_list **map_raw_data)
{
	char	*line;

	*map_raw_data = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		return (false);
	while (line != NULL)
	{
		add_list_back(map_raw_data, create_list(line));
		line = get_next_line(fd);
	}
	return (true);
}

bool	read_raw_data(t_list **map_raw_data, const char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (false);
	raw_data_to_list(fd, map_raw_data);
	return (true);
}