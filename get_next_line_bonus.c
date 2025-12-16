/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebavaro <sebavaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:50:40 by sebavaro          #+#    #+#             */
/*   Updated: 2025/12/16 14:06:13 by sebavaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*read_and_stash(int fd, char *stash)
{
	int		byte_read;
	char	*buffer;

	if (!stash)
		stash = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free (stash);
			free (buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		stash = ft_strjoin(stash, buffer);
		if (ft_strchr (buffer, '\n'))
			break ;
	}
	free (buffer);
	return (stash);
}

char	*get_the_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i ++;
	if (stash[i] == '\n')
		i ++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i ++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*the_next_line(char *stash)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i ++;
	next_line = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	while (stash[i])
	{
		next_line[j] = stash[i];
		j ++;
		i ++;
	}
	next_line[j] = 0;
	free(stash);
	return (next_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*the_buffer[1024];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	the_buffer[fd] = read_and_stash(fd, the_buffer[fd]);
	if (!the_buffer[fd])
		return (NULL);
	line = get_the_line(the_buffer[fd]);
	the_buffer[fd] = the_next_line(the_buffer[fd]);
	return (line);
}
