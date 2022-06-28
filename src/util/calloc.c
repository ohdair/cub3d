/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 18:59:01 by juhur             #+#    #+#             */
/*   Updated: 2022/06/28 19:03:36 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"
#include "util.h"

void	*_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ret = malloc(size * count);
	if (ret == NULL)
		quit_program(STATUS_ERROR_ALLOC);
	i = 0;
	while (i < count * size)
	{
		*(unsigned char *)(ret + i) = 0;
		++i;
	}
	return (ret);
}
