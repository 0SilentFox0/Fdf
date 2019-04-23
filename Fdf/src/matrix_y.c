/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_y.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:15:01 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/25 14:15:03 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotation_y_forward(t_map *m, t_coord *tmp, double l)
{
	double	x;
	double	z;

	tmp = m->copy;
	while (tmp)
	{
		x = m->x0 + (tmp->x - m->x0) * cos(l) + (tmp->z - m->z0) * sin(l);
		z = m->z0 + (m->x0 - tmp->x) * sin(l) + (tmp->z - m->z0) * cos(l);
		tmp->x = x;
		tmp->z = z;
		tmp = tmp->next;
	}
}

void	rotation_y_back(t_map *m, t_coord *tmp, double l)
{
	double	x;
	double	z;

	tmp = m->copy;
	while (tmp)
	{
		x = m->x0 + (tmp->x - m->x0) * cos(l) - (tmp->z - m->z0) * sin(l);
		z = m->z0 - (m->x0 - tmp->x) * sin(l) + (tmp->z - m->z0) * cos(l);
		tmp->x = x;
		tmp->z = z;
		tmp = tmp->next;
	}
}

void	rotation_y(t_map *m, int keycode, double l)
{
	if (keycode == 13)
		rotation_y_forward(m, m->cor, l);
	else if (keycode == 1)
		rotation_y_back(m, m->cor, l);
}
