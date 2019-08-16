/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:24:40 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/15 21:50:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "../../../include/lem_in.h"

typedef struct		s_string
{
	char			*data;
	int				size;
	int				capacity;
}					t_string;


int	parse_main(t_graph *graph, t_string *output);
void error_exit(char *str);
void init_flags_lem(int flags[]);
int get_size_lem(char **str);
int get_ants_count(char *line);
int				ft_isnum(char *str);
int check_each_char(char *line);
int count_chars(char *str, char c);
int check_room_name(char *name);
int check_coors(char *first_coor, char *second_coor);
int check_line(char *line, t_graph *graph, int links);
int		ft_count_digits(int n);
void free_string_array(char ***str);

/*
**t_string function
*/

t_string			str_create_custstr(t_string *cs);
t_string			str_create_str(char *s);
t_string			str_create_size(int size);
void				str_resize(t_string *s, int new_size);
void				str_pushchar(t_string *s, char c);
void				str_pushstr(t_string *s, char *str);
int					str_len(t_string *s);
void				str_destroy(t_string *s);
void				str_print(t_string *s);
void				str_rev(t_string *s);
char				str_at(t_string *s, int idx);
t_string			str_custjoin(t_string *l, t_string *r);
t_string			str_cut(t_string *str, int start, int end);
int					str_len(t_string *s);
void				str_print(t_string *s);
void				str_push_cs(t_string *l, t_string *r);
char				*to_cstr(t_string *str);

#endif