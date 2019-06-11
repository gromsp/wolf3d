/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:22:57 by adoyle            #+#    #+#             */
/*   Updated: 2019/06/08 18:14:59 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int		heightm(char *av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		i++;
	}
	close(fd);
	return (i);
}

int		widhtm(char *av)
{
	int		i;
	int		fd;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	fd = open(av, O_RDONLY);
	get_next_line(fd, &line);
	while (line[i])
	{
		if ((line[i - 1]) && line[i - 1] == 32 && line[i] != 32)
			j++;
		i++;
	}
	free(line);
	j += 1;
	while ((get_next_line(fd, &line)) == 1)
	{
		i++;
		free(line);
	}
	close(fd);
	return (j);
}

void	mapa(int f, int size_line, t_map *map, char *str)
{
	static int	i;
	int			j;


	j = 0;
	if (i == 0 || i % size_line == 0)
	{
		map->map[i] = ft_atoi(str + j);
		i++;
		j++;
	}
	while (f > i)
	{
		if (str[j] != 0 && str[j - 1] == 32 && str[j] != 32)
		{
			map->map[i] = ft_atoi(str + j);
			i++;
			j++;
		}
		else if ((!(str)) || (str[j] == 0))
		{
			map->map[i] = 1;
			i++;
		}
		else
			j++;
	}
}

void	maph(char *av, t_map *map, int f, int size_line)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	i = size_line;
	j = size_line;
	fd = open(av, O_RDONLY);
	while (i > 0)
	{
		get_next_line(fd, &line);
		mapa(j, size_line, map, line);
		j = j + size_line;
		free(line);
		i--;
	}
	close(fd);
}

t_map	*parser(char *av, t_map *map)
{
	int i;
	int size_line;

	i = 0;
	if (!(map = malloc(sizeof(t_map))))
		exit(-2);
	map->height_m = heightm(av);
	map->widht_m = widhtm(av);
	if (map->height_m > map->widht_m)
	{
		i = 1;
		map->map = malloc(sizeof(int) * map->height_m * map->height_m);
		size_line = map->height_m;
	}
	else
	{
		map->map = malloc(sizeof(int) * map->widht_m * map->widht_m);
		size_line = map->widht_m;
		map->height_m = map->widht_m;
	}
	maph(av, map, i, size_line);
	map->step = (int)1 / (double)sizeb;
	int a = 0;
	while (a < 16)
		printf("%d", map->map[a++]);
	printf("\n");
	return (map);
}
