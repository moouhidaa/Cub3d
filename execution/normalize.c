/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/03/26 08:02:50 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/cub3d.h"

double	no_angle(double angle)
{
	double	r;

	r = fmod(angle, (2 * PI));
	if (r < 0)
		r += (2 * PI);
	return (r);
}

double	get_the_distance(double px, double py, double interx, double intery)
{
	return (sqrt((px - interx) * (px - interx) + (py - intery) * (py
				- intery)));
}
