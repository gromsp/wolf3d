/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:12:24 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/09 18:34:20 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/wolf.h"

void	draw(t_core *core, int ray, double angle, double ray_ang)
{
	int i;
	double	column;
	double	beg;

	i = 0;
	column = height / (core->play->rays * cos((ray_ang - core->play->pa) * M_PI / 180));
	beg = (height - column) / 2;
	while (i < height)
	{
		if ((i > beg) && (i < height - beg))
			core->img->addr[ray + (i * height)] = 0xFFFFFF;
		else if (i > beg)
			core->img->addr[ray + (i * height)] = 0x444444;
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

	angle = (double)core->play->fov / widht;
	ray = 0;
	ray_ang = core->play->pa - (core->play->fov / 2);
	while(ray < widht)
	{
		ray_ang += angle;
		core->play->rays = 0;
		while(core->play->rays < core->map->height_m * core->map->height_m)
		{
			x = core->play->px + core->play->rays * cos(ray_ang * M_PI / 180);
			y = core->play->py + core->play->rays * sin(ray_ang * M_PI / 180);
			if (core->map->map[(int)x + ((int)y * core->map->height_m)] == 1)
			{
				draw(core, ray, angle, ray_ang);
				break;
			}
			core->play->rays += (core->map->step / 2);
		}
		ray++;
	}
	mlx_put_image_to_window(core->img->mlx, core->img->win, core->img->img, 0, 0);
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
