/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:56:27 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 10:56:29 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_file_extension(char *path)
{
	int	len;

	if (!path)
		return (1);
	len = ft_strlen(path);
	if (len < 4)
		return (1);
	if (ft_strncmp(path + len - 4, ".cub", 4) != 0)
		return (1);
	if (len > 4 && path[len - 5] == '/')
		return (1);
	return (0);
}

int	parsing_main(char *file_path, t_game *game)
{
	t_scene	scene;
	int		fd;

	if (!file_path || !game || check_file_extension(file_path))
		return (1);
	ft_memset(&scene, 0, sizeof(scene));
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (collect_scene_data(fd, &scene)
		|| parse_map_from_rows(scene.rows, scene.row_count, game))
	{
		close(fd);
		free_scene_data(&scene);
		return (1);
	}
	close(fd);
	game->north_texture = scene.north_texture;
	game->south_texture = scene.south_texture;
	game->west_texture = scene.west_texture;
	game->east_texture = scene.east_texture;
	game->floor_color = scene.floor_color;
	game->ceiling_color = scene.ceiling_color;
	scene.north_texture = NULL;
	scene.south_texture = NULL;
	scene.west_texture = NULL;
	scene.east_texture = NULL;
	free_scene_data(&scene);
	return (0);
}
