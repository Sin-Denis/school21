/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 12:57:47 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 17:38:18 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handler_item(va_list *args, t_fs *form_string, char **format)
{
	if (form_string->type == 'd')
		d_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'i')
		d_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'o')
		o_handler(form_string, va_arg(*args, unsigned long long), format);
	else if (form_string->type == 'u')
		u_handler(form_string, va_arg(*args, unsigned long long), format);
	else if (form_string->type == 'x')
		x_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'X')
		x_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == 'f')
		if (ft_strchr(form_string->size, 'L'))
			lf_handler(form_string, va_arg(*args, long double), format);
		else
			f_handler(form_string, va_arg(*args, double), format);
	else if (form_string->type == 'c')
		c_handler(form_string, va_arg(*args, int), format);
	else if (form_string->type == 's')
		s_handler(form_string, va_arg(*args, char *), format);
	else if (form_string->type == 'p')
		p_handler(form_string, va_arg(*args, long long), format);
	else if (form_string->type == '%')
		pr_handler(form_string, format);
}

void		handler(va_list *args, t_fs_vector *form_strings, char **format)
{
	int		i;

	i = -1;
	while (++i < fs_vector_length(form_strings))
		handler_item(args, &form_strings->data[i], format);
}
