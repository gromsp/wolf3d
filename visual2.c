/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:54:37 by jsteuber          #+#    #+#             */
/*   Updated: 2019/06/12 18:38:00 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdio.h>

static void		add_offsets(t_win *win1, t_visual *w)
{
	w->x_i += win1->x_offset;
	w->y_i += win1->y_offset;
	w->x2_i += win1->x_offset;
	w->y2_i += win1->y_offset;
	// w->x_i = w->x_d;
	// w->y_i = w->y_d;
	// w->x2_i = w->x2_d;
	// w->y2_i = w->y2_d;
}

void			draw_x_str(t_win *win1, int i, int x_len, t_visual *w)
{
	int			j;
	double		coef;

	j = 0;
	coef = win1->size / win1->prop;
	while (x_len--)
	{
		//
		// win1->tiles->x = x_len;
		// printf("%d ", win1->tiles.x);
		//
		printf("%d %d %f %f %d\n", i, j, (win1->grid)[0][0].x, (win1->grid)[0][0].y, w->x_i);
		fflush(stdout);
		w->x_i = (win1->grid)[i][j].x * win1->prop - win1->prop;
		w->y_i = (win1->grid)[i][j].y * win1->prop - win1->prop;
		w->x2_i = (win1->grid)[i][j + 1].x * win1->prop - win1->prop;
		w->y2_i = (win1->grid)[i][j + 1].y * win1->prop - win1->prop;
		w->pxl = &(win1->grid)[i][j];
		w->gradcolor1 = (win1->grid)[i][j].color;
		w->gradcolor2 = (win1->grid)[i][j + 1].color;
		add_offsets(win1, w);
		//
		if (win1->tiles[i][j] > 0)
		{
			// getcolor(win1->tiles[i][j], win1);
			// draw_sqare(win1, w->x_i, w->y_i, win1->objcl);
			draw_sqare(win1, w->x_i, w->y_i, win1->prop);
		}
		//
		draw_line_gen(win1);
		j++;
	}
}

void			draw_y_str(t_win *win1, int i, int x_len, t_visual *w)
{
	int			j;
	double		coef;

	j = 0;
	coef = win1->size / win1->prop;
	while (x_len--)
	{
		w->x_i = (win1->grid)[i][j].x * win1->prop - win1->prop;
		w->y_i = (win1->grid)[i][j].y * win1->prop - win1->prop;
		w->x2_i = (win1->grid)[i + 1][j].x * win1->prop - win1->prop;
		w->y2_i = (win1->grid)[i + 1][j].y * win1->prop - win1->prop;
		w->pxl = &(win1->grid)[i][j];
		w->gradcolor1 = (win1->grid)[i][j].color;
		w->gradcolor2 = (win1->grid)[i + 1][j].color;
		add_offsets(win1, w);
		draw_line_gen(win1);
		j++;
	}
}
