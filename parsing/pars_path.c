/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brbaazi <brbaazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:29:52 by brbaazi           #+#    #+#             */
/*   Updated: 2026/01/07 09:49:27 by brbaazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	mini_atoi(char *n, int *i)
{
	int	num;

	num = 0;
	while (n[*i] >= '0' && n[*i] <= '9')
	{
		num = num * 10 + (n[*i] - '0');
		(*i)++;
	}
	return (num);
}

int	validhelp(char *s, int *i)
{
	if (s[*i] == ',')
	{
		(*i)++;
		while (s[*i] == ' ')
			(*i)++;
		if (!ft_isdigit(s[*i]))
			return (0);
	}
	else if (s[*i] != '\0')
		return (0);
	return (1);
}

static void	init_v(t_counters *c)
{
	c->no = 0;
	c->so = 0;
	c->we = 0;
	c->ea = 0;
	c->f = 0;
	c->c = 0;
}

int	check_duplicates(char **paths)
{
	t_counters	*count;

	count = my_malloc(sizeof(t_counters));
	if (!count)
		return (1);
	init_v(count);
	if (check_if_duplicate(paths, count))
		return (1);
	if (count->no != 1 || count->so != 1 || count->we != 1 || count->ea != 1
		|| count->f != 1 || count->c != 1)
	{
		ft_error("Error");
		return (1);
	}
	return (0);
}

int	ft_validcolor(char *s)
{
	int	i;
	int	count;
	int	num;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == ' ')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		num = mini_atoi(s, &i);
		if (num < 0 || num > 255)
			return (0);
		count++;
		while (s[i] == ' ')
			i++;
		if (!validhelp(s, &i))
			return (0);
	}
	return (count == 3);
}
