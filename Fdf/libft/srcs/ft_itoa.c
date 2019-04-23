/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 10:10:37 by aspizhav          #+#    #+#             */
/*   Updated: 2018/10/29 10:10:43 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long int	ft_abs(long int nbr)
{
	if (nbr < 0)
	{
		nbr = -nbr;
		return (nbr);
	}
	else
		return (nbr);
}

static int		num_len(long nb)
{
	int		len;

	len = 0;
	if (nb == 0)
	{
		len = 1;
		return (len);
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int nbr)
{
	int		len;
	int		sign;
	char	*c;

	sign = (nbr < 0) ? -1 : 1;
	len = num_len(nbr);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (!c)
		return (NULL);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(nbr % 10);
		nbr = ft_abs(nbr / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
