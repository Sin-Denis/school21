/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_fs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:59:45 by vice-wra          #+#    #+#             */
/*   Updated: 2019/04/30 17:38:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_fs(char **str, t_fs *form_string, va_list *args)
{
	get_fs(str, form_string);
	prepare_item(form_string);
	handler_item(args, form_string, str);
}
