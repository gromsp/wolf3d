/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteuber <jsteuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:55:16 by jsteuber          #+#    #+#             */
/*   Updated: 2019/06/18 21:35:12 by jsteuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"

typedef struct		s_visual
{
	int				x_i;
	int				y_i;
	int				y2_i;
}					t_visual;

typedef struct		s_obj
{
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			len;
}					t_obj;

typedef struct		s_win
{
	void			*mlx;
	void			*win;
	int				x_len;
	int				y_len;
	t_visual		*vs;
	double			rotation;
	char			*img_ptr;
	void			*image;
	int				linesize;
	int				dragl;
	int				dragr;
	double			x_mem;
	double			y_mem;
//
	int				zoom;
	int				**tiles;
	t_obj			player;
	t_obj			dir;
	t_obj			plane;
	double			dist;
	double			trash;
	int				objcl;
	double			castx;
	double			casty;
	int				rays;
	double			renderpoint;
	int				prop;
	//
	void	*text;
	int		*addrtext;
	int     bts;
	int		rcurr;
	char		wall;
	int     *addr;
	double		hitx;
	double		hity;
	int			endian;
	int			bpp;
}					t_win;

# define WIN_WIDTH 1300
# define WIN_HIGHT 1300
# define ROTATION -0.1
# define SPEED 0.3
# define MAX_DIST 35
//
# define TEXSIZE 32

int					init(char *argv, t_win *cr);
int					hooks(t_win *cr);
void				get_grid(int fd0, int fd, t_win *cr);
void				render(t_win *cr);
void				img_new(t_win *cr);
void				img_pxl(t_win *cr, int x, int y, int color);
int					key_action(int keycode, t_win *cr);
void				err_ex(int pr);
int					mouse_press(int button, int x, int y, t_win *cr);
int					mouse_release(int button, int x, int y, t_win *cr);
int					mouse_move(int x, int y, t_win *cr);
void				make_cast(t_win *cr);
void				bresenham(t_win *cr);
void				dda(t_win *cr);
int					wall_check(t_win *cr, double x, double y);
void				transform(t_win *cr, double *x0, double *y0, char dir);
void				tile_color(int wt, t_win *cr);
void				calc_line(t_win *cr);
//
char	checker(double x, double y, int **tiles);
// void	render(t_map *map);
void	draw(t_win *cr, int ray);

#endif
