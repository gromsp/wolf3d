
#include "../include/wolf.h"

void	draw(t_img *img, double x, double y, int c, int luch)
{
	int i = 0;
	int column;
	int beg;
	column = 512/c;
	beg = (512 - column) / 2;
	while(i < 512)
	{
		if ((i > beg) && (i < (512 - beg)))
			img->addr[luch + (i * 512)] = 0xFFFFFF;
		else
			img->addr[luch + (i * 512)] = 0x000000;
		i++;
	}
}

int main()
{
	t_img *img;
	img = (t_img *)ft_memalloc(sizeof(t_img));
	char *s;
	img->mlx = mlx_init();
	img->img = mlx_new_image(img->mlx, 512, 512);
	img->win = mlx_new_window(img->mlx, 512, 512, "42");
	s = mlx_get_data_addr(img->img, &(img->bts), &(img->size_line), &(img->endian));
	img->addr = (int*)s;
	int wmap;
	int hmap;

	wmap = 4;
	hmap = 4;
	char map[4 * 4] = "1111101111111111";
	int wemap = 512;
	int quad;
	quad = wemap / wmap;
	char *m;
	int i;
	m = malloc(sizeof(char) * (512 * 512));
	i = 0;
	while (i < 512 * 512)
	{
		if (map[i / quad] == 1)
		{
			m[i] = 1;
			printf("1");
		}
		else
		{
			m[i] = 0;
			printf("0");
		}
		i++;
	}
	double px = quad + 5;
	double py = quad + 5;
	double pa = 0.0;
	double c = 0;
	int x;
	int y;
	int fov;
	int luch;
	double angle;
	fov = 90; 
	angle = (double)90 / (double)512;
	while (luch < 512)
	{
		pa = pa + angle;
		while ((x + (y * 512)) < 512 * 512)
		{
			x = px + c * cos(pa);
			y = py + c * sin(pa);
			if (m[x + (y * 512)] == 1)
			{
				draw(img, x, y, c, luch);
				break;
			}
			c++;
		}
		luch++;
	}
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_loop(img->mlx);
	return (0);
}