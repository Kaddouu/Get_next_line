/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilkaddou <ilkaddou@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:54:38 by ilkaddou          #+#    #+#             */
/*   Updated: 2024/11/29 00:50:25 by ilkaddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buffer_to_cache(int fd, char *cache)
{
	char	*buffer;
	int		reader;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader = 1;
	while (!ft_strchr(cache, '\n') && reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
			return (free(cache), free(buffer), NULL);
		buffer[reader] = '\0';
		temp = ft_strjoin(cache, buffer);
		if (!temp)
			return (free(buffer), free(cache), NULL);
		free(cache);
		cache = temp;
	}
	free(buffer);
	return (cache);
}

char	*cache_to_line(char **cache)
{
	size_t	i;
	char	*line;
	char	*temp;

	i = 0;
	if (!*cache || **cache == 0)
		return (NULL);
	while ((*cache)[i] && (*cache)[i] != '\n')
		i++;
	line = ft_substr(*cache, 0, i + ((*cache)[i] == '\n'));
	if (!line)
		return (free(*cache), NULL);
	temp = ft_substr(*cache, i + ((*cache)[i] == '\n'), ft_strlen(*cache) - (i
				+ ((*cache)[i] == '\n')));
	if (!temp)
		return (free(line), free(*cache), NULL);
	free(*cache);
	*cache = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*cache[FD_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FD_MAX)
	{
		return (NULL);
	}
	if (!cache[fd])
	{
		cache[fd] = malloc(1);
		if (cache[fd])
			cache[fd][0] = 0;
	}
	if (!cache[fd])
		return (NULL);
	cache[fd] = buffer_to_cache(fd, cache[fd]);
	if (!cache[fd] || !*cache[fd])
		return (NULL);
	return (cache_to_line(&cache[fd]));
}
