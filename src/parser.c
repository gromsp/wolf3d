
#include "../include/wolf.h"

int		heightm(char *av)
{
	int		i;
	int		fd;
	char	**line;

	i = 0;
	fd = open(av, O_RDONLY);
	while(get_next_line(fd, line) == 1)
	{
		i++;
	}
	close(fd);
	return(i);
}

int		widhtm(char *av)
{
	int i;
	int	fd;
	char **line;

	i = 0;
	fd = open(av, O_RDONLY);
	get_next_line(fd, line);
	i = ft_strlen(&line);
	i -= 1;
	close(fd);
	return (i);
}

char	*map(char *av, t_map *map, int f)
{
	int i;
	int fd;
	int size_line;
	char **line;
	char *lm;

	i = 0;
	j = 0;
	fd = open(av, O_RDONLY);
	get_next_line(fd, line);
	if (f == 1)
		size_line = map->height_m;
}

t_map	parser(char *av)
{
	t_map	*map;
	int i;

	i = 0;
	if (!(map = malloc(sizeof(t_map))))
		exit (-2);
	map->height_m = heightm(av);
	map->widht_m = widhtm(av);
	if (map->height_m > map->widht_m)
	{
		i = 1;
		map = malloc(sizeof(char) * map->height_m * map->height_m);
	}
	else
		map = malloc(sizeof(char) * map->widht_m * map->widht_m);
	map->map = maph(av, map, i);	
}