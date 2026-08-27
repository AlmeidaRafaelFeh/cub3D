/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:00:12 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/27 17:04:32 by rafreire         ###   ########.fr       */
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

static int	load_texture(void *mlx, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(
			mlx,
			path,
			&texture->width,
			&texture->height
			);
	if (!texture->img)
		return (1);
	texture->addr = mlx_get_data_addr(
			texture->img,
			&texture->bpp,
			&texture->line_len,
			&texture->endian
			);
	if (!texture->addr)
	{
		mlx_destroy_image(mlx, texture->img);
		texture->img = NULL;
		return (1);
	}
	return (0);
}

int	render_main(t_game *game)
{
	if (init_game(game))
	{
		printf("Erro no init_game\n");
		return (1);
	}
	if (load_texture(game->mlx, &game->north, game->north_texture)
		|| load_texture(game->mlx, &game->south, game->south_texture)
		|| load_texture(game->mlx, &game->west, game->west_texture)
		|| load_texture(game->mlx, &game->east, game->east_texture))
	{
		printf("Erro ao carregar texturas\n");
		return (1);
	}
	mlx_loop_hook(game->mlx, render_frame, game);
	mlx_loop(game->mlx);
	return (0);
}
