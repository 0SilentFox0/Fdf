/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 11:33:19 by aspizhav          #+#    #+#             */
/*   Updated: 2018/10/30 11:33:22 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		sign;
	int		res;

	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		sign = (*str == '-' ? -1 : 1);
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (9223372036854775807 - res <= *str - 48)
			return (sign == 1 ? -1 : 0);
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res * sign);
}
