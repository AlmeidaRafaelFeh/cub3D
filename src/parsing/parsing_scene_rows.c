/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_scene_rows.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:14:21 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 10:18:30 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	append_row(t_scene *scene, char *line)
{
	char	**new_rows;
	char	*copy;
	int		index;

	copy = ft_strdup(line);
	if (!copy)
		return (1);
	new_rows = malloc(sizeof(char *) * (scene->row_count + 2));
	if (!new_rows)
	{
		free(copy);
		return (1);
	}
	index = 0;
	while (index < scene->row_count)
	{
		new_rows[index] = scene->rows[index];
		index++;
	}
	new_rows[scene->row_count] = copy;
	new_rows[scene->row_count + 1] = NULL;
	free(scene->rows);
	scene->rows = new_rows;
	scene->row_count++;
	return (0);
}
