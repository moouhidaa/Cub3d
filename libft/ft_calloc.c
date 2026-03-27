/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:39:20 by brbaazi           #+#    #+#             */
/*   Updated: 2024/11/12 16:40:27 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*tmpp;

	tmpp = malloc((count * (size)));
	if (tmpp == NULL)
		return (0);
	i = 0;
	while (i < count * size)
	{
		tmpp[i] = 0;
		i++;
	}
	return (tmpp);
}
