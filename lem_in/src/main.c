/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 11:45:00 by jblue-da          #+#    #+#             */
/*   Updated: 2019/08/17 14:34:36 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lem_in.h"

int				main(void)
{
	t_graph		*g;
	t_graph		*new_g;
	t_string 	output_str;
	int 		optimal_num_path;

	g = graph_create();
	if (parse_main(g, &output_str) == -1)
	{
		graph_destroy(&g);
		error_exit("ERROR", &g);
	}
	new_g = get_double_net(g);
	optimal_num_path = analysis(new_g);
	graph_destroy(&new_g);
	if (optimal_num_path == 0)
		error_exit("ERROR", &g);
	new_g = get_double_net(g);
	optimized_solution(new_g, optimal_num_path);
	output(new_g, &output_str);
	graph_destroy(&new_g);
	graph_destroy(&g);
	str_destroy(&output_str);
	return (0);
}
