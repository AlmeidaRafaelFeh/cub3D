/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:02:18 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/02 15:05:11 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	parsing_main(char *file_path)
{
	t_scene	scene;
	t_game	game;
	int		fd;

	if (!file_path)
		return (1);
	ft_memset(&scene, 0, sizeof(scene));
	ft_memset(&game, 0, sizeof(game));
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (collect_scene_data(fd, &scene)
		|| parse_map_from_rows(scene.rows, scene.row_count, &game))
	{
		close(fd);
		free_scene_data(&scene);
		return (1);
	}
	close(fd);
	free_scene_data(&scene);
	free_map(&game);
	return (0);
}
