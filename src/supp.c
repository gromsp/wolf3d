/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:21:49 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/12 20:05:52 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

char	checker(double x, double y, t_map *map)
{
	char s;
	
	if (map->map[(int)(x + 0.01) + ((int)y * map->widht_m)] == 0)
		s = 'e';
	if (map->map[(int)(x - 0.01) + ((int)y * map->widht_m)] == 0)
		s = 'w';
	if (map->map[(int)x + ((int)(y + 0.01) * map->widht_m)] == 0)
		s = 's';
	if (map->map[(int)x + ((int)(y - 0.01) * map->widht_m)] == 0)
		s = 'n';
	return (s);
}
