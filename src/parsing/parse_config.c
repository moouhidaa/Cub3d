#include "../../cub3d.h"

static int	parse_texture(t_game *game, char *line, int idx)
{
	char	*path;
	int		i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (!line[i])
		return (1);
	path = ft_strtrim(line + i, " \t\n\r");
	if (!path || ft_strlen(path) == 0)
	{
		if (path)
			free(path);
		return (1);
	}
	if (game->map.tex_path[idx])
	{
		free(path);
		return (1);
	}
	game->map.tex_path[idx] = path;
	return (0);
}

static int	parse_color(int *color, char *line)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(line, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
	{
		ft_free_split(parts);
		return (1);
	}
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	ft_free_split(parts);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	*color = create_color(r, g, b);
	return (0);
}

static int	handle_identifier(t_game *game, char *id, char *rest)
{
	if (ft_strcmp(id, "NO") == 0)
		return (parse_texture(game, rest, NORTH));
	if (ft_strcmp(id, "SO") == 0)
		return (parse_texture(game, rest, SOUTH));
	if (ft_strcmp(id, "WE") == 0)
		return (parse_texture(game, rest, WEST));
	if (ft_strcmp(id, "EA") == 0)
		return (parse_texture(game, rest, EAST));
	if (ft_strcmp(id, "F") == 0)
		return (parse_color(&game->map.floor_color, rest));
	if (ft_strcmp(id, "C") == 0)
		return (parse_color(&game->map.ceil_color, rest));
	return (1);
}

int	parse_config_line(t_game *game, char *line, int *map_found)
{
	char	*trimmed;
	int		i;
	char	id[8];

	trimmed = ft_strtrim(line, " \t\r\n");
	if (!trimmed)
		return (1);
	if (trimmed[0] == '\0')
	{
		free(trimmed);
		return (0);
	}
	if (trimmed[0] == '1' || trimmed[0] == '0' || trimmed[0] == ' ')
	{
		*map_found = 1;
		free(trimmed);
		return (0);
	}
	i = 0;
	while (trimmed[i] && trimmed[i] != ' ' && trimmed[i] != '\t' && i < 7)
	{
		id[i] = trimmed[i];
		i++;
	}
	id[i] = '\0';
	if (handle_identifier(game, id, trimmed + i) != 0)
	{
		free(trimmed);
		return (1);
	}
	free(trimmed);
	return (0);
}
