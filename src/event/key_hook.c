/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:01:59 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 13:47:46 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "event.h"

int	key_press(int key, t_game *g)
{
	if (key == KEY_ESC)
	{
		destroy_window(g);
		quit_program(STATUS_OK);
	}
	return (0);
}
