/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_reader.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:14:09 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 10:18:44 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	handle_non_blank_line(t_scene *scene, char *line,
				int *map_started, int map_ended)
{
	if (!header_complete(scene))
	{
		if (!is_header_line(line) || store_header_line(scene, line))
			return (1);
		return (0);
	}
	if (map_ended)
		return (1);
	if (!is_map_line(line) || append_row(scene, line))
		return (1);
	*map_started = 1;
	return (0);
}

int	collect_scene_data(int fd, t_scene *scene)
{
	char	*line;
	int		map_started;
	int		map_ended;

	map_started = 0;
	map_ended = 0;
	line = get_next_line(fd);
	while (line)
	{
		normalize_line(line);
		if (is_blank_line(line))
		{
			if (map_started)
				map_ended = 1;
		}
		else if (handle_non_blank_line(scene, line, &map_started, map_ended))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (!(header_complete(scene) && map_started && scene->row_count > 0));
}
