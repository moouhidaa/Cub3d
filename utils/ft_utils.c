#include "../cub3d.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		len;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	memcpy(dup, s, len + 1);
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		len1;
	int		len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	memcpy(res, s1, len1);
	memcpy(res + len1, s2, len2 + 1);
	return (res);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

int	ft_atoi(const char *s)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (sign * result);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*res;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	res = malloc(end - start + 1);
	if (!res)
		return (NULL);
	memcpy(res, s1 + start, end - start);
	res[end - start] = '\0';
	return (res);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		start;
	int		words;

	words = count_words(s, c);
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		start = 0;
		while (s[start] && s[start] != c)
			start++;
		res[i] = malloc(start + 1);
		if (!res[i])
		{
			while (i > 0)
				free(res[--i]);
			free(res);
			return (NULL);
		}
		memcpy(res[i], s, start);
		res[i][start] = '\0';
		i++;
		s += start;
	}
	res[i] = NULL;
	return (res);
}

void	ft_free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
