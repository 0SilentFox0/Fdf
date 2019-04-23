/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:20:33 by aspizhav          #+#    #+#             */
/*   Updated: 2018/11/13 14:36:05 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*read_line(char *src, t_gnl *gnl)
{
	char		*new;
	int			i;
	int			j;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(src) + gnl->size);
	while (src[j] != '\0')
		new[i++] = src[j++];
	free(src);
	while (gnl->buf[gnl->index] != '\n' && gnl->index < gnl->size)
		new[i++] = gnl->buf[gnl->index++];
	return (new);
}

static t_gnl		*create(int fd, t_gnl *prev)
{
	t_gnl		*creature;

	creature = (t_gnl *)malloc(sizeof(t_gnl));
	if (!creature)
		return (NULL);
	creature->next = NULL;
	creature->prev = prev;
	creature->fd = fd;
	creature->index = 0;
	creature->size = 0;
	return (creature);
}

static t_gnl		*create_fd(int fd, t_gnl *gnl)
{
	t_gnl		*memory;

	while (gnl->prev)
		gnl = gnl->prev;
	while (gnl)
	{
		if (fd == gnl->fd)
			return (gnl);
		memory = gnl;
		gnl = gnl->next;
	}
	memory->next = create(fd, memory);
	return (memory->next);
}

static char			*reader(t_gnl *gnl, char *res)
{
	while ((gnl->size = read(gnl->fd, gnl->buf, BUFF_SIZE)))
	{
		gnl->index = 0;
		res = read_line(res, gnl);
		if (gnl->index < gnl->size)
			break ;
	}
	return (res);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl		*gnl;
	char				*res;

	if ((fd < 0 || line == NULL || read(fd, 0, 0) < 0)
		|| (!gnl && !(gnl = create(fd, NULL))))
		return (-1);
	if (!(gnl = create_fd(fd, gnl)))
		return (-1);
	if (!(res = ft_strnew(0)))
		return (-1);
	if (gnl->index < gnl->size)
	{
		gnl->index++;
		res = read_line(res, gnl);
	}
	if (gnl->index >= gnl->size)
		res = reader(gnl, res);
	if (!(ft_strlen(res)) && !gnl->size)
	{
		*line = NULL;
		free(res);
		return (0);
	}
	*line = res;
	return (1);
}
