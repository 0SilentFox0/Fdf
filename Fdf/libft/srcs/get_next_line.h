/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 11:11:46 by aspizhav          #+#    #+#             */
/*   Updated: 2018/11/13 14:36:53 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32

typedef struct		s_gnl
{
	int				index;
	int				size;
	char			buf[BUFF_SIZE];
	struct s_gnl	*next;
	struct s_gnl	*prev;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
