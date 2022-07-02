/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhur <juhur@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:25:32 by juhur             #+#    #+#             */
/*   Updated: 2022/07/02 16:02:50 by juhur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <stddef.h>

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

int			_atoi(const char *num);
void		*_calloc(size_t count, size_t size);
void		_free(void **target);
void		_free_double_pointer(void ***target);
char		*get_next_line(int fd);
t_list		*create_list(void *data);
t_list		*get_last_list(t_list *list);
void		add_list_back(t_list **list, t_list *new);
const char	**_split(char *s, char c);
// char	**_split(char *s, char c);
void		remove_all_list(t_list **list);
char		*_strchr(const char *s, int c);
int			_strcmp(const char *s1, const char *s2);
char		*_strdup(const char *s);
char		*_strexpand(char *old, const char *s);
size_t		_strlcat(char *dst, const char *src, size_t dstsize);
size_t		_strlen(const char *s);
int			_strncmp(const char *s1, const char *s2, size_t n);
char		*_strndup(const char *s, size_t n);

#endif
