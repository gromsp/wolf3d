/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:20 by jsteuber          #+#    #+#             */
/*   Updated: 2019/06/18 21:35:59 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "wolf.h"

int		hooks(t_win *cr)
{
	render(cr);
	//
	mlx_hook(cr->win, 4, 1, mouse_press, cr);
	mlx_hook(cr->win, 5, 1, mouse_release, cr);
	mlx_hook(cr->win, 6, 1, mouse_move, cr);
	mlx_hook(cr->win, 2, 1, key_action, cr);
	mlx_loop(cr->mlx);
	return (0);
}

int		init(char *argv, t_win *cr)
{
	int			fd0;
	int			fd;
	//
	int		x;
	int		y;

	fd0 = open(argv, O_RDONLY);
	fd = open(argv, O_RDONLY);
	if (!(cr->mlx = mlx_init()))
		err_ex(0);
	if (!(cr->win = mlx_new_window(cr->mlx, WIN_WIDTH, WIN_HIGHT, "Wolf3d")))
		err_ex(0);
	if (!(cr->vs = (t_visual *)malloc(sizeof(t_visual))))
		err_ex(0);
	cr->rotation = ROTATION;
	cr->renderpoint = WIN_WIDTH / 2;
	//
	x = TEXSIZE;
	y = TEXSIZE;
	cr->text = mlx_xpm_file_to_image(cr->mlx, "stone.xpm", &x, &y);
	// printf("%d, %d  ===  ", x, y);
	cr->addrtext = (int *)mlx_get_data_addr(cr->text, &cr->bpp, &(cr->linesize), &(cr->endian));
	//
	get_grid(fd0, fd, cr);
	return (0);
}
