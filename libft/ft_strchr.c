/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:42:42 by brbaazi           #+#    #+#             */
/*   Updated: 2025/11/18 15:00:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	h;

	h = (char)c;
	i = 0;
	while (s && s[i])
	{
		if (s[i] == h)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
