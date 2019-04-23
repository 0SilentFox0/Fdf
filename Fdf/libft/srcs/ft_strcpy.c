/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:06:20 by aspizhav          #+#    #+#             */
/*   Updated: 2018/10/26 11:06:21 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	size_t	cur;

	cur = 0;
	while (src[cur] != '\0')
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = '\0';
	return (dst);
}
