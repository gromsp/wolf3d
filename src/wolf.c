
#include "../include/wolf.h"

void	draw(t_img *img, double x, double y, int c, int luch)
{
	int i = 0;
	int column;
	int beg;
	c = c / 2;
	column = 500/c;
	beg = (500 - column) / 2;
	while(i < 500)
	{
		if ((i > beg) && (i < (500 - beg)))
			img->addr[luch + (i * 500)] = 0xFFFFFF;
		else
			img->addr[luch + (i * 500)] = 0x000000;
		i++;
	}
}

int main()
{
	t_img *img;
	img = (t_img *)ft_memalloc(sizeof(t_img));
	char *s;
	img->mlx = mlx_init();
	img->img = mlx_new_image(img->mlx, 500, 500);
	img->win = mlx_new_window(img->mlx, 500, 500, "42");
	s = mlx_get_data_addr(img->img, &(img->bts), &(img->size_line), &(img->endian));
	img->addr = (int*)s;
	int wmap;
	int hmap;

	wmap = 4;
	hmap = 4;
	char map[4 * 4] = "1111101111111111";
	int wemap = 500;
	int quad;
	quad = wemap / wmap;
	char *m;
	int i;
	m = (char*)ft_memalloc(500 * 500);
	int j;
	int l;
	int k;
	int ryd;
	int mesto;
	j = 0;
	while (j < 16)
	{
		l = 0;
		if (map[j] == '1')
		{
			l = 0;
			ryd = (j / 4 * quad);
			while(l < 125)
			{
				mesto = (j % 4 * quad);
				k = 0;
				while(k < 125)
				{
					m[mesto + (ryd * 500)] = 1;
					k++;
					mesto++;
				}
				ryd++;
				l++;
			}
		}
		j++;
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
	double PI = 3.14159265;
	angle = (double)90 / (double)500;
	while (luch < 500)
	{
		pa = pa + angle;
		while ((x + (y * 500)) < 500 * 500)
		{
			x = px + c * cos(pa * PI/180);
			y = py + c * sin(pa * PI/180);
			if (m[x + (y * 500)] == 1)
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