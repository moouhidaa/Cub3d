/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 23:34:41 by brbaazi           #+#    #+#             */
/*   Updated: 2024/11/12 16:18:54 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	l;
	int		len;

	l = (char)c;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	while (len >= 0)
	{
		if (s[len] == l)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
