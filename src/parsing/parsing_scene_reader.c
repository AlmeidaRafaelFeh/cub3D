/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:14:09 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/03 19:12:45 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	process_line(t_scene *scene, char *line, int *map_started)
{
	if (is_blank_line(line))
	{
		if (!*map_started && header_complete(scene))
			return (0);
		return (1);
	}
	if (!*map_started)
	{
		if (!is_header_line(line) || store_header_line(scene, line))
			return (1);
		return (0);
	}
	if (!is_map_line(line) || append_row(scene, line))
		return (1);
	return (0);
}

int	collect_scene_data(int fd, t_scene *scene)
{
	char	*line;
	int		map_started;

	map_started = 0;
	line = get_next_line(fd);
	while (line)
	{
		normalize_line(line);
		if (!map_started && is_blank_line(line) && header_complete(scene))
			map_started = 1;
		else if (process_line(scene, line, &map_started))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (!(header_complete(scene) && map_started && scene->row_count > 0));
}
