#include "../../cub3d.h"

static int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' || c == ' ');
}

static int	flood_fill_check(t_game *game, char **visited, int row, int col)
{
	if (row < 0 || row >= game->map.rows
		|| col < 0 || col >= game->map.cols)
		return (1);
	if (visited[row][col])
		return (0);
	if (game->map.grid[row][col] == ' ')
		return (1);
	if (game->map.grid[row][col] == '1')
		return (0);
	visited[row][col] = 1;
	if (flood_fill_check(game, visited, row - 1, col))
		return (1);
	if (flood_fill_check(game, visited, row + 1, col))
		return (1);
	if (flood_fill_check(game, visited, row, col - 1))
		return (1);
	if (flood_fill_check(game, visited, row, col + 1))
		return (1);
	return (0);
}

static int	check_map_enclosed(t_game *game)
{
	char	**visited;
	int		i;
	int		j;
	int		result;

	visited = malloc(game->map.rows * sizeof(char *));
	if (!visited)
		return (1);
	i = 0;
	while (i < game->map.rows)
	{
		visited[i] = calloc(game->map.cols, 1);
		if (!visited[i])
		{
			while (i > 0)
				free(visited[--i]);
			free(visited);
			return (1);
		}
		i++;
	}
	result = flood_fill_check(game, visited,
		(int)game->player.pos_y, (int)game->player.pos_x);
	i = 0;
	while (i < game->map.rows)
		free(visited[i++]);
	free(visited);
	if (result)
		return (1);
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (!is_valid_char(game->map.grid[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_map(t_game *game)
{
	int		i;
	int		j;
	int		player_count;

	player_count = 0;
	i = 0;
	while (i < game->map.rows)
	{
		j = 0;
		while (j < game->map.cols)
		{
			if (!is_valid_char(game->map.grid[i][j]))
				return (1);
			if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S'
				|| game->map.grid[i][j] == 'E' || game->map.grid[i][j] == 'W')
			{
				player_count++;
				if (player_count > 1)
					return (1);
				set_player_start(game, i, j, game->map.grid[i][j]);
				game->map.grid[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
		return (1);
	if (game->map.tex_path[NORTH] == NULL || game->map.tex_path[SOUTH] == NULL
		|| game->map.tex_path[WEST] == NULL || game->map.tex_path[EAST] == NULL)
		return (1);
	if (game->map.floor_color < 0 || game->map.ceil_color < 0)
		return (1);
	return (check_map_enclosed(game));
}
