/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 17:56:10 by vice-wra          #+#    #+#             */
/*   Updated: 2019/08/06 14:12:31 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/lem_in.h"

int main()
{
	char *str = "hey-yo";
	


	t_dict *dict = dict_create();

	dict_insert(dict, "hey", 0);
	dict_insert(dict, "hey sup", 1);
	dict_insert(dict, "hey tho", 2);
	dict_insert(dict, "hey how's it goin", 3);
}