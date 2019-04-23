/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:04:46 by aspizhav          #+#    #+#             */
/*   Updated: 2018/10/31 10:04:48 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*map;

	if (s == NULL || f == NULL)
		return (0);
	map = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (map == NULL)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		map[i] = f(i, *s);
		i++;
		s++;
	}
	map[i] = '\0';
	return (map);
}
