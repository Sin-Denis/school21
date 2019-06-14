/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:14:52 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/14 15:25:04 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	arr_len(char const *s, char c)
{
	int			i;
	size_t		len;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		++i;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		++i;
	}
	return (len);
}

static size_t	len_str(char *s, char c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			return (i + 1);
		++i;
	}
	return (i);
}

static void		clean_arr(char **arr, int len_elems)
{
	while (len_elems >= 0)
	{
		free(arr[len_elems]);
		arr[len_elems] = NULL;
		--len_elems;
	}
	free(arr);
	arr = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		len;
	char		*tmp;
	char		**arr;
	int			i;
	size_t		j;

	if (s == NULL)
		return (NULL);
	tmp = (char *)s;
	i = 0;
	j = 0;
	len = arr_len(s, c);
	arr = (char **)malloc(sizeof(char *) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (j++ < len)
	{
		while (*tmp && *tmp == c)
			tmp++;
		if ((arr[i++] = ft_strsub(tmp, 0, len_str(tmp, c))) == NULL)
			clean_arr(arr, i - 1);
		tmp += len_str(tmp, c);
	}
	arr[len] = NULL;
	return (arr);
}
