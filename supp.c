/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:21:49 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/18 21:11:46 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>
#include <math.h>

char	checker(double x, double y, int **tiles)
{
	char s = ' ';

	// printf("%f %f | ", x, y);
	if ((x - (int)x) == 0)
	{
		if ((y - (int)y) == 0)
			s = 'w';
		else
			s = 'e';
	}
	else
		if ((y - (int)y) == 0)
			s = 'n';
		else
			s = 's';
	return (s);
}

// char	checker(double x, double y, int **tiles)
// {
// 	char s;
//
// 	if (tiles[(int)(x + 0.01) + ((int)y * WIN_WIDTH)] == 0)
// 		s = 'e';
// 	if (tiles[(int)(x - 0.01) + ((int)y * WIN_WIDTH)] == 0)
// 		s = 'w';
// 	if (tiles[(int)x + ((int)(y + 0.01) * WIN_WIDTH)] == 0)
// 		s = 's';
// 	if (tiles[(int)x + ((int)(y - 0.01) * WIN_WIDTH)] == 0)
// 		s = 'n';
// 	return (s);
// }
