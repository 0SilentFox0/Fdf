/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:20:55 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/25 14:20:57 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			draw_flat(t_coord *tmp, t_map *m)
{
	int i;

	i = 0;
	tmp = m->cor;
	m->y0 = HEIGHT / 2;
	m->x0 = WIDTH / 2;
	while (tmp)
	{
		if (tmp->prev)
			line(m, tmp, 1);
		if (i < m->x - 1)
			line(m, tmp, 2);
		else
			i = -1;
		tmp = tmp->next;
		i++;
	}
	mlx_clear_window(m->mlx, m->win);
	instruction(m);
}

void			draw(t_coord *tmp, t_map *m)
{
	int i;

	i = 0;
	tmp = m->copy;
	while (tmp)
	{
		if (tmp->prev)
			line(m, tmp, 1);
		if (i < m->x - 1)
			line(m, tmp, 2);
		else
			i = -1;
		tmp = tmp->next;
		i++;
	}
}

void			cord_power(t_coord *tmp, t_map *m)
{
	tmp->x = tmp->x * COEF;
	tmp->y = tmp->y * COEF;
	tmp->z = tmp->z * 15;
	tmp->x += (WIDTH - m->x * COEF) / 2;
	tmp->y += (HEIGHT - m->y * COEF) / 2;
	if (tmp->next)
		cord_power(tmp->next, m);
}

void			print_iso(t_coord *copy, t_map *m)
{
	copyyy(m);
	rotation_x_forward(m, copy, 0.523599);
	rotation_y_back(m, copy, 0.523599);
	m->y0 = HEIGHT / 2;
	m->x0 = WIDTH / 2;
	mlx_clear_window(m->mlx, m->win);
	instruction(m);
	return ;
}

void			zoom(t_coord *copy, int keycode)
{
	while (copy)
	{
		if (keycode == 69)
		{
			copy->x = (copy->x - WIDTH / 2) * 1.1 + WIDTH / 2;
			copy->y = (copy->y - HEIGHT / 2) * 1.1 + HEIGHT / 2;
		}
		if (keycode == 78)
		{
			copy->x = (copy->x - WIDTH / 2) * 0.9 + WIDTH / 2;
			copy->y = (copy->y - HEIGHT / 2) * 0.9 + HEIGHT / 2;
		}
		copy = copy->next;
	}
}
