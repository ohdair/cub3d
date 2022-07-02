/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:59:45 by juhur             #+#    #+#             */
/*   Updated: 2022/07/02 20:31:42 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	_atoi(const char *num)
{
	int	ret;
	int	sign;

	sign = 1;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			sign = -1;
		++num;
	}
	ret = 0;
	while (*num != '\0')
	{
		if (*num < '0' || '9' < *num)
			quit_program(STATUS_ERROR_INVALID_MAP);
		ret = ret * 10 + *(num++) - '0';
	}
	return (ret * sign);
}
