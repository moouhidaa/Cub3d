/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:42:12 by brbaazi           #+#    #+#             */
/*   Updated: 2024/11/12 20:55:28 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	slen;
	size_t	dlen;

	if ((!src || !dest) && destsize == 0)
		return (0);
	slen = ft_strlen(src);
	dlen = ft_strlen(dest);
	if (destsize == 0)
	{
		return (slen);
	}
	if (dlen >= destsize)
	{
		return (slen + destsize);
	}
	i = 0;
	while (src[i] && dlen + i < destsize - 1)
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}
