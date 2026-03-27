/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:14:33 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 18:06:19 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	slen;
	size_t	i;
	char	*res;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	slen = ft_strlen(s1);
	while (s1[i] && check_set(s1[i], set))
		i++;
	while (s1[i] && check_set(s1[slen - 1], set))
		slen--;
	res = my_malloc(slen - i + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (i < slen)
	{
		res[j++] = s1[i++];
	}
	res[j] = '\0';
	return (res);
}
