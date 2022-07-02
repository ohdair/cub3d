/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:09:23 by juhur             #+#    #+#             */
/*   Updated: 2022/07/03 11:05:26 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_player(struct s_map map)
{
	bool	player;
	int		i;
	int		j;

	player = false;
	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			if (_strchr("NEWS", map.map[i][j]) == NULL)
				continue ;
			if (player)
				return (false);
			player = true;
		}
	}
	return (true);
}

static void	dfs(struct s_map *map, int y, int x)
{
	const int	dy[4] = {-1, 0, 1, 0};
	const int	dx[4] = {0, 1, 0, -1};
	int			ny;
	int			nx;
	int			k;

	if (y == 0 || x == 0 || y == map->height - 1 || x == map->width - 1)
		quit_program(STATUS_ERROR_INVALID_MAP);
	map->map[y][x] = '1';
	k = -1;
	while (++k < 4)
	{
		ny = y + dy[k];
		nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= map->height || nx >= map->width)
			continue ;
		if (map->map[ny][nx] == '1')
			continue ;
		if (map->map[ny][nx] == ' ')
			quit_program(STATUS_ERROR_INVALID_MAP);
		if (map->map[ny][nx] == '0')
			dfs(map, ny, nx);
	}
}

bool	check_map(struct s_map map)
{
	int	i;
	int	j;

	if (!check_player(map))
		quit_program(STATUS_ERROR_INVALID_MAP);
	i = -1;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			if (_strchr(" 01NEWS", map.map[i][j]) == NULL)
				quit_program(STATUS_ERROR_INVALID_MAP);
			else if (map.map[i][j] == '0')
				dfs(&map, i, j);
		}
	}
	return (true);
}
