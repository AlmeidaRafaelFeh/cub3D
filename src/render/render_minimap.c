/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_minimap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:43:18 by rafreire          #+#    #+#             */
/*   Updated: 2026/07/27 13:43:18 by rafreire         ###   ########.fr       */
=======
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:05:04 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/07/29 15:47:47 by tmfanfa          ###   ########.fr       */
>>>>>>> tai-merge
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define TILE_SIZE 16

<<<<<<< HEAD
static void	draw_square(t_game *game, int start_x, int start_y, int color)
=======
// preenche o quadrado
static void	draw_square(t_game *game, int start_x, int start_y,	int color)
>>>>>>> tai-merge
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
<<<<<<< HEAD
			my_pixel_put(&game->screen, start_x + x, start_y + y, color);
=======
			my_pixel_put(&game->screen,	start_x + x, start_y + y, color);
>>>>>>> tai-merge
			x++;
		}
		y++;
	}
}

<<<<<<< HEAD
void	render_minimap(t_game *game)
{
	draw_square(game, 20, 20, 0xFFFFFF);
=======
// vai desenhar o mapa inteiro
void	render_minimap(t_game *game)
{
	draw_square(game, 20, 20, 0xFFFFFF); // para teste
	(void)game;
>>>>>>> tai-merge
}
