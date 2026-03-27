/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture_to_xpm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <moouhida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 08:34:13 by moouhida          #+#    #+#             */
/*   Updated: 2026/01/04 11:13:36 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ray_going_down(double ray_angle)
{
	return (ray_angle > 0 && ray_angle < PI);
}

int	ray_going_right(double ray_angle)
{
	return (ray_angle < PI / 2 || ray_angle > 3 * PI / 2);
}

void	intersection_steps(double *x_step, double *y_step, double angle,
		int type)
{
	int	ex;

	ex = 1;
	if (type == 0)
	{
		if (!ray_going_down(angle))
			ex = -1;
		*y_step = TILE * ex;
		*x_step = *y_step / tan(angle);
		if (cos(angle) < 0 && *x_step > 0)
			*x_step *= -1;
		if (cos(angle) > 0 && *x_step < 0)
			*x_step *= -1;
	}
	else
	{
		if (cos(angle) < 0)
			ex = -1;
		*x_step = TILE * ex;
		*y_step = *x_step * tan(angle);
		if (!ray_going_down(angle) && *y_step > 0)
			*y_step *= -1;
		if (ray_going_down(angle) && *y_step < 0)
			*y_step *= -1;
	}
}
