/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:13:59 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 10:18:23 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parse_component(char **str, int *val)
{
	long	num;

	*str = skip_spaces(*str);
	if (!ft_isdigit(**str))
		return (1);
	num = 0;
	while (ft_isdigit(**str))
	{
		num = num * 10 + (**str - '0');
		if (num > 255)
			return (1);
		(*str)++;
	}
	*str = skip_spaces(*str);
	*val = (int)num;
	return (0);
}

int	parse_rgb(char *str, int *color_out)
{
	int	r;
	int	g;
	int	b;

	if (!str)
		return (1);
	if (parse_component(&str, &r))
		return (1);
	if (*str != ',')
		return (1);
	str++;
	if (parse_component(&str, &g))
		return (1);
	if (*str != ',')
		return (1);
	str++;
	if (parse_component(&str, &b))
		return (1);
	if (*str != '\0')
		return (1);
	*color_out = (r << 16) | (g << 8) | b;
	return (0);
}

static int	store_texture(char **field, char *str)
{
	char	*path;

	if (*field != NULL)
		return (1);
	path = skip_spaces(str);
	if (!*path)
		return (1);
	*field = ft_strdup(path);
	if (!*field)
		return (1);
	return (0);
}

int	store_header_line(t_scene *scene, char *line)
{
	char	*p;

	p = skip_spaces(line);
	if (ft_strncmp(p, "NO", 2) == 0 && (p[2] == ' ' || p[2] == '\t'))
		return (store_texture(&scene->north_texture, p + 2));
	if (ft_strncmp(p, "SO", 2) == 0 && (p[2] == ' ' || p[2] == '\t'))
		return (store_texture(&scene->south_texture, p + 2));
	if (ft_strncmp(p, "WE", 2) == 0 && (p[2] == ' ' || p[2] == '\t'))
		return (store_texture(&scene->west_texture, p + 2));
	if (ft_strncmp(p, "EA", 2) == 0 && (p[2] == ' ' || p[2] == '\t'))
		return (store_texture(&scene->east_texture, p + 2));
	if (ft_strncmp(p, "F", 1) == 0 && (p[1] == ' ' || p[1] == '\t'))
	{
		if (scene->floor_set || parse_rgb(p + 1, &scene->floor_color))
			return (1);
		return (scene->floor_set = 1, 0);
	}
	if (ft_strncmp(p, "C", 1) == 0 && (p[1] == ' ' || p[1] == '\t'))
	{
		if (scene->ceiling_set || parse_rgb(p + 1, &scene->ceiling_color))
			return (1);
		return (scene->ceiling_set = 1, 0);
	}
	return (1);
}

int	header_complete(t_scene *scene)
{
	return (scene->north_texture && scene->south_texture
		&& scene->west_texture && scene->east_texture
		&& scene->floor_set && scene->ceiling_set);
}
