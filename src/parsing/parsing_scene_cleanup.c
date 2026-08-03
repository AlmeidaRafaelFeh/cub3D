/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_cleanup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:13:48 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/03 18:55:53 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_scene_field(char **field)
{
	free(*field);
	*field = NULL;
}

void	free_scene_data(t_scene *scene)
{
	int	row;

	free_scene_field(&scene->north_texture);
	free_scene_field(&scene->south_texture);
	free_scene_field(&scene->west_texture);
	free_scene_field(&scene->east_texture);
	free_scene_field(&scene->floor_color);
	free_scene_field(&scene->ceiling_color);
	row = 0;
	while (scene->rows && row < scene->row_count)
	{
		free(scene->rows[row]);
		row++;
	}
	free(scene->rows);
	scene->rows = NULL;
	scene->row_count = 0;
}
