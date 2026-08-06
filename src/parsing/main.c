/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:02:18 by rafreire          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/02 15:05:11 by rafreire         ###   ########.fr       */
=======
/*   Updated: 2026/08/03 by tmfanfa                 ###   ########.fr       */
>>>>>>> tai-merge
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD
int	parsing_main(char *file_path)
{
	t_scene	scene;
	t_game	game;
	int		fd;

	if (!file_path)
		return (1);
	ft_memset(&scene, 0, sizeof(scene));
	ft_memset(&game, 0, sizeof(game));
=======
int	parsing_main(char *file_path, t_game *game)
{
	t_scene	scene;
	int		fd;

	if (!file_path || !game)
		return (1);
	ft_memset(&scene, 0, sizeof(scene));
>>>>>>> tai-merge
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (1);
	if (collect_scene_data(fd, &scene)
<<<<<<< HEAD
		|| parse_map_from_rows(scene.rows, scene.row_count, &game))
=======
		|| parse_map_from_rows(scene.rows, scene.row_count, game))
>>>>>>> tai-merge
	{
		close(fd);
		free_scene_data(&scene);
		return (1);
	}
	close(fd);
	free_scene_data(&scene);
<<<<<<< HEAD
	free_map(&game);
=======
>>>>>>> tai-merge
	return (0);
}
