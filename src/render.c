/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:12:24 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/21 16:18:25 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/wolf.h"

// int		floormap(t_core *core, int i, int dist)
// {
// 	int x;
// 	int y;

	
// }

int		colors(t_core *core, int i, double column, int	*text)
{
	int tx;
	double	ty;
	double	x;
	int t;
	int c;

	if (core->ray->wall == 'n' || core->ray->wall == 's')
		x = core->ray->x;
	else
		x = core->ray->y;
	tx = (x - (int)x) * TEXSIZE;
	ty = (double)TEXSIZE / column;
	t = i * ty;
	c = core->img->addrtext[tx + (t * TEXSIZE)];
		return (c);
}

int	floormap(double y, double distWall, t_core *core)
{
	double distPlayer;
	double currentDist;
	int c;

    currentDist = (double)height / (2.0 * (double)y - (double)height);
	double weight = currentDist / distWall;

    double currentFloorX = weight * core->ray->x + (1.0 - weight) * core->play->px;
    double currentFloorY = weight * core->ray->y + (1.0 - weight) * core->play->px;

    int floorTexX, floorTexY;
    floorTexX = (int)(currentFloorX * 32) % 32;
    floorTexY = (int)(currentFloorY * 32) % 32;

   c = core->img->addrtext[32 * floorTexY + floorTexX];
   return (c);
}

void	draw(t_core *core, int ray)
{
	int i;
	double	column;
	double	beg;

	i = 0;
	column = height / (core->play->rays * cos((core->ray->ray_angle - core->play->pa) * M_PI / 180));
	beg = (height - column) / 2;
	while (i < height)
	{
		if ((i > beg) && (i < height - beg))
		{
			core->ray->wall = checker(core->ray->x, core->ray->y, core->map);
			if (core->ray->wall == 'e')
				core->img->addr[ray + (i * height)] = colors(core, i - beg, column, core->img->addrtext);
			if (core->ray->wall == 'n')
				core->img->addr[ray + (i * height)] = colors(core, i - beg, column, core->img->addrtext);
			if (core->ray->wall == 's')
				core->img->addr[ray + (i * height)] = colors(core, i - beg, column, core->img->addrtext);
			if (core->ray->wall == 'w')
				core->img->addr[ray + (i * height)] = colors(core, i - beg, column, core->img->addrtext);
		}
		else if (i > beg + column)
			core->img->addr[ray + (i * height)] = floormap(i, core->play->rays, core);
		else
			core->img->addr[ray + (i * height)] = 0x000033;
		i++;			
	}
}

void	raycast(t_core *core)
{
	double	angle;
	int		ray;
	double	ray_ang;
	double	x;
	double	y;

	core->ray->angle = (double)core->play->fov / widht;
	ray = 0;
	core->ray->ray_angle = core->play->pa - (core->play->fov / 2);
	while(ray < widht)
	{
		core->ray->ray_angle += core->ray->angle;
		core->play->rays = 0;
		while(core->play->rays < (core->map->height_m * core->map->widht_m) * 2)
		{
			core->ray->x = core->play->px + core->play->rays * cos(core->ray->ray_angle * M_PI / 180);
			core->ray->y = core->play->py + core->play->rays * sin(core->ray->ray_angle * M_PI / 180);
			if (core->map->map[(int)core->ray->x + ((int)core->ray->y * core->map->widht_m)] == 1)
			{
				draw(core, ray);
				break;
			}
			core->play->rays += (core->map->step / 10);
		}
		ray++;
	}
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->img, 0, 0);
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->text, 0, 0);
}

void	render(t_map *map)
{
	t_core	*core;

	core = initcore(core);
	core->map = map;
	raycast(core);
	mlx_key_hook(core->img->win, control, (void*)(core));
	// mlx_mouse_hook(core->img->win, controlms, (void*)(core));
	// mlx_hook(core->img->win, 6, 0, mouse_move, (void*)(core));
	mlx_loop(core->img->mlx);
}
