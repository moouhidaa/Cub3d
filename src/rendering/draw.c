#include "../../cub3d.h"

void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	char	*src;

	if (x < 0 || x >= img->width || y < 0 || y >= img->height)
		return (0);
	src = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(int *)src);
}

int	create_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	draw_ceiling_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_put(&game->screen, x, y, game->map.ceil_color);
			x++;
		}
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel_put(&game->screen, x, y, game->map.floor_color);
			x++;
		}
		y++;
	}
}
