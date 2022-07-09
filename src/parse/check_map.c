/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:09:23 by juhur             #+#    #+#             */
/*   Updated: 2022/07/09 15:15:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "check_map.h"

static bool	check_player(struct s_map *map)
{
	bool	player;
	t_coor	cur;

	player = false;
	cur.y = -1;
	while (++cur.y < map->height)
	{
		cur.x = -1;
		while (++cur.x < map->width)
		{
			if (_strchr("NEWS", map->map[cur.y][cur.x]) == NULL)
				continue ;
			if (player)
				return (false);
			player = true;
		}
	}
	if (!player)
		return (false);
	return (true);
}

static void	dfs(struct s_map *map, t_coor cur, bool **visited)
{
	const int	dy[MAX_DIR] = {-1, 1, 0, 0};
	const int	dx[MAX_DIR] = {0, 0, -1, 1};
	t_coor		next;
	int			k;

	if (cur.y == 0 || cur.y == map->height - 1)
		quit_program(STATUS_ERROR_INVALID_MAP);
	if (cur.x == 0 || cur.x == map->width - 1)
		quit_program(STATUS_ERROR_INVALID_MAP);
	visited[cur.y][cur.x] = true;
	k = -1;
	while (++k < MAX_DIR)
	{
		next.y = cur.y + dy[k];
		next.x = cur.x + dx[k];
		if (map->map[next.y][next.x] == '1' || visited[next.y][next.x])
			continue ;
		if (map->map[next.y][next.x] == ' ')
			quit_program(STATUS_ERROR_INVALID_MAP);
		if (map->map[next.y][next.x] == '0')
			dfs(map, next, visited);
	}
}

bool	check_map(struct s_map *map)
{
	t_coor	cur;
	bool	**visited;

	if (!check_player(map))
		quit_program(STATUS_ERROR_INVALID_MAP);
	visited = _calloc(map->height + 1, sizeof(bool *));
	cur.y = -1;
	while (++cur.y < map->height)
		visited[cur.y] = _calloc(map->width + 1, sizeof(bool));
	cur.y = -1;
	while (++cur.y < map->height)
	{
		cur.x = -1;
		while (++cur.x < map->width)
		{
			if (_strchr(" 01NEWS", map->map[cur.y][cur.x]) == NULL)
				quit_program(STATUS_ERROR_INVALID_MAP);
			else if (map->map[cur.y][cur.x] == '0' && !visited[cur.y][cur.x])
				dfs(map, cur, visited);
		}
	}
	_free_double_pointer((void ***)&visited);
	return (true);
}
