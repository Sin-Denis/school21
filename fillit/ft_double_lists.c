/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 16:10:51 by vice-wra          #+#    #+#             */
/*   Updated: 2019/05/13 12:27:08 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_dpushback(t_dlist **head, t_dlist *elem)
{
	t_dlist *last;

	last = *head;
	elem->next = NULL;
	if (*head == NULL)
	{
		elem->prev = NULL;
		*head = elem;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = elem;
	elem->prev = last;
}

t_dlist		*ft_dlstnew(void *content, size_t content_size)
{
	t_dlist *new_list;

	new_list = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new_list)
		return (NULL);
	if (!content)
	{
		new_list->content = 0;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = malloc(content_size);
		if (!new_list->content)
			return (0);
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}

void		ft_dlstfree(t_dlist **head)
{
	t_dlist *temp;

	temp = NULL;
	while (*head != NULL)
	{
		temp = (*head)->next;
		free((*head)->content);
		free((*head));
		*head = temp;
	}
	head = NULL;
}

int			ft_dlstlen(t_dlist *list)
{
	t_dlist *temp;
	int		i;

	i = 0;
	temp = list;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
