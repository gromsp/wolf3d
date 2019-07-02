/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:10 by jsteuber          #+#    #+#             */
/*   Updated: 2019/06/21 20:38:32 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdlib.h>
#include <stdio.h>

static void		map_line(char *line, int j, t_win *cr)
{
	char			**arr;
	int				i;
	int				line_len_ct;

	i = 0;
	arr = ft_strsplit(line, ' ');
	line_len_ct = cr->x_len;
	while (line_len_ct--)
	{
		cr->tiles[j][cr->x_len - line_len_ct - 1] = ft_atoi(arr[i]);
		i++;
	}
	ft_arrfree(&arr, cr->x_len);
}

void			get_map(int fd0, int fd, t_win *cr, char *argv)
{
	char		*line;
	int			yc;

	yc = 0;
	if (get_next_line(fd0, &line) == 1)
	{
		yc++;
	}
	else
		err_ex(2);
	cr->x_len = ft_ctwords(line, ' ');
	free(line);
	img_new(cr);
	// cr->y_len = yc;
	// cr->tiles = (int **)malloc(sizeof(int *) * cr->y_len + 1);//+1 ??????
	while (get_next_line(fd0, &line) == 1)
	{
		if (line[0] == 0 || line[0] == '\n')
			break;
		yc++;
		free(line);
	}
	cr->y_len = yc;
	cr->tiles = (int **)malloc(sizeof(int *) * cr->y_len);
	yc = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 0 || line[0] == '\n')
			break;
		if (!((cr->tiles)[yc] = (int *)malloc(sizeof(int) * cr->x_len)))
			err_ex(0);
		map_line(line, yc, cr);
		yc++;
		free(line);
	}
	close(fd0);
	get_obj(cr, argv);
	vector_init(cr);
	img_new(cr);
	visual(cr);
	close(fd);
}
