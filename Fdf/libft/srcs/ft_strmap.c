/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:02:09 by aspizhav          #+#    #+#             */
/*   Updated: 2018/10/30 18:02:11 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	if (s == NULL || f == NULL)
		return (NULL);
	map = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		map[i] = f(*s);
		i++;
		s++;
	}
	map[i] = '\0';
	return (map);
}
