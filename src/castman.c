#include "mlx.h"
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <stdlib.h>
#include "wolf.h"

void		bresenham(t_win *cr)
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;

	x0 = cr->vs->x_i;
	y0 = cr->vs->y_i;
	x1 = cr->vs->x2_i;
	y1 = cr->vs->y2_i;
	int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = (dx > dy ? dx : -dy) / 2, e2;
 	while (x0 != x1 || y0 != y1)
	{
    	img_pxl(cr, x0, y0, cr->vs->vcolor);
    	// if (x0 == x1 && y0 == y1)
		// 	break;
    	e2 = err;
    	if (e2 >- dx)
		{
			err -= dy;
			x0 += sx;
		}
    	if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
  	}
}

static int	ft_roundl(double x, double istep)
{
	int	y;

	if (istep >= 0)
	{
		y = floor(x);
	}
	else
	{
		y = ceil(x) - 1;
	}
	// printf("%f::::%f  ", x, y);
	// fflush(stdout);
	if (y < 0)
	{
		// printf("! OOB < 0 ");
		y = 0;
	}
	if (y > 23)
	{
		// printf("! OOB > 23 ");
		y = 0;
	}
	// printf("%d ++++ ", y);
	// fflush(stdout);
	return (y);
}

void	dda2(t_win *cr)
{
    int mapX = (int)cr->player.x;
    int mapY = (int)cr->player.y;

    double sideDistX;
    double sideDistY;

    double deltaDistX = sqrt(1 + (cr->casty * cr->casty) / (cr->castx * cr->castx));
    double deltaDistY = sqrt(1 + (cr->castx * cr->castx) / (cr->casty * cr->casty));

    int stepX;
    int stepY;

    int hit = 0;
    int side;
	if (cr->castx < 0)
	{
		stepX= -1;
		sideDistX = (cr->player.x - mapX) * deltaDistX;
	}
	else
	{
		stepX = 1;
       	sideDistX = (mapX + 1.0 - cr->player.x) * deltaDistX;
	}
	if (cr->casty < 0)
    {
    	stepY = -1;
		sideDistY = (cr->player.y - mapY) * deltaDistY;
    }
	else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - cr->player.y) * deltaDistY;
    }
    while (hit == 0 && (mapX < cr->x_len && mapY <= cr->y_len))
    {
    	if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        if (cr->tiles[mapY][mapX] > 0 || (mapX > cr->x_len || mapY > cr->y_len))
					hit = 1;
    }
	if (side == 0)
		cr->dist = (mapX - cr->player.x + (1 - stepX) / 2) / cr->castx;
    else
		cr->dist = (mapY - cr->player.y + (1 - stepY) / 2) / cr->casty;
	double wallX; //where exactly the wall was hit
  if (side == 0) 
  	wallX = cr->player.y + cr->dist * cr->casty;
  else
  	wallX = cr->player.x + cr->dist * cr->castx;
	double floorXWall, floorYWall; //x, y position of the floor texel at the bottom of the wall
	if(side == 0 && cr->castx > 0)
      {
        cr->hitx = mapX;
        cr->hity = wallX;
		cr->wall = 'w';
      }
      else if(side == 0 && cr->castx < 0)
      {
        cr->hitx = mapX + 1.0;
        cr->hity = wallX;
		cr->wall = 'e';
      }
      else if(side == 1 && cr->casty > 0)
      {
        cr->hitx = wallX;
        cr->hity = mapY;
		cr->wall = 'n';
      }
      else
      {
        cr->hitx = wallX;
        cr->hity = mapY + 1.0;
		cr->wall = 's';
      }
	if (cr->hitx > cr->x_len)
		cr->hitx = cr->x_len - 1;
	if (cr->hity > cr->y_len)
		cr->hity = cr->y_len - 1;
	if (cr->hitx < 1)
		cr->hitx = 1;
	if (cr->hity < 1)
		cr->hity = 1;
	printf("x - %f, y - %f\n", cr->hitx, cr->hity);
}

void	dda(t_win *cr)
{
	t_obj	inext;
	t_obj	d_inv;
	t_obj	istep;
	float	px;
	float	py;
	float	dx;
	float	dy;
	int		i_max = MAX_DIST;
	int		mapValue;

	cr->dist = 0;
	cr->objcl = 0;
	d_inv.x = 1.0f / cr->castx;
	d_inv.y = 1.0f / cr->casty;

	istep.x = (cr->castx < 0.0f) ? -1 : 1;
	istep.y = (cr->casty < 0.0f) ? -1 : 1;

	inext.x = (cr->castx < 0.0f) ? ceil(cr->player.x) + istep.x : floor(cr->player.x) + istep.x;
	inext.y = (cr->casty < 0.0f) ? ceil(cr->player.y) + istep.y : floor(cr->player.y) + istep.y;
	while (i_max--)
	{
		px = cr->player.x + cr->castx * cr->dist;
		py = cr->player.y + cr->casty * cr->dist;
		//
		// mapValue = wall_check(cr, px, py);
		//
		// printf("%d, %d\n", (int)ceil(py + 0.01 * istep.y), (int)ceil(px + 0.01 * istep.x));
		// fflush(stdout);
		// printf("%d, %d | ", ft_roundl(py, istep.y), ft_roundl(px, istep.x));
		// fflush(stdout);
		if (cr->tiles[ft_roundl(py, istep.y)][ft_roundl(px, istep.x)] != 0)
		// if ((checker(cr, px, py, cr->tiles)) != ' ')
		{
			// img_pxl(cr, px * cr->vs->gridsize + cr->vs->x_offset, py * cr->vs->gridsize + cr->vs->y_offset, 0x0000ff);//Для минимапы
			cr->hitx = px;
			cr->hity = py;
            printf("x - %f, y - %f\n", cr->hitx, cr->hity);
			return ;
		}
		// mapValue = cr->tiles[(int)ceil(py + 0.01 * istep.y)][(int)ceil(px + 0.01 * istep.x)];
		// if (mapValue != 0)
		// {
		// 	tile_color(mapValue, cr);
		// 	cr->hitx = px;
		// 	cr->hity = py;
		// 	return ;
		// }
		dx = ((float)(inext.x) - cr->player.x) * d_inv.x;
		dy = ((float)(inext.y) - cr->player.y) * d_inv.y;
		cr->dist = dx < dy ? dx : dy;
		if (dx == cr->dist)
			inext.x += istep.x;
		if (dy == cr->dist)
			inext.y += istep.y;
	}
}
