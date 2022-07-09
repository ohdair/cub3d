/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:01:59 by juhur             #+#    #+#             */
/*   Updated: 2022/07/09 13:53:05 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "event.h"

static void	key_hook_lr(int key, struct s_point *dir, struct s_point *plane)
{
	if (key == KEY_LEFT)
	{
		dir->y = dir->x * sin(-ROTATE_UNIT) + dir->y * cos(-ROTATE_UNIT);
		dir->x = dir->x * cos(-ROTATE_UNIT) - dir->y * sin(-ROTATE_UNIT);
		plane->y = plane->x * sin(-ROTATE_UNIT) + plane->y * cos(-ROTATE_UNIT);
		plane->x = plane->x * cos(-ROTATE_UNIT) - plane->y * sin(-ROTATE_UNIT);
	}
	if (key == KEY_RIGHT)
	{
		dir->y = dir->x * sin(ROTATE_UNIT) + dir->y * cos(ROTATE_UNIT);
		dir->x = dir->x * cos(ROTATE_UNIT) - dir->y * sin(ROTATE_UNIT);
		plane->y = plane->x * sin(ROTATE_UNIT) + plane->y * cos(ROTATE_UNIT);
		plane->x = plane->x * cos(ROTATE_UNIT) - plane->y * sin(ROTATE_UNIT);
	}
}

int	key_press(int key, t_game *g)
{
	if (key == KEY_ESC)
	{
		destroy_window(g);
		quit_program(STATUS_OK);
	}
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move(key, g);
	else if (key == KEY_LEFT || key == KEY_RIGHT)
		key_hook_lr(key, &g->player.dir, &g->ray.plane);
	return (0);
}
