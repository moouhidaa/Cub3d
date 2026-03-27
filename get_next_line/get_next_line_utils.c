/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 02:12:13 by moouhida          #+#    #+#             */
/*   Updated: 2024/12/26 04:51:51 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_start(char *s, unsigned int start, size_t len)
{
	size_t	x;
	char	*new;

	x = 0;
	if (!s)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	new = my_malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[start])
	{
		new[x] = s[start];
		x++;
		start++;
	}
	new[x] = '\0';
	return (new);
}
