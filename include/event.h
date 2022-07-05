/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:03:56 by juhur             #+#    #+#             */
/*   Updated: 2022/07/06 08:31:43 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

enum e_mlx_event
{
	KEY_PRESS = 2,
	KEY_RELEASE = 3,
	DESTROY_NOTIFY = 17,
	MAX_EVENT
};

enum e_macos_key_code
{
	KEY_A = 0,
	KEY_S,
	KEY_D,
	KEY_W = 13,
	KEY_ESC = 53,
	KEY_LEFT = 123,
	KEY_RIGHT,
	MAX_KEY
};

struct s_coor
{
	int	y;
	int	x;
};

#endif
