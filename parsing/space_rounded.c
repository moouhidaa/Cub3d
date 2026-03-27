/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_rounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:29:58 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 09:29:59 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	space_rounded(int top, int bottom, int left, int right)
{
	if ((top != ' ' && top != '1') || (bottom != ' ' && bottom != '1')
		|| (left != ' ' && left != '1') || (right != ' ' && right != '1'))
		return (1);
	else
		return (0);
}

int	check_if_duplicate(char **paths, t_counters *count)
{
	int	i;

	i = 0;
	while (paths && paths[i])
	{
		if (!ft_strncmp(paths[i], "NO ", 3) && has_xpm_extension(paths[i]))
			count->no++;
		else if (!ft_strncmp(paths[i], "SO ", 3) && has_xpm_extension(paths[i]))
			count->so++;
		else if (!ft_strncmp(paths[i], "WE ", 3) && has_xpm_extension(paths[i]))
			count->we++;
		else if (!ft_strncmp(paths[i], "EA ", 3) && has_xpm_extension(paths[i]))
			count->ea++;
		else if (!ft_strncmp(paths[i], "F ", 2))
			count->f++;
		else if (!ft_strncmp(paths[i], "C ", 2))
			count->c++;
		i++;
	}
	if (!count->no || !count->we || !count->so || !count->f || !count->c
		|| !count->ea)
		return (ft_error("Error"), 1);
	return (0);
}

int	has_xpm_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if (!ft_strncmp(path + len - 4, ".xpm", 4) || len <= 4)
		return (1);
	return (0);
}
