/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 13:43:18 by rafreire          #+#    #+#             */
/*   Updated: 2026/07/27 13:44:00 by rafreire         ###   ########.fr       */
=======
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 10:01:29 by tmfanfa           #+#    #+#             */
/*   Updated: 2026/07/29 15:43:52 by tmfanfa          ###   ########.fr       */
>>>>>>> tai-merge
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

<<<<<<< HEAD
int	render_frame(t_game *game)
{
	render_background(game);
=======

// essa função vai ser chamada uma vez por frame
int	render_frame(t_game *game)
{
	update_player(game);
	render_background(game);
	render_walls(game);
>>>>>>> tai-merge
	render_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	return (0);
}
<<<<<<< HEAD
=======

// restante da renderização vai vir aqui 
>>>>>>> tai-merge
