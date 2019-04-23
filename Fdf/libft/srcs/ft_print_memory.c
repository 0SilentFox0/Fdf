/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:07:39 by aspizhav          #+#    #+#             */
/*   Updated: 2018/11/02 11:08:28 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void			print_hex(unsigned char hex)
{
	char			tab[16];
	char			ind;
	int				i;

	ind = '0';
	i = 0;
	while (ind <= '9')
		tab[i++] = ind++;
	ind = 'a';
	while (ind <= 'f')
		tab[i++] = ind++;
	ft_putchar(tab[hex / 16]);
	ft_putchar(tab[hex % 16]);
}

static void			print_ascii(unsigned char hex)
{
	if (hex >= 32 && hex <= 126)
		ft_putchar(hex);
	else
		ft_putchar('.');
}

static void			print_line(unsigned char *hex, size_t start, size_t size)
{
	size_t			i;

	i = start;
	while (i < start + 16 && i < size)
	{
		print_hex(hex[i]);
		if (i % 2 != 0)
			ft_putchar(' ');
		i++;
	}
	while (i < start + 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (i % 2 != 0)
			ft_putchar(' ');
		i++;
	}
	i = start;
	while (i < start + 16 && i < size)
	{
		print_ascii(hex[i]);
		i++;
	}
	ft_putchar('\n');
}

void				ft_print_memory(const void *addr, size_t size)
{
	size_t			index;
	unsigned char	*hex;

	index = 0;
	hex = (unsigned char*)addr;
	while (index < size)
	{
		print_line(hex, index, size);
		index += 16;
	}
}
