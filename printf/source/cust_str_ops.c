/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cust_str_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 14:18:44 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:36:48 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_string		cust_strsub(t_string *str, unsigned int start, size_t len)
{
	t_string	new_str;
	int			i;

	i = 0;
	new_str = str_create_size(len);
	while (i < (int)len && i++ < str->size)
		str_pushchar(&new_str, str_at(str, start++));
	return (new_str);
}

char			*cust_strjoin_left(t_string *s1, char *s2)
{
	char		*new_str;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s1->size || !s2)
		return (0);
	len = ft_strlen(s2);
	new_str = ft_strnew(s1->size + len);
	if (!new_str)
		return (0);
	i = -1;
	j = -1;
	while (++i < (size_t)s1->size)
		*(new_str + i) = str_at(s1, i);
	while (++j < len)
		*(new_str + i++) = *(s2 + j);
	*(new_str + i) = '\0';
	return (new_str);
}

char			*cust_strjoin_right(char *s1, t_string *s2)
{
	char		*new_str;
	size_t		i;
	size_t		j;
	size_t		len;

	if (!s1 || !s2->size)
		return (0);
	len = ft_strlen(s1);
	new_str = ft_strnew(len + s2->size);
	if (!new_str)
		return (0);
	i = -1;
	j = -1;
	while (++i < len)
		*(new_str + i) = *(s1 + i);
	while (++j < (size_t)s2->size)
		*(new_str + i++) = str_at(s2, j);
	*(new_str + i) = '\0';
	return (new_str);
}

char			*cust_strdup(t_string *src)
{
	int			i;
	char		*new_s1;

	if (!src->size)
		return (NULL);
	i = 0;
	if (!(new_s1 = malloc(sizeof(char) * (src->size + 1))))
		return (0);
	while (i < src->size)
	{
		new_s1[i] = str_at(src, i);
		i++;
	}
	new_s1[i] = '\0';
	return (new_s1);
}

char			*cust_strdup_free(t_string *src)
{
	int			i;
	char		*new_s1;

	if (!src->size)
		return (NULL);
	i = 0;
	if (!(new_s1 = malloc(sizeof(char) * (src->size + 1))))
		return (0);
	while (i < src->size)
	{
		new_s1[i] = str_at(src, i);
		i++;
	}
	new_s1[i] = '\0';
	str_destroy(src);
	return (new_s1);
}
