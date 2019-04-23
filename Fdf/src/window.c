/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:47:15 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/25 17:47:21 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			create_window(t_map *m)
{
	if (!(m->mlx = mlx_init()))
	{
		ft_putstr_fd("Error minilibx init\n", 2);
		return (1);
	}
	m->x0 = WIDTH / 2;
	m->y0 = HEIGHT / 2;
	m->z0 = 1;
	m->zoom = 1;
	if (!(m->win = mlx_new_window(m->mlx, WIDTH, HEIGHT, "fdf")))
		return (1);
	do_it(m);
	return (1);
}

void		instruction(t_map *m)
{
	mlx_string_put(m->mlx, m->win, 30, 20, TC, "Exit ->  ESC");
	mlx_string_put(m->mlx, m->win, 30, 40, TC, "Move ->  ^ v < >");
	mlx_string_put(m->mlx, m->win, 30, 60, TC, "Zoom ->  + - ");
	mlx_string_put(m->mlx, m->win, 30, 80, TC, "Press 1 to set First style");
	mlx_string_put(m->mlx, m->win, 30, 100, TC, "Press 2 to set Second style");
	mlx_string_put(m->mlx, m->win, 30, 120, TC, "Press 3 to set Third style");
	mlx_string_put(m->mlx, m->win, 30, 140, TC, "Press M for Magic");
	mlx_string_put(m->mlx, m->win, 30, 160,
		TC, "Press (Double) I for isometric form");
	mlx_string_put(m->mlx, m->win, 30, 180, TC, "Press P for paralel form");
}

int			do_it(t_map *m)
{
	instruction(m);
	draw(m->copy, m);
	return (1);
}

void		rescreen(t_map *m)
{
	mlx_clear_window(m->mlx, m->win);
	do_it(m);
}
