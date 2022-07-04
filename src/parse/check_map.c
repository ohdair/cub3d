/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:09:23 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 19:58:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "check_map.h"

static bool	check_player(const char **map, int height, int width)
{
	bool	player;
	t_coor	coor;

	player = false;
	coor.y = -1;
	while (++coor.y < height)
	{
		coor.x = -1;
		while (++coor.x < width)
		{
			if (_strchr("NEWS", map[coor.y][coor.x]) == NULL)
				continue ;
			if (player)
				return (false);
			player = true;
		}
	}
	return (true);
}

static void	dfs(const char **map, int height, int width, t_coor cur, bool **visited)
{
	const int	dy[4] = {-1, 0, 1, 0};
	const int	dx[4] = {0, 1, 0, -1};
	t_coor		next;
	int			k;

	if (cur.y == 0 || cur.x == 0 || cur.y == height - 1 || cur.x == width - 1)
		quit_program(STATUS_ERROR_INVALID_MAP);
	visited[cur.y][cur.x] = true;
	k = -1;
	while (++k < 4)
	{
		next.y = cur.y + dy[k];
		next.x = cur.x + dx[k];
		if (next.y < 0 || next.y < 0 || next.y >= height || next.x >= width)
			continue ;
		if (map[next.y][next.x] == '1' || visited[next.y][next.x])
			continue ;
		if (map[next.y][next.x] == ' ')
			quit_program(STATUS_ERROR_INVALID_MAP);
		if (map[next.y][next.x] == '0')
			dfs(map, height, width, next, visited);
	}
}

bool	check_map(const char **map, int height, int width)
{
	t_coor	coor;
	bool	**visited;

	if (!check_player(map, height, width))
		quit_program(STATUS_ERROR_INVALID_MAP);
	visited = _calloc(height + 1, sizeof(bool *));
	coor.y = -1;
	while (++coor.y < height)
		visited[coor.y] = _calloc(width + 1, sizeof(bool));
	coor.y = -1;
	while (++coor.y < height)
	{
		coor.x = -1;
		while (++coor.x < width)
		{
			if (_strchr(" 01NEWS", map[coor.y][coor.x]) == NULL)
				quit_program(STATUS_ERROR_INVALID_MAP);
			else if (map[coor.y][coor.x] == '0' && !visited[coor.y][coor.x])
				dfs(map, height, width, coor, visited);
		}
	}
	_free_double_pointer((void ***)&visited);
	return (true);
}
