/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:12:24 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/25 19:44:17 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "wolf.h"
#include <stdio.h>
#include "mlx.h"


static int		colors(t_win *cr, int i, double column)
{
	int tx;
	double	ty;
	double	x;
	int t;
	int c;


	if (cr->wall == 'n')
		cr->objcl = 0xff0000;
	else if (cr->wall == 's')
		cr->objcl = 0x00ff00;
	else if (cr->wall == 'w')
		cr->objcl = 0x0000ff;
	else if (cr->wall == 'e')
		cr->objcl = 0xffffff;
	else if (cr->wall == ' ')
		cr->objcl = 0x000000;

	if (cr->wall == 'n' || cr->wall == 's')
		x = cr->hitx;
	else
		x = cr->hity;
	tx = (x - (int)x) * TEXSIZE;
	ty = (double)TEXSIZE / column;
	// printf("%d %d | ", cr->hitx, cr->hity);
	t = i * ty;
	// if (cr->rcurr == 1)
	// 	cr->objcl = 0x0000ff;
	c = cr->addrtext[tx + (t * TEXSIZE)];
		// return (c);
		return (cr->objcl);
}

int	floormap(double y, double distWall, t_win *cr)
{
	double distPlayer;
	double currentDist;
	int c;

    currentDist = (double)WIN_HIGHT / (2.0 * (double)y - (double)WIN_HIGHT);
	double weight = currentDist / distWall;

    double currentFloorX = weight * cr->hitx + (1.0 - weight) * cr->player.x;
    double currentFloorY = weight * cr->hity + (1.0 - weight) * cr->player.y;

    int floorTexX, floorTexY;
    floorTexX = (int)(currentFloorX * 32) % 32;
    floorTexY = (int)(currentFloorY * 32) % 32;

   c = cr->addrtext[32 * floorTexY + floorTexX];
   return (c);
}

void	draw(t_win *cr, int ray)
{
	int i;
	double	column;
	double	beg;

	i = 0;
	column = WIN_HIGHT / cr->dist;//Заменить на норм. расчет высоты столбцов
	beg = (WIN_HIGHT - column) / 2;
	// printf("%d    ", ray);
	// fflush(stdout);
	while (i < WIN_HIGHT)
	{
		if ((i > beg) && (i < WIN_HIGHT - beg) && i > 0)
		{
			cr->wall = checker(cr, cr->hitx, cr->hity, cr->tiles);
			// cr->wall = 's';
			if (cr->wall == 'e')
				cr->addr[ray + (i * WIN_WIDTH)] = colors(cr, i - beg, column);
			if (cr->wall == 'n')
				cr->addr[ray + (i * WIN_WIDTH)] = colors(cr, i - beg, column);
			if (cr->wall == 's')
				cr->addr[ray + (i * WIN_WIDTH)] = colors(cr, i - beg, column);
			if (cr->wall == 'w')
				cr->addr[ray + (i * WIN_WIDTH)] = colors(cr, i - beg, column);
		}
		else if (i > beg + column)
			cr->addr[ray + (i * WIN_WIDTH)] = floormap(i, cr->dist, cr);		
		i++;
	}
}
