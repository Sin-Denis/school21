/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:12:37 by jblue-da          #+#    #+#             */
/*   Updated: 2019/07/30 15:32:30 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "../../Libftprintf/libftprintf.h"
#define DICT_INIT_SIZE 5

typedef enum		e_status
{
	BLANK = 0,
	DELETE = 1,
	EXIST = 2
}					t_status;

typedef struct	s_field
{
	char		*key;
	int			val;
	t_status	status;
}				t_field;

typedef struct	s_dict
{
	t_field		*data;
	size_t		size;
	size_t		capacity;
}				t_dict;

/* t_field */
void			field_init(t_field *field, const char *key, int val);
void			fields_init(t_field *fields, size_t size);
void			fields_destroy(t_field **data, size_t size);

/* t_dict */
t_dict			*dict_create(void);
void			dict_destroy(t_dict **dict);
void			dict_insert(t_dict *dict, const char *key, int val);
void			dict_delete(t_dict *dict, const char *key);
int				dict_at(t_dict *dict, const char *key);
size_t			hash(const char *key, int m, int k);
void			dict_print(t_dict *dict);

#endif