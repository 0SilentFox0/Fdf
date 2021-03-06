/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 10:15:01 by aspizhav          #+#    #+#             */
/*   Updated: 2018/11/02 10:15:30 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int r;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	r = 2;
	while (r * r <= nb)
	{
		if (r * r == nb)
			return (r);
		r++;
	}
	return (0);
}
