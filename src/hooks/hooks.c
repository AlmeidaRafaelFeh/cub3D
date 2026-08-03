/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:08:42 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/07/29 15:25:48 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// seta todas as teclas pra 0 (tipo sem estarem pressionadas) no inicio do jogo
void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}


// fecha a janela e encerra (libera a imagem e a janela antes de sair)
//  ainda não implementei pra janela fechar no X
static void	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->screen.img);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

// liga a flag quando uma tecla é pressionada
// ESC fecha o jogo na hora
// as outras teclas so ficam marcadas como ativas em game->keys e o movimento de acontece em
// update_player() no arquivo movement.c, ele roda uma vez por frame
int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		game->keys.w = 1;
	else if (keycode == KEY_A)
		game->keys.a = 1;
	else if (keycode == KEY_S)
		game->keys.s = 1;
	else if (keycode == KEY_D)
		game->keys.d = 1;
	else if (keycode == KEY_LEFT)
		game->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 1;
	return (0);
}

// desliga a flag da tecla pressionada
int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = 0;
	else if (keycode == KEY_A)
		game->keys.a = 0;
	else if (keycode == KEY_S)
		game->keys.s = 0;
	else if (keycode == KEY_D)
		game->keys.d = 0;
	else if (keycode == KEY_LEFT)
		game->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		game->keys.right = 0;
	return (0);
}

// Aqui os hooks de teclado, ainda incompletos
// - EVENT_KEY_PRESS   -> tecla pressionada
// - EVENT_KEY_RELEASE -> quando solta a tecla
void	set_hooks(t_game *game)
{
	mlx_hook(game->win, EVENT_KEY_PRESS, 1L << 0, key_press, game);
	mlx_hook(game->win, EVENT_KEY_RELEASE, 1L << 1, key_release, game);
}
