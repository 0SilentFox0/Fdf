/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:28:15 by aspizhav          #+#    #+#             */
/*   Updated: 2018/12/06 19:28:19 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		freedom_for_bytes(char **n)
{
	int i;

	i = -1;
	while (n[++i] != NULL)
		free(n[i]);
	free(n);
}

void		new_list_cord(t_coord **alst, t_coord *new)
{
	t_coord *tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next != NULL)
	{
		if (tmp->y == new->y - 1 && tmp->x == new->x)
			new->prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = new;
}

int			atoi_tab(t_map *m, char *str, int y)
{
	char		**n;
	int			x;
	t_coord		*new;
	t_coord		*tmp;

	new = NULL;
	if (!(n = ft_strsplit(str, ' ')))
		return (0);
	x = 0;
	while (n[x])
		x++;
	m->x == -1 ? m->x = x : 0;
	if (m->x != x)
		return (0);
	x = -1;
	while (++x < m->x)
	{
		new = ini(x, y, ft_atoi(n[x]), abase(n[x] + ft_strlen(n[x]) - 6, 16));
		new_list_cord(&m->cor, new);
		tmp = ini(x, y, ft_atoi(n[x]), abase(n[x] + ft_strlen(n[x]) - 6, 16));
		new_list_cord(&m->copy, tmp);
	}
	freedom_for_bytes(n);
	return (1);
}

t_coord		*ini(double x, double y, double z, int color)
{
	t_coord *new;

	if (!(new = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->x = x;
	new->y = y;
	new->z = z;
	new->color = color;
	if (!color)
		new->color = 0xfc7702;
	return (new);
}

int			reader(char *str, t_map *m)
{
	char	*line;
	int		res;
	int		y;
	int		fd;

	if ((fd = open(str, O_RDONLY)) <= 0)
		put_error(-1);
	y = 0;
	m->cor = NULL;
	m->x = -1;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (atoi_tab(m, line, y++) == 0)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	put_error(res);
	close(fd);
	m->y = y;
	return (1);
}
