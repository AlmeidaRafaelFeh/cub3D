/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_flood.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:47:24 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/02 16:32:43 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**duplicate_map(char **map, int height)
{
	char	**copy;
	int		row;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	row = 0;
	while (row < height)
	{
		copy[row] = ft_strdup(map[row]);
		if (!copy[row])
		{
			while (row-- > 0)
				free(copy[row]);
			free(copy);
			return (NULL);
		}
		row++;
	}
	copy[row] = NULL;
	return (copy);
}

static void	free_map_copy(char **map_copy, int height)
{
	int	row;

	row = 0;
	while (row < height)
	{
		free(map_copy[row]);
		row++;
	}
	free(map_copy);
}

static int	flood_fill(t_flood *flood, int x, int y)
{
	if (x < 0 || y < 0 || x >= flood->width || y >= flood->height)
		return (1);
	if (flood->map[y][x] == '1' || flood->map[y][x] == 'X')
		return (0);
	if (flood->map[y][x] != '0')
		return (1);
	flood->map[y][x] = 'X';
	if (flood_fill(flood, x + 1, y))
		return (1);
	if (flood_fill(flood, x - 1, y))
		return (1);
	if (flood_fill(flood, x, y + 1))
		return (1);
	if (flood_fill(flood, x, y - 1))
		return (1);
	return (0);
}

int	validate_map_flood(t_game *game)
{
	t_flood	flood;
	int		result;

	flood.map = duplicate_map(game->map, game->map_h);
	if (!flood.map)
		return (parsing_error("Invalid map: flood fill allocation failed"));
	flood.width = game->map_w;
	flood.height = game->map_h;
	flood.x = game->player.x;
	flood.y = game->player.y;
	result = flood_fill(&flood, flood.x, flood.y);
	free_map_copy(flood.map, game->map_h);
	if (result)
		return (parsing_error("Invalid map: map is not closed"));
	return (0);
}
