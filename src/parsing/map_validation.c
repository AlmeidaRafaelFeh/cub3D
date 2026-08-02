/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:47:13 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/02 15:47:47 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_wall_row(char *row, int width)
{
	int	index;

	index = 0;
	while (index < width)
	{
		if (row[index] != '1')
			return (0);
		index++;
	}
	return (1);
}

static int	is_side_walled(char *row, int width)
{
	return (row[0] == '1' && row[width - 1] == '1');
}

int	validate_map_closed(t_game *game)
{
	int	row;

	if (!game || !game->map || game->map_h <= 0 || game->map_w <= 0)
		return (parsing_error("Invalid map: missing map data"));
	if (!is_wall_row(game->map[0], game->map_w)
		|| !is_wall_row(game->map[game->map_h - 1], game->map_w))
		return (parsing_error("Invalid map: top or bottom border is open"));
	row = 0;
	while (row < game->map_h)
	{
		if (!is_side_walled(game->map[row], game->map_w))
			return (parsing_error("Invalid map: side border is open"));
		row++;
	}
	return (0);
}

int	validate_parsed_map(t_game *game)
{
	if (validate_map_closed(game))
		return (1);
	if (validate_map_flood(game))
		return (1);
	return (0);
}
