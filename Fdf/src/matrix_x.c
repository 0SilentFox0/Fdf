/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:13:13 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/25 14:13:17 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotation_x_back(t_map *m, t_coord *tmp, double l)
{
	double	y;
	double	z;

	tmp = m->copy;
	while (tmp)
	{
		y = m->y0 + (tmp->y - m->y0) * cos(l) - (m->z0 - tmp->z) * sin(l);
		z = m->z0 - (tmp->y - m->y0) * sin(l) + (tmp->z - m->z0) * cos(l);
		tmp->y = y;
		tmp->z = z;
		tmp = tmp->next;
	}
}

void	rotation_x_forward(t_map *m, t_coord *tmp, double l)
{
	double	y;
	double	z;

	tmp = m->copy;
	while (tmp)
	{
		y = m->y0 + (tmp->y - m->y0) * cos(l) + (m->z0 - tmp->z) * sin(l);
		z = m->z0 + (tmp->y - m->y0) * sin(l) + (tmp->z - m->z0) * cos(l);
		tmp->y = y;
		tmp->z = z;
		tmp = tmp->next;
	}
}

void	rotation_x(t_map *m, int keycode, double l)
{
	if (keycode == 12)
		rotation_x_forward(m, m->cor, l);
	else if (keycode == 0)
		rotation_x_back(m, m->cor, l);
}
