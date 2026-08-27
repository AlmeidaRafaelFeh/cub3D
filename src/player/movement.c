/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:35:14 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 14:46:28 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define MOVE_SPEED 0.05
#define ROT_SPEED 0.03

static int	is_wall(t_game *game, double x, double y)
{
	int	col;
	int	row;

	col = (int)x;
	row = (int)y;
	if (row < 0 || row >= game->map_h || col < 0 || col >= game->map_w)
		return (1);
	if (!game->map[row] || col >= (int)ft_strlen(game->map[row]))
		return (1);
	return (game->map[row][col] != '0');
}

static void	try_move(t_game *game, double dx, double dy)
{
	if (!is_wall(game, game->player.x + dx, game->player.y))
		game->player.x += dx;
	if (!is_wall(game, game->player.x, game->player.y + dy))
		game->player.y += dy;
}

void	move_player(t_game *game)
{
	if (game->keys.w)
		try_move(game, game->player.dir_x * MOVE_SPEED,
			game->player.dir_y * MOVE_SPEED);
	if (game->keys.s)
		try_move(game, -game->player.dir_x * MOVE_SPEED,
			-game->player.dir_y * MOVE_SPEED);
	if (game->keys.a)
		try_move(game, game->player.dir_y * MOVE_SPEED,
			-game->player.dir_x * MOVE_SPEED);
	if (game->keys.d)
		try_move(game, -game->player.dir_y * MOVE_SPEED,
			game->player.dir_x * MOVE_SPEED);
}

static void	rotate_by(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_dir_x * sin(angle) + player->dir_y * cos(angle);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(angle)
		- player->plane_y * sin(angle);
	player->plane_y = old_plane_x * sin(angle) + player->plane_y * cos(angle);
}

void	rotate_player(t_game *game)
{
	if (game->keys.left)
		rotate_by(&game->player, -ROT_SPEED);
	if (game->keys.right)
		rotate_by(&game->player, ROT_SPEED);
}
