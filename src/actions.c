/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:59 by jsteuber          #+#    #+#             */
/*   Updated: 2019/06/21 21:19:33 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "wolf.h"

// int			mouse_move(int x, int y, t_win *cr)
// {
// 	char	d;
//
// 	if ((x - cr->x_mem) == 0)
// 		return (0);
// 	d = (x - cr->x_mem) > 0 ? 'R' : 'L';
// 	cr->rotation = (double)(x - cr->x_mem) / WIN_WIDTH;
// 	printf("%f\n", x - cr->x_mem);
// 	cr->x_mem = x;
// 	transform(cr, &(cr->dir.x), &(cr->dir.y), 'L');
// 	transform(cr, &(cr->plane.x), &(cr->plane.y), 'L');
// 	visual(cr);
// 	return (0);
// }

int			key_action(int keycode, t_win *cr)
{
	double	tmp_p_x;
	double	tmp_p_y;

	tmp_p_x = cr->player.x;
	tmp_p_y = cr->player.y;
	if (keycode == 53)
		exit(0);
	else if (keycode == 0)
	{
		tmp_p_x += cr->plane.x / cr->plane.len * SPEED;
		tmp_p_y += cr->plane.y / cr->plane.len * SPEED;
	}
	else if (keycode == 2)
	{
		tmp_p_x -= cr->plane.x / cr->plane.len * SPEED;
		tmp_p_y -= cr->plane.y / cr->plane.len * SPEED;
	}
	else if (keycode == 13)
	{
		tmp_p_x += cr->dir.x / cr->dir.len * SPEED;
		tmp_p_y += cr->dir.y / cr->dir.len * SPEED;
	}
	else if (keycode == 1)
	{
		tmp_p_x -= cr->dir.x / cr->dir.len * SPEED;
		tmp_p_y -= cr->dir.y / cr->dir.len * SPEED;
	}
	else if (keycode == 12)
	{
		transform(cr, &(cr->dir.x), &(cr->dir.y), 'L');
		transform(cr, &(cr->plane.x), &(cr->plane.y), 'L');
	}
	else if (keycode == 14)
	{
		transform(cr, &(cr->dir.x), &(cr->dir.y), 'R');
		transform(cr, &(cr->plane.x), &(cr->plane.y), 'R');
	}
	//
	if ((checker(cr, tmp_p_x, tmp_p_y, cr->tiles)) != ' ')
	{
		cr->player.x = tmp_p_x;
		cr->player.y = tmp_p_y;
	}
	visual(cr);
	return (0);
}
