/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:35:29 by nparker           #+#    #+#             */
/*   Updated: 2019/04/30 18:37:37 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		get_queue(char *format, t_queue *queue)
{
	char	*str;
	int		i;

	while (format && ft_strchr(format, '%'))
	{
		str = ft_strsub(format, 0, ft_strchr(format, '%') - format);
		if (*str)
			queue_push(queue, str);
		ft_strdel(&str);
		format = ft_strchr(format, '%');
		i = find_the_flags(&format);
		str = ft_strsub(format, 0, i + 1);
		queue_push(queue, str);
		ft_strdel(&str);
		if (format[i])
			format = format + i + 1;
		else
			format = format + i;
	}
	i = ft_strchr(format, '\0') - format;
	str = ft_strsub(format, 0, i);
	queue_push(queue, str);
	ft_strdel(&str);
}

void		put_into_cust_str(t_fs *form_string, t_string *cust_str, char *str)
{
	if (str)
	{
		if (form_string->type == 'c' &&
				g_crutch == 1)
		{
			if (!ft_strchr(form_string->flags, '-'))
			{
				str_pushstr(cust_str, str);
				str_pushchar(cust_str, '\0');
			}
			else
			{
				str_pushchar(cust_str, '\0');
				str_pushstr(cust_str, str);
			}
		}
		else
			str_pushstr(cust_str, str);
	}
}

void		decide(t_queue *q, t_string *cust_str, va_list *args)
{
	char	*str;
	t_fs	form_string;

	fs_init(&form_string);
	while (q->size)
	{
		if (!ft_strchr(str = queue_pop(q), '%'))
			str_pushstr(cust_str, str);
		else
		{
			move_char_pointer(&str);
			process_fs(&str, &form_string, args);
			put_into_cust_str(&form_string, cust_str, str);
			fs_destroy(&form_string);
		}
		ft_strdel(&str);
	}
}

int			ft_printf(char *format, ...)
{
	va_list			args;
	t_string		str;
	t_queue			queue;

	if (!format || *format == '\0' || (ft_strlen(format) == 1 &&
												*format == '%'))
		return (0);
	va_start(args, format);
	queue_create(&queue);
	get_queue(format, &queue);
	str = str_create_size(ft_strlen(queue.tail->data));
	decide(&queue, &str, &args);
	write(1, str.data, str.size);
	ft_strdel(&str.data);
	return ((int)str.size);
}
