/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:13:59 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/02 15:14:03 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	store_header_value(char **field, char *line, int offset)
{
	char	*value;

	value = ft_strdup(skip_spaces(line + offset));
	if (!value || !*value)
	{
		free(value);
		return (1);
	}
	if (*field)
	{
		free(value);
		return (1);
	}
	*field = value;
	return (0);
}

int	store_header_line(t_scene *scene, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (store_header_value(&scene->north_texture, line, 2));
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (store_header_value(&scene->south_texture, line, 2));
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (store_header_value(&scene->west_texture, line, 2));
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (store_header_value(&scene->east_texture, line, 2));
	if (ft_strncmp(line, "F ", 2) == 0)
		return (store_header_value(&scene->floor_color, line, 1));
	if (ft_strncmp(line, "C ", 2) == 0)
		return (store_header_value(&scene->ceiling_color, line, 1));
	return (1);
}

int	header_complete(t_scene *scene)
{
	return (scene->north_texture && scene->south_texture && scene->west_texture
		&& scene->east_texture && scene->floor_color && scene->ceiling_color);
}
