/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 21:47:09 by brbaazi           #+#    #+#             */
/*   Updated: 2024/12/06 15:26:26 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
	{
		return ;
	}
	del(lst->content);
	free(lst);
}
// // int main()
// {
// 	t_list *head= NULL;
// 	t_list *node1 = ft_lstnew("bbbbbb");
// 	t_list *node2 = ft_lstnew("hhhh");
// 	t_list *node3 = ft_lstnew("kkkkk");
// 	t_list *node4 = ft_lstnew("brtrthtyjb");
// 	t_list *node5 = ft_lstnew("555");

// 	ft_lstadd_front(&head,node1 );
// 	ft_lstadd_front(&head,node2 );
// 	ft_lstadd_front(&head,node3 );
// 	ft_lstadd_front(&head,node4 );
// 	ft_lstadd_front(&head,node5 );

// 	ft_lstdelone(&head , node4 -> content);
// }