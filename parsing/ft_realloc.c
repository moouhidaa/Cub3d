/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:28:59 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 09:29:00 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**my_realloc(char **tab, char *newline)
{
	char	**new_tab;
	int		i;
	int		j;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = my_malloc(sizeof(char *) * (i + 2));
	if (!new_tab)
		return (NULL);
	j = 0;
	while (j < i)
	{
		new_tab[j] = ft_strdup(tab[j]);
		j++;
	}
	new_tab[j] = ft_strdup(newline);
	new_tab[j + 1] = NULL;
	return (new_tab);
}
