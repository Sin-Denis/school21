/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 21:43:32 by sindenis          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:14 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_size(char **str)
{
	int		states[3];
	char	*size;

	size = NULL;
	arr_zero(states, 3);
	while (**str && (**str == 'l' || **str == 'h' || **str == 'L'))
	{
		if (**str == 'l' && states[0]++ < 2)
			ft_strpush(&size, **str);
		else if (**str == 'h' && states[1]++ < 2)
			ft_strpush(&size, **str);
		else if (**str == 'L' && states[2]++ < 1)
			ft_strpush(&size, **str);
		move_char_pointer(str);
	}
	return (size);
}
