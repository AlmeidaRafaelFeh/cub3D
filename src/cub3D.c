/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:19:10 by rafreire          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/02 15:04:20 by rafreire         ###   ########.fr       */
=======
/*   Updated: 2026/08/03 by tmfanfa                 ###   ########.fr       */
>>>>>>> tai-merge
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
<<<<<<< HEAD
	if (ac != 2)
		return (1);
	if (parsing_main(av[1]))
		return (1);
	if (render_main())
		return (1);
=======
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
>>>>>>> tai-merge
	return (0);
}
