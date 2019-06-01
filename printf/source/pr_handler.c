/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:40:32 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:25 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pr_handler(t_fs *form_string, char **format)
{
	char	*temp;

	temp = ft_strnew(1);
	*temp = '%';
	width_insert(form_string, &temp);
	*format = temp;
}
