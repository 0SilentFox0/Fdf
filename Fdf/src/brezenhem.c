/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenhem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:18:03 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/25 14:18:04 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		line_x(t_map *m, int x1, int y1, int color)
{
	int x;
	int y;
	int d;

	x = x1;
	y = y1;
	d = -m->l.length_x;
	m->l.length++;
	while (m->l.length--)
	{
		mlx_pixel_put(m->mlx, m->win, x, y, color);
		x += m->l.dx;
		d += 2 * m->l.length_y;
		if (d > 0)
		{
			d -= 2 * m->l.length_x;
			y += m->l.dy;
		}
	}
}

void		line_y(t_map *m, int x1, int y1, int color)
{
	int x;
	int y;
	int d;

	x = x1;
	y = y1;
	d = -m->l.length_y;
	m->l.length++;
	while (m->l.length--)
	{
		mlx_pixel_put(m->mlx, m->win, x, y, color);
		y += m->l.dy;
		d += 2 * m->l.length_x;
		if (d > 0)
		{
			d -= 2 * m->l.length_y;
			x += m->l.dx;
		}
	}
}

void		line(t_map *m, t_coord *tmp, int mod)
{
	int x2;
	int y2;

	x2 = 0;
	y2 = 0;
	if (mod == 1)
	{
		x2 = tmp->prev->x;
		y2 = tmp->prev->y;
	}
	if (mod == 2)
	{
		x2 = tmp->next->x;
		y2 = tmp->next->y;
	}
	m->l.dx = (x2 - tmp->x >= 0 ? 1 : -1);
	m->l.dy = (y2 - tmp->y >= 0 ? 1 : -1);
	m->l.length_x = fabs(x2 - tmp->x);
	m->l.length_y = fabs(y2 - tmp->y);
	m->l.length = fmax(m->l.length_x, m->l.length_y);
	if (m->l.length_y <= m->l.length_x)
		line_x(m, tmp->x, tmp->y, tmp->color);
	else
		line_y(m, tmp->x, tmp->y, tmp->color);
}
