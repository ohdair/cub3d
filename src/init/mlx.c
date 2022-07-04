/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:03:52 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 17:29:59 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

#include <stdio.h>
static void	*texture_xpm(t_game *g, char *path)
{
	int		i;
	int		x;
	int		y;
	void	*img;
	char	*adr;

	i = 0;
	while (path[i] == ' ' || path[i] == '\t')
		i++;
	if (path[i] == '.' || path[i] == '/')
	{
		img = mlx_xpm_file_to_image(g->mlx, path + i, &x, &y);
		if (img == NULL || x != 64 || y != 64)
			quit_program(STATUS_ERROR_INVALID_MAP);
		adr = mlx_get_data_addr(img, &x, &y, &i);
		return (adr);
	}
	quit_program(STATUS_ERROR_INVALID_MAP);
	return (NULL);
}

void	init_mlx(t_game *g)
{
	int	i;

	g->mlx = mlx_init();
	i = -1;
	while (++i < MAX_IMAGE)
	{
		if (i == NO)
			g->map.north = texture_xpm(g, g->wall[i].path);
		else if (i == SO)
			g->map.south = texture_xpm(g, g->wall[i].path);
		else if (i == WE)
			g->map.west = texture_xpm(g, g->wall[i].path);
		else if (i == EA)
			g->map.east = texture_xpm(g, g->wall[i].path);
	}
	g->win = mlx_new_window(g->mlx, WIDTH, HEIGHT, "cub3d");
	g->img = mlx_new_image(g->mlx, WIDTH, HEIGHT);
	g->addr = mlx_get_data_addr(g->img, &g->bpp, &g->line_l, &g->end);
}
