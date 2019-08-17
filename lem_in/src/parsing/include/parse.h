/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:24:40 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/17 15:58:39 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../../../include/lem_in.h"
# include "../../pair_dict/include/p_dict.h"
# define STATE g_flags[0]
# define LINKS_COUNT g_flags[1]
# define MANDATORY_COMMANDS g_flags[2]
# define IDX g_flags[3]

short	g_toggle;
int		g_flags[4];

int		parse_main(t_graph *graph, t_string *output);
void	error_exit(char *str, t_graph **graph);
void	init_flags_lem(int flags[]);
int		get_size_lem(char **str);
int		get_ants_count(char *line);
int		ft_isnum(char *str);
int		check_each_char(char *line);
int		count_chars(char *str, char c);
int		check_room_name(char *name);
int		check_coors(char *first_coor, char *second_coor);
int		check_line(char *line, t_graph *graph, int links);
int		ft_count_digits(int n);
void	free_string_array(char ***str);
void	parse_rooms_into_graph(t_graph *graph, char *line);
int		parse_into_dict(t_dict *rooms, t_p_dict *coors, char *line, int idx);
int		read_line(char **line, t_graph *graph, t_string *output);
void	parse_line(t_dict *rooms, t_p_dict *coors, t_graph *graph, char *line);
int		parse_links(t_graph *graph, t_dict *rooms,
char *line, int *links_count);
int		check_each_char(char *line);
int		count_chars(char *str, char c);
int		check_room_name(char *name);
int		check_coors(char *first_coor, char *second_coor);
int		check_link(char *line, t_graph *graph);

#endif
