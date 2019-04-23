/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 17:56:47 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/25 17:56:50 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		key_hook_3(int keycode, t_map *m, t_coord *tmp)
{
	tmp = m->copy;
	while (tmp)
	{
		if (keycode == 126)
			tmp->y = tmp->y - 30;
		else if (keycode == 125)
			tmp->y = tmp->y + 30;
		else if (keycode == 123)
			tmp->x = tmp->x - 30;
		else if (keycode == 124)
			tmp->x = tmp->x + 30;
		else if (keycode == 46)
			tmp->color += 250;
		else if (keycode == 18)
			tmp->color = tmp->z == 0 ? 0xf4f404 : 0xce0e0e;
		else if (keycode == 19)
			tmp->color = tmp->z == 0 ? 0x710f8e : 0x067a29;
		else if (keycode == 20)
			tmp->color = tmp->z == 0 ? 0x1120c1 : 0xe2560f;
		tmp = tmp->next;
	}
	return ;
}

void		key_hook_2(int keycode, t_map *m)
{
	if (keycode == 34)
	{
		mlx_clear_window(m->mlx, m->win);
		print_iso(m->copy, m);
	}
	else if (keycode == 35)
	{
		mlx_clear_window(m->mlx, m->win);
		instruction(m);
		draw_flat(m->cor, m);
		copyyy(m);
	}
}

void		key_hook_1(int keycode, t_map *m)
{
	if (keycode == 126)
		m->y0 -= 30;
	if (keycode == 125)
		m->y0 += 30;
	if (keycode == 123)
		m->x0 -= 30;
	if (keycode == 124)
		m->x0 += 30;
	if (keycode == 69)
		zoom(m->copy, keycode);
	if (keycode == 78)
		zoom(m->copy, keycode);
}

int			key_hook(int keycode, t_map *m)
{
	double l;

	l = RAD;
	if (keycode == 53)
	{
		mlx_destroy_window(m->mlx, m->win);
		exit(1);
	}
	rotation_x(m, keycode, l);
	rotation_y(m, keycode, l);
	rotation_z(m, keycode, l);
	key_hook_3(keycode, m, m->copy);
	key_hook_1(keycode, m);
	rescreen(m);
	key_hook_2(keycode, m);
	return (1);
}

int			exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}
