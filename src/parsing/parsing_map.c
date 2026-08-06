/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:46:42 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 10:46:45 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	starting_copy(char **rows, int row, int col, t_game *game)
{
	char	current;

	current = rows[row][col];
	if (!is_valid_char(current))
		return (1);
	game->map[row][col] = current;
	if (current == 'N' || current == 'S' || current == 'E' || current == 'W')
	{
		if (set_player_position(game, col, row, current))
			return (1);
		game->map[row][col] = '0';
	}
	return (0);
}

static int	copy_row(char **rows, int row, int max_width, t_game *game)
{
	int	col;
	int	len;

	col = 0;
	len = get_row_len(rows[row]);
	while (col < max_width)
	{
		if (!rows[row] || col >= len)
			game->map[row][col] = '0';
		else if (rows[row][col] == ' ' || rows[row][col] == '\t')
			game->map[row][col] = '0';
		else
		{
			if (starting_copy(rows, row, col, game))
				return (1);
		}
		col++;
	}
	game->map[row][col] = '\0';
	return (0);
}

static int	fill_map(char **rows, int row_count, int max_width, t_game *game)
{
	int	row;

	row = 0;
	while (row < row_count)
	{
		if (copy_row(rows, row, max_width, game))
			return (1);
		row++;
	}
	return (0);
}

int	parse_map_from_rows(char **rows, int row_count, t_game *game)
{
	int	max_width;
	int	player_count;

	if (!rows || !game || row_count <= 0)
		return (1);
	free_map(game);
	max_width = get_max_width(rows, row_count);
	game->map = alloc_map(row_count, max_width);
	if (!game->map)
		return (1);
	game->map_h = row_count;
	game->map_w = max_width;
	game->player.moves = 0;
	if (fill_map(rows, row_count, max_width, game))
		return (free_map(game), 1);
	player_count = count_players(rows, row_count);
	if (player_count != 1 || game->player.moves != 1)
		return (free_map(game), 1);
	return (0);
}
