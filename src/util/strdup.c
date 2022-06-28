/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:02:32 by juhur             #+#    #+#             */
/*   Updated: 2022/06/28 19:37:32 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*_strdup(const char *s)
{
	char	*new;
	char	*ptr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = _strlen(s);
	new = _calloc(s_len + 1, sizeof(char));
	ptr = new;
	while (s_len--)
		*(ptr++) = *(s++);
	return (new);
}
