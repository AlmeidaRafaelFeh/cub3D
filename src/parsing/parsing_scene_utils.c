/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:14:32 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 10:18:18 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_blank_line(char *line)
{
	int	index;

	if (!line)
		return (1);
	index = 0;
	while (line[index])
	{
		if (line[index] != ' ' && line[index] != '\t'
			&& line[index] != '\r' && line[index] != '\n')
			return (0);
		index++;
	}
	return (1);
}

void	normalize_line(char *line)
{
	int	index;

	index = 0;
	while (line && line[index])
	{
		if (line[index] == '\t')
			line[index] = ' ';
		if (line[index] == '\n' || line[index] == '\r')
		{
			line[index] = '\0';
			break ;
		}
		index++;
	}
}

char	*skip_spaces(char *line)
{
	while (line && (*line == ' ' || *line == '\t'))
		line++;
	return (line);
}

int	is_header_line(char *line)
{
	char	*p;

	p = skip_spaces(line);
	if (!p || !*p)
		return (0);
	if ((ft_strncmp(p, "NO", 2) == 0 || ft_strncmp(p, "SO", 2) == 0
			|| ft_strncmp(p, "WE", 2) == 0 || ft_strncmp(p, "EA", 2) == 0)
		&& (p[2] == ' ' || p[2] == '\t'))
		return (1);
	if ((ft_strncmp(p, "F", 1) == 0 || ft_strncmp(p, "C", 1) == 0)
		&& (p[1] == ' ' || p[1] == '\t'))
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	index;
	int	has_content;

	if (!line || !*line)
		return (0);
	index = 0;
	has_content = 0;
	while (line[index])
	{
		if (line[index] == '0' || line[index] == '1' || line[index] == 'N'
			|| line[index] == 'S' || line[index] == 'E' || line[index] == 'W')
			has_content = 1;
		else if (line[index] != ' ' && line[index] != '\t')
			return (0);
		index++;
	}
	return (has_content);
}
