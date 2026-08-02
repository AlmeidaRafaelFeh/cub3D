/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:14:32 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/02 15:14:34 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_blank_line(char *line)
{
	int	index;

	index = 0;
	while (line && line[index])
	{
		if (line[index] != ' ')
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
	while (line && *line == ' ')
		line++;
	return (line);
}

int	is_header_line(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0);
}

int	is_map_line(char *line)
{
	int	index;

	index = 0;
	if (!line || !*line)
		return (0);
	while (line[index])
	{
		if (line[index] != '0' && line[index] != '1' && line[index] != 'N'
			&& line[index] != 'S' && line[index] != 'E' && line[index] != 'W'
			&& line[index] != ' ')
			return (0);
		index++;
	}
	return (1);
}
