#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"

# include "libft.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_img
{
	void    *mlx;
	void    *win;
	void    *img;
	int     *addr;
	int     bts;
	int     size_line;
	int     endian;
}              t_img;


#endif