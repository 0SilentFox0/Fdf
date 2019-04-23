/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:28:15 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/06 19:28:19 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	copyyy(t_map *m)
{
	t_coord *tmp;
	t_coord	*ptr;

	tmp = m->copy;
	ptr = m->cor;
	while (tmp)
	{
		tmp->x = ptr->x;
		tmp->y = ptr->y;
		tmp->z = ptr->z;
		tmp->color = ptr->color + 250;
		tmp = tmp->next;
		ptr = ptr->next;
	}
	m->y0 = HEIGHT / 2;
	m->x0 = WIDTH / 2;
}

void	put_error(int res)
{
	if (res == -1)
	{
		perror("Error");
		exit(1);
	}
}

int		main(int argc, char **argv)
{
	t_map		m;

	argc = 0;
	if (!(reader(argv[1], &m)))
	{
		ft_putstr("MAP ERROR\n");
		return (1);
	}
	cord_power(m.copy, &m);
	cord_power(m.cor, &m);
	create_window(&m);
	mlx_hook(m.win, 17, 1L << 17, exit_x, &m);
	mlx_hook(m.win, 2, 5, key_hook, &m);
	mlx_loop(m.mlx);
	return (0);
}
