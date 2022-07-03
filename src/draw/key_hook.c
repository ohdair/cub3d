/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 13:56:14 by juhur             #+#    #+#             */
/*   Updated: 2022/07/03 16:07:54 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "event.h"
#include "mlx.h"

static void	key_esc(t_game *game)
{
	if (game->mlx.win && game->mlx.mlx)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	quit_program(STATUS_OK);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_ESC)
		key_esc(game);
	return (0);
}