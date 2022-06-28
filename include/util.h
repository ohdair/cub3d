/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:32 by juhur             #+#    #+#             */
/*   Updated: 2022/06/28 19:37:38 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>

void	*_calloc(size_t count, size_t size);
void	_free(void **target);
int		_strcmp(const char *s1, const char *s2);
char	*_strdup(const char *s);
char	*_strexpand(char *old, const char *s);
size_t	_strlcat(char *dst, const char *src, size_t dstsize);
size_t	_strlen(const char *s);

#endif
