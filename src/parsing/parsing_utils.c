/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:03:35 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/27 16:43:17 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	free_texture_path(char **path)
{
	if (*path)
	{
		free(*path);
		*path = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	if (!game)
		return ;
	free_texture_path(&game->north_texture);
	free_texture_path(&game->south_texture);
	free_texture_path(&game->west_texture);
	free_texture_path(&game->east_texture);
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

int	free_rows(char **rows, int row_count)
{
	int	row;

	row = 0;
	while (rows && row < row_count)
	{
		free(rows[row]);
		row++;
	}
	free(rows);
	return (0);
}
