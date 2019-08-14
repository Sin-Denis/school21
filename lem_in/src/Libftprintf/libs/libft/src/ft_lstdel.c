/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:52:58 by jblue-da          #+#    #+#             */
/*   Updated: 2018/12/13 17:27:25 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst == NULL)
		return ;
	while (*alst != NULL)
	{
		tmp = *alst;
		(*alst) = (*alst)->next;
		ft_lstdelone(&tmp, del);
	}
}
