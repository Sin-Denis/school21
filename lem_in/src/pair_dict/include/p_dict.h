/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_dict.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:12:37 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/15 20:00:58 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_DICT_H
# define P_DICT_H

# include "../../Libftprintf/libftprintf.h"
# include "../../dictionary/include/dictionary.h"
# include "../../pair/include/pair.h"
# define DICT_INIT_SIZE 5

typedef struct	s_p_field
{
	t_pair		*key;
	t_status	status;
}				t_p_field;

typedef struct	s_p_dict
{
	t_p_field	*data;
	size_t		size;
	size_t		capacity;
}				t_p_dict;

/* t_field */
void			p_field_init(t_p_field *field, const t_pair *key);
void			p_fields_init(t_p_field *fields, size_t size);
void			p_fields_destroy(t_p_field **data, size_t size);

/* t_dict */
t_p_dict		*p_dict_create(void);
t_p_dict		*p_dict_create_size(int cap);
void			p_dict_destroy(t_p_dict **dict);
void			p_dict_insert(t_p_dict *dict, const t_pair *key);
void			p_dict_delete(t_p_dict *dict, const t_pair *key);
int				p_dict_contains(t_p_dict *dict, const t_pair *key);
size_t			p_hash(const t_pair *key, int m, int k);
void			p_dict_print(t_p_dict *dict);

#endif