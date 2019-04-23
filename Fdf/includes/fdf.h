/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:08:03 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/05 13:08:58 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 2000
# define HEIGHT 1300
# define COEF 30
# define TC 0xffffff
# define RAD 0.3
# include "../libft/srcs/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_line
{
	int dx;
	int dy;
	int length_x;
	int length_y;
	int length;
}				t_line;

typedef struct	s_coord
{
	double				x;
	double				y;
	double				z;
	int					color;
	struct s_coord		*next;
	struct s_coord		*prev;
}				t_coord;

typedef struct	s_map
{
	void		*mlx;
	void		*win;
	double		zoom;
	int			x;
	int			y;
	int			x0;
	int			y0;
	int			z0;
	double		cx;
	double		cy;
	double		cz;
	int			area;
	int			*tab;
	int			w;
	int			h;
	t_coord		*cor;
	t_coord		*copy;
	t_line		l;
	int			nb_case;
}				t_map;

void			copyyy(t_map *m);
void			put_error(int res);
void			zoom(t_coord *copy, int keycode);
void			instruction(t_map *m);
void			draw_flat(t_coord *tmp, t_map *m);
int				key_hook(int keycode, t_map *m);
void			print_iso(t_coord *tmp, t_map *m);
int				exit_x(void *par);
void			rotation_x(t_map *m, int keycode, double l);
void			rotation_y(t_map *m, int keycode, double l);
void			rotation_z(t_map *m, int keycode, double l);
void			draw(t_coord *tmp, t_map *m);
void			cord_power(t_coord *tmp, t_map *m);
void			line(t_map *m, t_coord *tmp, int mod);
int				create_window(t_map	*m);
int				do_it(t_map *m);
void			rescreen(t_map *m);
int				reader(char *str, t_map *m);
t_coord			*ini(double x, double y, double z, int color);
void			rotation_x_forward(t_map *m, t_coord *tmp, double l);
void			rotation_y_forward(t_map *m, t_coord *tmp, double l);
void			rotation_z_forward(t_map *m, t_coord *tmp, double l);
void			rotation_x_back(t_map *m, t_coord *tmp, double l);
void			rotation_z_back(t_map *m, t_coord *tmp, double l);
void			rotation_y_back(t_map *m, t_coord *tmp, double l);

#endif
