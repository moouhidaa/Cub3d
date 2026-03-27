/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouhida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 07:57:51 by moouhida          #+#    #+#             */
/*   Updated: 2024/12/26 04:19:42 by moouhida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_after_line(char *str)
{
	size_t	i;
	char	*new_str;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	new_str = ft_start(str, i + 1, ft_strlen(str) - i);
	str[i + 1] = '\0';
	return (new_str);
}

char	*get_ref_fd(int fd, char *str, char *buffer)
{
	char	*takestr;
	ssize_t	i;

	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, (size_t)BUFFER_SIZE);
		if (i < 0)
		{
			free(str);
			return (NULL);
		}
		buffer[i] = '\0';
		if (i == 0)
			return (str);
		takestr = str;
		str = ft_strjoin(takestr, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > 1024)
		return (NULL);
	buffer = my_malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	line = get_ref_fd(fd, str, buffer);
	if (!line)
		return (NULL);
	if (*line == '\0')
		return (NULL);
	str = get_after_line(line);
	return (line);
}
