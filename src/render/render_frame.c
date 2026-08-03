/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:01:29 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/07/29 15:43:52 by tmfanfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


// essa função vai ser chamada uma vez por frame
int	render_frame(t_game *game)
{
	update_player(game);
	render_background(game);
	render_walls(game);
	render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}

// restante da renderização vai vir aqui 
