#include "../../cub3d.h"

static int	line_is_map(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '0'
			&& line[i] != '1' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

static int	max_line_len(char **lines, int start, int total)
{
	int	max;
	int	len;
	int	i;

	max = 0;
	i = start;
	while (i < total)
	{
		if (!line_is_map(lines[i]))
			break ;
		len = ft_strlen(lines[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	set_player_start(t_game *game, int row, int col, char dir)
{
	static int	found = 0;

	if (found)
		return (1);
	found = 1;
	game->player.pos_x = col + 0.5;
	game->player.pos_y = row + 0.5;
	if (dir == 'N')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = -1.0;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0.0;
	}
	else if (dir == 'S')
	{
		game->player.dir_x = 0.0;
		game->player.dir_y = 1.0;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0.0;
	}
	else if (dir == 'E')
	{
		game->player.dir_x = 1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->player.dir_x = -1.0;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0.0;
		game->player.plane_y = -0.66;
	}
	return (0);
}

int	parse_map_lines(t_game *game, char **lines, int start, int total)
{
	int		rows;
	int		cols;
	int		i;
	int		j;

	rows = 0;
	i = start;
	while (i < total && line_is_map(lines[i]))
	{
		rows++;
		i++;
	}
	if (rows == 0)
		return (1);
	cols = max_line_len(lines, start, total);
	game->map.rows = rows;
	game->map.cols = cols;
	game->map.grid = malloc(rows * sizeof(char *));
	if (!game->map.grid)
		return (1);
	i = 0;
	while (i < rows)
	{
		game->map.grid[i] = malloc(cols + 1);
		if (!game->map.grid[i])
			return (1);
		memset(game->map.grid[i], ' ', cols);
		game->map.grid[i][cols] = '\0';
		j = 0;
		while (lines[start + i][j] && lines[start + i][j] != '\r')
		{
			game->map.grid[i][j] = lines[start + i][j];
			j++;
		}
		i++;
	}
	return (0);
}
