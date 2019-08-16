/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/16 23:14:05 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				main(void)
{
	// int			num_roads;
	t_graph		*g;
	t_graph		*new_g;
	// t_vector	**roads;
	// t_vector	*distribution;
	t_string 	output_str;
	// int i;

	// i = 0;
	g = graph_create();
	if (parse_main(g, &output_str) == -1)
	{
		graph_destroy(&g);
		error_exit("ERROR MAIN");
	}
	graph_print(g);
	ft_printf("\n");
	new_g = get_double_net(g);
	graph_print(new_g);
	int a = analysis(new_g);
	graph_destroy(&new_g);
	if (a == 0)
		error_exit("ERROR");
	// num_roads = get_num_roads(g);
	// ft_printf("%d", num_roads);
	// roads = get_all_roads(g, num_roads);
	// ft_printf("%d\n", a);
	// for (int i = 0; roads[i] != NULL; ++i) {
	// 	vector_print(roads[i]);
	// 	ft_printf("\n");
	// }
	// distribution = get_distribution(roads, g->num_ants, num_roads);
	// str_print(&output_str);
	// str_destroy(&output_str);
	// output(g, roads, distribution, num_roads);
	// vector_destroy(&distribution);
	// while (i < num_roads)
	// 	vector_destroy(&roads[i++]);
	// free(roads);
	graph_destroy(&g);

	return (0);
}
