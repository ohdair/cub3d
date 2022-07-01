/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strndup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:24:18 by juhur             #+#    #+#             */
/*   Updated: 2022/07/01 13:27:10 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*_strndup(const char *s, size_t n)
{
	char	*new;
	size_t	s_len;

	s_len = _strlen(s);
	if (n < s_len)
		s_len = n;
	new = _calloc(s_len + 1, sizeof(char));
	*new = '\0';
	_strlcat(new, s, s_len + 1);
	return (new);
}
