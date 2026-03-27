/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:47:36 by brbaazi           #+#    #+#             */
/*   Updated: 2024/11/12 20:40:46 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		return (1);
	}
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	ft_fi(char *s, int nb, int size_n)
{
	long	n;

	n = (long)nb;
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return ;
	}
	if (n < 0)
	{
		s[0] = '-';
		n = -(long)nb;
	}
	s[size_n] = '\0';
	size_n--;
	while (n != 0)
	{
		s[size_n] = n % 10 + 48;
		n /= 10;
		size_n--;
	}
}

char	*ft_itoa(int nb)
{
	char	*s;
	long	size_n;

	size_n = count_size(nb);
	s = malloc((size_n * sizeof(char)) + 1);
	if (!s)
		return (NULL);
	ft_fi(s, nb, size_n);
	return (s);
}
