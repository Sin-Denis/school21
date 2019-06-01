/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sindenis <sindenis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:08:18 by nparker           #+#    #+#             */
/*   Updated: 2019/05/13 12:27:07 by sindenis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct			s_sharp
{
	int					x;
	int					y;
}						t_sharp;

typedef struct			s_figure
{
	t_sharp				figure[4];
	char				letter;
	int					with;
	int					high;
}						t_fig;

typedef struct			s_map
{
	int					**arr;
	t_list				*sec_st;
	int					size;
}						t_map;

typedef struct			s_fig_list
{
	struct s_figure		content;
	size_t				content_size;
	struct s_fig_list	*next;
}						t_fig_list;

typedef struct			s_dlist
{
	void				*content;
	size_t				content_size;
	struct s_dlist		*next;
	struct s_dlist		*prev;
}						t_dlist;

int						ft_read_tet(int file, t_dlist **head);
char					ft_check_neighb(char *str, int i);
int						ft_check_cube(char *str);
int						ft_check_tet(char *str);
int						ft_main_check(char *str);
t_fig					*ft_find_fig(char *str, t_fig *fig);
int						ft_width(t_fig *fig);
int						ft_high(t_fig *fig);
int						ft_putcheck(t_fig *fig, t_map *field);
void					ft_plus_field(t_map *field);
int						ft_dep_x(t_fig *fig, t_map *field);
int						ft_dep_y(t_fig *fig, t_map *field);
void					ft_putfig(t_fig *fig, t_map *field);
int						ft_intersection(t_map *field);
int						ft_rec_fillit(t_map *field,
t_list **figs, int take_fig);
t_map					fillit(t_dlist *fig_list);
t_dlist					*ft_dlstnew(void *content, size_t content_size);
void					ft_dpushback(t_dlist **head, t_dlist *elem);
void					ft_print_map(t_map field);
void					ft_letter(t_fig *fig, t_map *field);
void					ft_clear_fig(t_fig *fig, t_map *field);
void					ft_arrnew(t_map *field);
void					ft_arrclear(t_map *field);
int						ft_max_x(t_fig *fig);
int						ft_max_y(t_fig *fig);
int						ft_is_it_full(t_map *field);
void					ft_step_back(t_dlist **fig_list, t_map *field);
int						ft_process_fig(t_dlist **fig_list, t_map *field);
int						ft_rec_new(t_dlist **fig_list, t_map *field);
int						ft_end(t_fig *fig, t_map *field);
void					ft_free_map(t_map *field);
void					ft_dlstfree(t_dlist **head);
int						ft_dlstlen(t_dlist *list);
int						ft_get_size(t_dlist *list);

#endif
