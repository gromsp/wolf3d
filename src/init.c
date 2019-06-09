/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:16:28 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/09 17:35:59 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void		initimg(t_img *img)
{
	char	*s;
	char	*m;

	img->mlx = mlx_init();
	img->img = mlx_new_image(img->mlx, widht, height);
	img->win = mlx_new_window(img->mlx, widht, height, "wolf3d");
	s = mlx_get_data_addr(img->img, &(img->bts),
	&(img->size_line), &(img->endian));
	img->addr = (int*)s;
}

void		initplayer(t_player *play)
{
	play->px = 1.5;
	play->py = 1.5;
	play->pa = 45;
	play->fov = 60;
}

t_core		*initcore(t_core *core)
{
	t_img	*img;
	t_player	*play;

	if (!(core = malloc(sizeof(t_core))))
		exit (-1);
	if (!(img = malloc(sizeof(t_img))))
		exit (-1);
	if (!(play = malloc(sizeof(t_player))))
		exit (-1);
	core->img = img;
	core->play = play;
	initimg(core->img);
	initplayer(core->play);
	return (core);
}