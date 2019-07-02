/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:20 by jsteuber          #+#    #+#             */
/*   Updated: 2019/06/25 20:10:44 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "wolf.h"

int		hooks(t_win *cr)
{
	visual(cr);
	//
	// mlx_hook(cr->win, 4, 1, mouse_press, cr);
	// mlx_hook(cr->win, 5, 1, mouse_release, cr);
	// mlx_hook(cr->win, 6, 1, mouse_move, cr);
	mlx_hook(cr->win, 2, 1, key_action, cr);
	mlx_loop(cr->mlx);
	return (0);
}

void		vector_init(t_win *cr)
{
	cr->player.x = 6.5; //Добавить функцию поиска свободной клетки
	cr->player.y = 3.5; //для помещения туда игрока
	cr->dir.x = 0.0;
	cr->dir.y = 1.0;
	cr->plane.x = 0.5;
	cr->plane.y = 0;
	cr->dir.len = cr->dir.x > cr->dir.y ? cr->dir.x : cr->dir.y;
	cr->plane.len = cr->plane.x > cr->plane.y ? cr->plane.x : cr->plane.y;
}

double	ft_atod(char *l)
{
	int i;
	int k;
	int j;
	int c;
	double	r;

	i = 0;
	if (l[0] > 47 && l[0] < 58)
		k = ft_atoi(l);
	else
		k = ft_atoi(l + 3);
	while (l[i] != '.')
		i++;
	j = ft_atoi(l + i + 1);
	c = 0;
	i++;
	while (l[i++] != ',')
		c++;
	i = 1;
	while (c--)
		i = i * 10;
	r = k + ((double)j / (double)i);
	return(r);
}

void	writemass(t_spr *spr, char *l)
{
	int i;
	int j;
	double tx;

	i = 0;
	j = 0;
	spr->x = ft_atod(l + 2);
	while (l[i])
	{
		if (l[i] == ',' && j == 0)
		{
			spr->y = ft_atod(l + i + 2);
			j++;
			i++;
		}
		if (l[i] == ',' && j == 1)
			spr->tex = ft_atoi(l + i + 2);
		i++;		
	}
}

void	write_obj(t_win *cr, int fd, int count)
{
	t_spr spr[count];
	int i;
	int j;
	char *line;

	cr->sprite = malloc(sizeof(t_spr) * count);
	i = 0;
	j = 0;
	while (get_next_line(fd, &line) == 1)
	{
		// if (line[0] > 47 && line[0] < 58)
		// 	break;
		if (i == 1)
		{
			writemass(&spr[j], line);
			j++;
		}
		if (ft_strcmp("obj:", line) == 0)
			i = 1;
		free(line);
	}
	cr->sprite = spr;
}

void	get_obj(t_win *cr, char *argv)
{
	int fd3;
	int fd4;
	int i;
	int count;
	char *line;

	fd3 = open(argv, O_RDONLY);
	fd4 = open(argv, O_RDONLY);
	i = 0;
	count = 0;
	while (get_next_line(fd3, &line) == 1)
	{
		if (line[0] > 47 && line[0] < 58)
			break;
		if (i == 1)
			count++;
		if (ft_strcmp("obj:", line) == 0)
			i = 1;
		free(line);
	}
	while (get_next_line(fd3, &line) == 1)
		i = 0;
	close(fd3);
	write_obj(cr, fd4, count);
	close(fd4);
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
	//
	x = TEXSIZE;
	y = TEXSIZE;
	// cr->text = mlx_xpm_file_to_image(cr->mlx, "src/stone.xpm", &x, &y);
	// printf("%d, %d  ===  ", x, y);
	// cr->addrtext = (int *)mlx_get_data_addr(cr->text, &cr->bpp, &(cr->linesize), &(cr->endian));
	//
	get_map(fd0, fd, cr, argv);
	return (0);
}
