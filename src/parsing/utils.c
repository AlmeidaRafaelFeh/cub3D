/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:03:35 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/02 16:17:27 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->map_h)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
	game->map_w = 0;
	game->map_h = 0;
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W');
}

void	destroy_all(t_scene *scene, t_game *game)
{
	free_scene_data(scene);
	free_map(game);
	return ;
}
