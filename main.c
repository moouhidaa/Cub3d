/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:07:14 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "include/cub3d.h"

int	check_name(char *name)
{
	int	len;

	len = ft_strlen(name) - 1;
	if (name[len] != 'b' || name[len - 1] != 'u' || name[len - 2] != 'c'
		|| name[len - 3] != '.')
		return (1);
	return (0);
}

void	ft_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

int	main(int ac, char **av)
{
	t_hulk	*game;

	if (ac != 2 || check_name(av[1]))
		return (ft_error(MAX_ARGS), 1);
	game = my_malloc(sizeof(t_hulk));
	ft_memset(game, 0, sizeof(t_hulk));
	if (!game)
		return (ft_error("Error"), 1);
	if (parse_cub3d(av[1], game) || init_player(game))
		return (my_free(), 1);
	launch_the_mlx(game);
	return (0);
}
