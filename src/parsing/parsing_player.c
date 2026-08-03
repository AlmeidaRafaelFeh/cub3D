/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:22:04 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/03 by tmfanfa                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	set_player_position(t_game *game, int x, int y, char orientation)
{
	if (game->player.moves == 1)
		return (1);
	game->player.x = x;
	game->player.y = y;
	game->player.orientation = orientation;
	game->player.moves = 1;
	return (0);
}

int	count_players(char **rows, int row_count)
{
	int	row;
	int	col;
	int	count;
	int	len;

	row = 0;
	count = 0;
	while (row < row_count)
	{
		col = 0;
		len = get_row_len(rows[row]);
		while (col < len)
		{
			if (rows[row][col] == 'N' || rows[row][col] == 'S'
				|| rows[row][col] == 'E' || rows[row][col] == 'W')
				count++;
			col++;
		}
		row++;
	}
	return (count);
}
