/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 18:34:34 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/14 16:06:41 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*old;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	old = lst;
	new = (*f)(old);
	if (new == NULL)
		return (NULL);
	old = old->next;
	while (old)
	{
		ft_lstpushback(&new, (*f)(old));
		old = old->next;
	}
	return (new);
}
