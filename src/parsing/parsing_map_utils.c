/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 11:26:13 by rafreire          #+#    #+#             */
/*   Updated: 2026/08/06 10:17:41 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**alloc_map(int row_count, int max_width)
{
	char	**map;
	int		row;

	map = malloc(sizeof(char *) * row_count);
	if (!map)
		return (NULL);
	row = 0;
	while (row < row_count)
	{
		map[row] = malloc(sizeof(char) * (max_width + 1));
		if (!map[row])
		{
			while (row-- > 0)
				free(map[row]);
			free(map);
			return (NULL);
		}
		row++;
	}
	return (map);
}

int	get_row_len(char *row)
{
	if (!row)
		return (0);
	return ((int)ft_strlen(row));
}

int	get_max_width(char **rows, int row_count)
{
	int	row;
	int	width;
	int	len;

	row = 0;
	width = 0;
	while (row < row_count)
	{
		len = get_row_len(rows[row]);
		if (len > width)
			width = len;
		row++;
	}
	return (width);
}
