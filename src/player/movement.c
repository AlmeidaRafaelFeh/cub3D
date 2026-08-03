/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:28:42 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/08/03 by tmfanfa                 ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

# define MOVE_SPEED 0.05
# define ROT_SPEED 0.03

// move o player com as teclas WASD
// W/S andam para frente/tras na direcao que o jogador olha (dir_x, dir_y)
// A/D andam para os lados usando o vetor perpendicular à direcao (ta na função de baixo)
// AINDA NÃO TEM checagem de colisao com parede — isso e da parte lá de verificações
void	move_player(t_game *game)
{
	if (game->keys.w)
	{
		game->player.x += game->player.dir_x * MOVE_SPEED;
		game->player.y += game->player.dir_y * MOVE_SPEED;
	}
	if (game->keys.s)
	{
		game->player.x -= game->player.dir_x * MOVE_SPEED;
		game->player.y -= game->player.dir_y * MOVE_SPEED;
	}
	if (game->keys.a)
	{
		game->player.x += game->player.dir_y * MOVE_SPEED;
		game->player.y -= game->player.dir_x * MOVE_SPEED;
	}
	if (game->keys.d)
	{
		game->player.x -= game->player.dir_y * MOVE_SPEED;
		game->player.y += game->player.dir_x * MOVE_SPEED;
	}
}

// gira o vetor de direcao e o plano da camera por "angle" radianos,
// usando uma matriz de rotacao 2D (ângulo positivo gira para a direita, negativo gira para a esquerda)
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

// função principal da rotação
// roda o player com as setas esquerda/direita quando estiverem pressionadas
void	rotate_player(t_game *game)
{
	if (game->keys.left)
		rotate_by(&game->player, -ROT_SPEED);
	if (game->keys.right)
		rotate_by(&game->player, ROT_SPEED);
}

// atualiza posiçãoo e rotação do player conforme as teclas que forem
// pressionadas naquele instante (roda isso uma vez por frame)
void	update_player(t_game *game)
{
	move_player(game);
	rotate_player(game);
}
