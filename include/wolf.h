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

// typedef struct s_img
// {
// 	void    *mlx;
// 	void    *win;
// 	void    *img;
// 	void    *imgm;
// 	int     *addr;
// 	int     *addrm;
// 	int     bts;
// 	int     size_line;
// 	int     endian;
// }              t_img;

typedef struct s_map
{
	int		widht_m;
	int		height_m;
	int		*map;
	double	step;
}              t_map;

// typedef struct s_core
// {
// 	void *data;
// }              t_core;

void	parser(char *av);

#endif