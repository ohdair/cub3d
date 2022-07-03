/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:39:18 by juhur             #+#    #+#             */
/*   Updated: 2022/07/03 16:17:16 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util.h"
#include "mlx.h"

static void	init_map_struct(struct s_map *map)
{
	map->map = NULL;
	map->height = 0;
	map->width = 0;
}

void	init_game_struct(t_game *game)
{
	int	i;
	int	j;

	game->mlx.mlx = NULL;
	game->mlx.win = NULL;
	i = -1;
	while (++i < MAX_IMAGE)
	{
		game->wall[i].img = NULL;
		game->wall[i].path = NULL;
		game->wall[i].h = -1;
		game->wall[i].w = -1;
	}
	i = -1;
	while (++i < MAX_BACKGROUND_COLOR)
	{
		j = -1;
		while (++j < MAX_COLOR)
			game->background[i].color[j] = -1;
	}
	init_map_struct(&game->map);
}

static void	set_image_from_xpm(void *mlx, char *path, struct s_image *image)
{
	image->img = mlx_xpm_file_to_image(mlx, path, &(image->w), &(image->h));
	if (image->img == NULL)
		quit_program(STATUS_ERROR_INVALID_MAP);
}

void	init_mlx(t_game *game)
{
	int	i;

	game->mlx.mlx = mlx_init();
	if (game->mlx.mlx == NULL)
		quit_program(STATUS_ERROR_MLX_INIT);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "cub3d");
	if (game->mlx.win == NULL)
		quit_program(STATUS_ERROR_MLX_INIT);
	game->mlx.img = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	if (game->mlx.img == NULL)
		quit_program(STATUS_ERROR_MLX_INIT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &(game->mlx.bpp), &(game->mlx.line_l), &(game->mlx.end));
	if (game->mlx.addr == NULL)
		quit_program(STATUS_ERROR_MLX_INIT);
	i = -1;
	while (++i < MAX_IMAGE)
		set_image_from_xpm(game->mlx.mlx, game->wall[i].path, &game->wall[i]);
}
