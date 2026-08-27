/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:34:43 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/27 16:42:52 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (1);
	ft_memset(&game, 0, sizeof(game));
	if (parsing_main(av[1], &game))
		return (1);
	if (render_main(&game))
	{
		free_map(&game);
		return (1);
	}
	free_map(&game);
	return (0);
}
