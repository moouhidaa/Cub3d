/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:09:30 by brbaazi           #+#    #+#             */
/*   Updated: 2024/11/12 16:16:43 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmmp;

	if (!lst || !del)
	{
		return ;
	}
	while (*lst)
	{
		tmmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmmp;
	}
	*lst = NULL;
}
