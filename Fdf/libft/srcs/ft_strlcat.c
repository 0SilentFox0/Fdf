/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:36:27 by aspizhav          #+#    #+#             */
/*   Updated: 2018/10/26 14:36:30 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s1_end;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (dst[i] && i < dstsize)
		i++;
	s1_end = i;
	while (src[i - s1_end] && i < dstsize - 1)
	{
		dst[i] = src[i - s1_end];
		i++;
	}
	if (s1_end < dstsize)
		dst[i] = '\0';
	return (s1_end + ft_strlen(src));
}
