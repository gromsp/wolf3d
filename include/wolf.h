#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"

# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define widht	512
# define height	512
# define sizeb	32
# define TEXSIZE 32

typedef struct s_img
{
	void    *mlx;
	void    *win;
	void    *img;
	int     *addr;
	void	*text;
	int		*addrtext;
	int     bts;
	int     size_line;
	int     endian;
}              t_img;

typedef struct s_ray
{
	double	x;
	double	y;
	double	column;
	double	ray_angle;
	double	angle;
	char	wall;
}              t_ray;

typedef struct s_player
{
	double	px;
	double	py;
	int		pa;
	double	rays;
	int		fov;
}              t_player;

typedef struct s_map
{
	int		widht_m;
	int		height_m;
	int		*map;
	double	step;
}              t_map;

typedef struct s_core
{
	t_map	*map;
	t_img	*img;
	t_player *play;
	t_ray	*ray;
}              t_core;

void	raycast(t_core *core);
char	checker(double x, double y, t_map *map);
int		control(int press_key, void *param);
int		mouse_move(int x, int y, void *param);
t_core	*initcore(t_core *core);
void	render(t_map *map);
t_map	*parser(char *av, t_map *map);

#endif