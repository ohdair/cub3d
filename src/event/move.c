/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:45:19 by juhur             #+#    #+#             */
/*   Updated: 2022/07/06 08:31:54 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "event.h"

static void	key_a(char **map, struct s_point *pos, struct s_point *plane)
{
	const struct s_coor	nx = {pos->y, pos->x - plane->x * SM};
	const struct s_coor	ny = {pos->y - plane->y * SM, pos->x};

	if (map[nx.y][nx.x] != '0' || map[ny.y][ny.x] != '0')
		return ;
	pos->x -= plane->x * SM;
	pos->y -= plane->y * SM;
}

static void	key_d(char **map, struct s_point *pos, struct s_point *plane)
{
	const struct s_coor	nx = {pos->y, pos->x + plane->x * SM};
	const struct s_coor	ny = {pos->y + plane->y * SM, pos->x};

	if (map[nx.y][nx.x] != '0' || map[ny.y][ny.x] != '0')
		return ;
	pos->x += plane->x * SM;
	pos->y += plane->y * SM;
}

static void	key_w(char **map, struct s_player *p)
{
	const struct s_coor	nx = {p->pos.y, p->pos.x + p->dir.x * SM};
	const struct s_coor	ny = {p->pos.y + p->dir.y * SM, p->pos.x};

	if (map[nx.y][nx.x] != '0' || map[ny.y][ny.x] != '0')
		return ;
	p->pos.x += p->dir.x * SM;
	p->pos.y += p->dir.y * SM;
}

static void	key_s(char **map, struct s_player *p)
{
	const struct s_coor	nx = {p->pos.y, p->pos.x - p->dir.x * SM};
	const struct s_coor	ny = {p->pos.y - p->dir.y * SM, p->pos.x};

	if (map[nx.y][nx.x] != '0' || map[ny.y][ny.x] != '0')
		return ;
	p->pos.x -= p->dir.x * SM;
	p->pos.y -= p->dir.y * SM;
}

void	move(int key, t_game *g)
{
	if (key == KEY_W)
		key_w(g->map.map, &g->player);
	else if (key == KEY_S)
		key_s(g->map.map, &g->player);
	else if (key == KEY_A)
		key_a(g->map.map, &g->player.pos, &g->ray.plane);
	else if (key == KEY_D)
		key_d(g->map.map, &g->player.pos, &g->ray.plane);
}
