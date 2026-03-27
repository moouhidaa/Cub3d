#include "../cub3d.h"

static int	check_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

static char	**read_all_lines(int fd, int *count)
{
	char	**lines;
	char	buf[8192];
	char	*big;
	char	*tmp;
	char	*next;
	ssize_t	n;
	int		i;

	big = ft_strdup("");
	if (!big)
		return (NULL);
	while ((n = read(fd, buf, sizeof(buf) - 1)) > 0)
	{
		buf[n] = '\0';
		tmp = ft_strjoin(big, buf);
		free(big);
		if (!tmp)
			return (NULL);
		big = tmp;
	}
	*count = 0;
	tmp = big;
	while (*tmp)
	{
		if (*tmp == '\n')
			(*count)++;
		tmp++;
	}
	if (ft_strlen(big) > 0 && big[ft_strlen(big) - 1] != '\n')
		(*count)++;
	lines = malloc((*count + 1) * sizeof(char *));
	if (!lines)
	{
		free(big);
		return (NULL);
	}
	i = 0;
	tmp = big;
	while (i < *count)
	{
		next = ft_strchr(tmp, '\n');
		if (next)
		{
			lines[i] = malloc(next - tmp + 1);
			if (!lines[i])
			{
				while (i > 0)
					free(lines[--i]);
				free(lines);
				free(big);
				return (NULL);
			}
			memcpy(lines[i], tmp, next - tmp);
			lines[i][next - tmp] = '\0';
			tmp = next + 1;
		}
		else
		{
			lines[i] = ft_strdup(tmp);
			tmp += ft_strlen(tmp);
		}
		i++;
	}
	lines[i] = NULL;
	free(big);
	return (lines);
}

static void	free_lines(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(lines[i++]);
	free(lines);
}

static int	find_map_start(char **lines, int total)
{
	int	i;
	int	j;

	i = 0;
	while (i < total)
	{
		j = 0;
		while (lines[i][j] == ' ' || lines[i][j] == '\t')
			j++;
		if (lines[i][j] == '1' || lines[i][j] == '0')
			return (i);
		i++;
	}
	return (-1);
}

int	parse_file(t_game *game, const char *filename)
{
	int		fd;
	int		total;
	char	**lines;
	int		i;
	int		map_found;
	int		map_start;

	if (!check_extension(filename))
		error_exit(ERR_EXT, NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_OPEN, NULL);
	lines = read_all_lines(fd, &total);
	close(fd);
	if (!lines)
		error_exit(ERR_MEM, NULL);
	map_found = 0;
	i = 0;
	while (i < total && !map_found)
	{
		if (parse_config_line(game, lines[i], &map_found) != 0)
		{
			free_lines(lines, total);
			error_exit(ERR_MAP, game);
		}
		i++;
	}
	map_start = find_map_start(lines, total);
	if (map_start < 0)
	{
		free_lines(lines, total);
		error_exit(ERR_MAP, game);
	}
	if (parse_map_lines(game, lines, map_start, total) != 0)
	{
		free_lines(lines, total);
		error_exit(ERR_MAP, game);
	}
	free_lines(lines, total);
	if (validate_map(game) != 0)
		error_exit(ERR_MAP, game);
	return (0);
}
