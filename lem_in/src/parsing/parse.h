/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:24:40 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/07 16:02:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_main(t_graph *graph);
void error_exit(char *str);
void init_flags_lem(int flags[]);
int get_size_lem(char **str);
int get_ants_count();
int				ft_isnum(char *str);
int check_each_char(char *line);
int count_chars(char *str, char c);
int check_room_name(char *name);
int check_coors(char *first_coor, char *second_coor);
int check_line(char *line);
int		ft_count_digits(int n);
void free_string_array(char ***str);