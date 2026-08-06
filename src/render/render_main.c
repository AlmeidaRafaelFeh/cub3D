/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:00:12 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 11:00:21 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	create_screen(t_game *game)
{
	game->screen.img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	if (!game->screen.img)
		return (1);
	game->screen.addr = mlx_get_data_addr(game->screen.img, &game->screen.bpp,
			&game->screen.line_len, &game->screen.endian);
	return (0);
}

// game->map, game->map_w, game->map_h e a posição inicial do player
// (game->player.x/y/orientation) já chegam prontos, preenchidos pelo
// parsing_main() antes desta função ser chamada.
static int	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3D");
	if (!game->win)
		return (1);
	if (create_screen(game))
		return (1);
	init_player(&game->player);
	init_keys(&game->keys);
	set_hooks(game);
	return (0);
}

int	render_main(t_game *game)
{
	if (init_game(game))
	{
		printf("Erro no init_game\n");
		return (1);
	}
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
	return (0);
}
