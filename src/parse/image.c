/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:35:36 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 20:39:40 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "cub3d.h"

static void	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		quit_program(STATUS_ERROR_INVALID_MAP);
	close(fd);
}

static char	*get_path(const char **ss)
{
	char	*path;
	int		i;
	int		len;

	len = 1;
	while (ss[len] != NULL)
		++len;
	path = NULL;
	i = 0;
	while (++i < len)
	{
		path = _strexpand(path, ss[i]);
		if (i < len - 1)
			path = _strexpand(path, " ");
	}
	return (path);
}

bool	set_image(t_game *g, char *data)
{
	const char	*direction[MAX_DIR] = {"NO", "SO", "WE", "EA"};
	const char	**ss = _split(data, ' ');
	int			i;

	i = -1;
	while (++i < MAX_DIR)
	{
		if (ss[0] == NULL)
			break ;
		if (!_strcmp(ss[0], direction[i]))
		{
			if (g->wall[i].path != NULL)
				quit_program(STATUS_ERROR_INVALID_MAP);
			g->wall[i].path = get_path(ss);
			check_path(g->wall[i].path);
			_free_double_pointer((void ***)&ss);
			return (true);
		}
	}
	_free_double_pointer((void ***)&ss);
	return (false);
}
