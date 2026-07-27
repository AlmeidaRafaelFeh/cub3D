/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:03:37 by rafreire          #+#    #+#             */
/*   Updated: 2026/07/27 13:43:18 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	create_screen(t_game *game)
{
	game->screen.img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	if (!game->screen.img)
		return (1);
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.bits_per_pixel, &game->screen.line_length,
			&game->screen.endian);
	return (0);
}

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
	return (0);
}

int	render_main(void)
{
	t_game	game;

	if (init_game(&game))
	{
		printf("Erro no init_game\n");
		return (1);
	}
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
