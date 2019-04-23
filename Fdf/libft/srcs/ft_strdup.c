/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:43:54 by aspizhav          #+#    #+#             */
/*   Updated: 2018/10/26 10:43:56 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *s1)
{
	char	*cpy;

	cpy = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cpy != NULL)
		ft_strcpy(cpy, s1);
	return (cpy);
}
