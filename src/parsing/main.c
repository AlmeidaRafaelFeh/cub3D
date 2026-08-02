/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:02:18 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/02 16:33:47 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	parsing_cleanup(int fd, t_scene *scene, t_game *game, int status)
{
	if (fd >= 0)
		close(fd);
	destroy_all(scene, game);
	return (status);
}

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
		return (parsing_error("Error: cannot open scene file"));
	if (collect_scene_data(fd, &scene))
		return (parsing_cleanup(fd, &scene, &game,
				parsing_error("Invalid scene: malformed header or map")));
	if (parse_map_from_rows(scene.rows, scene.row_count, &game))
		return (parsing_cleanup(fd, &scene, &game, 1));
	return (parsing_cleanup(fd, &scene, &game, 0));
}
