/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:00:09 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:26:11 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*str;

	str = (*alst);
	while (str != NULL)
	{
		(*del)(str->content, str->content_size);
		free(str);
		str = str->next;
	}
	(*alst) = NULL;
}
