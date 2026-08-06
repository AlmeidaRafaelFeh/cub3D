/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:43:18 by rafreire          #+#    #+#             */
/*   Updated: 2026/07/27 13:43:18 by rafreire         ###   ########.fr       */
=======
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 09:58:38 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/07/29 15:43:34 by tmfanfa          ###   ########.fr       */
>>>>>>> tai-merge
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD
=======
// metade superior da tela
// -> será a cor do teto <-
>>>>>>> tai-merge
static void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_H / 2)
	{
		x = 0;
		while (x < SCREEN_W)
		{
<<<<<<< HEAD
			my_pixel_put(&game->screen, x, y, 0x87CEEB);
=======
			my_pixel_put(&game->screen,	x, y, 0x87CEEB);
>>>>>>> tai-merge
			x++;
		}
		y++;
	}
}

<<<<<<< HEAD
=======

// metade inferior da tela
// -> será a cor do chão <-
>>>>>>> tai-merge
static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = SCREEN_H / 2;
	while (y < SCREEN_H)
	{
		x = 0;
		while (x < SCREEN_W)
		{
<<<<<<< HEAD
			my_pixel_put(&game->screen, x, y, 0x555555);
=======
			my_pixel_put(&game->screen,	x, y, 0x555555);
>>>>>>> tai-merge
			x++;
		}
		y++;
	}
}

<<<<<<< HEAD
=======

// desenha céu e chão
>>>>>>> tai-merge
void	render_background(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
}
