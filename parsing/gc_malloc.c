/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:02 by moouhida          #+#    #+#             */
/*   Updated: 2026/01/07 20:45:41 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	*m_malloc(size_t size, int mode)
{
	static t_list	*head;
	t_list			*new;
	void			*addr;

	addr = NULL;
	if (mode == 1)
	{
		addr = malloc(size);
		if (!addr)
		{
			ft_putstr_fd("Error\n: Malloc Failed", 2);
			m_malloc(0, 0);
			exit(1);
		}
		new = ft_lstnew(addr);
		ft_lstadd_back(&head, new);
	}
	if (mode == 0)
	{
		if (head)
			ft_lstclear(&head, free);
		head = NULL;
	}
	return (addr);
}

void	*my_malloc(size_t size)
{
	return (m_malloc(size, 1));
}

void	my_free(void)
{
	m_malloc(0, 0);
	exit(1);
}

int	onlyw(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] > 32)
			return (1);
		i++;
	}
	return (0);
}
