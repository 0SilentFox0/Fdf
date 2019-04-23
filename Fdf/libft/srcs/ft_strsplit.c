/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aspizhav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 12:24:53 by aspizhav          #+#    #+#             */
/*   Updated: 2018/10/31 12:24:55 by aspizhav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_wordcount(const char *s, char c)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			counter++;
		s++;
	}
	return (counter);
}

static int	word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (*s == c)
		s++;
	while (*s != c)
	{
		len++;
		if ((*(s + 1) == c || *(s + 1) == '\0'))
			return (len);
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		index;
	int		i;
	int		j;
	int		wordlen;

	i = 0;
	index = 0;
	if (!s || !(tab = (char **)malloc(sizeof(*tab) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (index < ft_wordcount(s, c))
	{
		j = 0;
		wordlen = word_len(&s[i], c);
		tab[index] = ft_strnew(wordlen);
		while (s[i] == c)
			i++;
		while (j < wordlen)
			tab[index][j++] = s[i++];
		index++;
	}
	tab[index] = 0;
	return (tab);
}
