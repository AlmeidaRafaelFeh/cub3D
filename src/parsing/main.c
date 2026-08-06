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

int	parsing_main(char *file_path, t_game *game)
{
	t_scene	scene;
	int		fd;

	if (!file_path || !game)
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
	free_scene_data(&scene);
	return (0);
}
