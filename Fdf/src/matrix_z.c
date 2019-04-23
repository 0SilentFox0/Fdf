/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:15:22 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/25 14:15:24 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotation_z_forward(t_map *m, t_coord *tmp, double l)
{
	double	x;
	double	y;

	tmp = m->copy;
	while (tmp)
	{
		x = m->x0 + (tmp->x - m->x0) * cos(l) + (-tmp->y + m->y0) * sin(l);
		y = m->y0 + (tmp->x - m->x0) * sin(l) + (tmp->y - m->y0) * cos(l);
		tmp->x = x;
		tmp->y = y;
		tmp = tmp->next;
	}
}

void	rotation_z_back(t_map *m, t_coord *tmp, double l)
{
	double	x;
	double	y;

	tmp = m->copy;
	while (tmp)
	{
		x = m->x0 + (tmp->x - m->x0) * cos(l) - (m->y0 - tmp->y) * sin(l);
		y = m->y0 - (tmp->x - m->x0) * sin(l) + (tmp->y - m->y0) * cos(l);
		tmp->x = x;
		tmp->y = y;
		tmp = tmp->next;
	}
}

void	rotation_z(t_map *m, int keycode, double l)
{
	if (keycode == 14)
		rotation_z_forward(m, m->cor, l);
	else if (keycode == 2)
		rotation_z_back(m, m->cor, l);
}
