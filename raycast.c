/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:20 by jsteuber          #+#    #+#             */
/*   Updated: 2019/06/15 20:28:17 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include "wolf.h"
#include <stdio.h>
#include <math.h>

void	make_cast(t_win *cr)
{
	int		rcurr;

	cr->rcurr = 0;
	rcurr = 0;
	cr->rays = WIN_WIDTH / 2;
	rcurr = -cr->rays;
	while (rcurr <= cr->rays)
	{
		cr->castx = cr->dir.x + (cr->plane.x / cr->rays * rcurr);
		cr->casty = cr->dir.y + (cr->plane.y / cr->rays * rcurr);
		dda(cr);
		calc_line(cr);
		// draw(cr, cr->rcurr);
		cr->trash += WIN_WIDTH / cr->rays / 2;
		rcurr++;
		cr->rcurr++;
	}
	cr->trash = 0;
}

// int		wall_check(t_win *cr, double x, double y)
// {
// 	int	res;
//
// 	return (0);
// }
