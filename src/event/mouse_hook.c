/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:20:43 by juhur             #+#    #+#             */
/*   Updated: 2022/07/04 13:47:54 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "event.h"

int	mouse_hook(t_game *g)
{
	destroy_window(g);
	quit_program(STATUS_OK);
	return (0);
}
