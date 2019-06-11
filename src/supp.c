/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:21:49 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/08 21:02:33 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

char	checker(double x, double y, t_map *map)
{
	char s;
	
	if (map->map[(int)(x + 0.001 * 2) + ((int)y * map->height_m)] == 0)
		s = 'e';
	if (map->map[(int)(x - 0.001 * 2) + ((int)y * map->height_m)] == 0)
		s = 'w';
	if (map->map[(int)x + ((int)(y + 0.001) * map->height_m)] == 0)
		s = 's';
	if (map->map[(int)x + ((int)(y - 0.001) * map->height_m)] == 0)
		s = 'n';
	return (s);
}
