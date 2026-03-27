/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:29:45 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 09:29:46 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_invalid_path(char *path)
{
	char	**res;
	int		i;

	res = ft_split(path, ' ');
	i = 0;
	while (res[i])
		i++;
	if (i != 1)
		return (1);
	return (0);
}

char	*extract_path(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	res = ft_strdup(line + i);
	if (ft_invalid_path(res) == 1)
		return (NULL);
	return (res);
}

int	read_textures_and_colors(char *file, t_hulk *game)
{
	char	*line;
	char	*tab;
	char	**map;
	int		count;

	count = 0;
	game->fd = open(file, O_RDONLY);
	if (game->fd == -1)
		return (BAD_M);
	map = NULL;
	line = get_next_line(game->fd);
	while (line && count < 6)
	{
		tab = ft_strtrim(line, " \t\r\n");
		if (tab[0] != '\0')
		{
			map = my_realloc(map, tab);
			count++;
		}
		if (count < 6)
			line = get_next_line(game->fd);
	}
	if (ft_path(map, game))
		return (BAD_M);
	return (GOOD_M);
}
