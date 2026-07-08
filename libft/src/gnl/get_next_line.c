/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 08:45:09 by rafreire          #+#    #+#             */
/*   Updated: 2026/07/08 08:45:22 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*content;
	char		*line;
	char		*buffer;

	buffer = malloc(BUFFER_SIZE +1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer);
		return (NULL);
	}
	content = ft_read_append(fd, content, buffer);
	if (!content)
		return (NULL);
	line = validate_line(&content);
	if (!line)
	{
		free (content);
		return (NULL);
	}
	return (line);
}

char	*ft_read_append(int fd, char *content, char *buffer)
{
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while ((content == NULL || !ft_strchr(content, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 && content != NULL)
			return (free(buffer), content);
		if (bytes_read <= 0)
			return (free_mem((void **)&buffer, (void **)&content));
		buffer[bytes_read] = '\0';
		if (content == NULL)
			content = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(content, buffer);
			free(content);
			content = temp;
		}
	}
	return (free(buffer), content);
}

char	*validate_line(char **content)
{
	char	*new_line;
	char	*line;
	char	*residue;

	new_line = ft_strchr(*content, '\n');
	if (!new_line)
	{
		line = ft_strdup(*content);
		free_mem ((void **)content, NULL);
		return (line);
	}
	else
	{
		line = ft_substr(*content, 0, (new_line - *content + 1));
		residue = ft_strdup(new_line +1);
		free (*content);
		if (residue[0] == '\0')
		{
			free (residue);
			*content = NULL;
		}
		else
			*content = residue;
		return (line);
	}
}

void	*free_mem(void **ptr1, void **ptr2)
{
	if (ptr1 && *ptr1)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (ptr2 && *ptr2)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
	return (NULL);
}
