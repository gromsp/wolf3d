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

int		main(int ac, char **av)
{
	t_map *map;
	
	if (ac != 2)
	{
		write(1, "Need map file: .map\n", 20);
		return(-2);
	}
	map = parser(av[1], map);
	render(map);
	return (0);
}
