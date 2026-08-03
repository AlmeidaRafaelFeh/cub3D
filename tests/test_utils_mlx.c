/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +#+#+#+#+#+   +#+           */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 10:30:00 by rafreire          #+#    #+#             */
/*   Updated: 2026/07/08 10:30:00 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>

#include "cub3D.h"

int	main(void)
{
	unsigned int	buffer[4];
	unsigned int	expected[4];
	t_pixel_data	data;

	buffer[0] = 0x00000000;
	buffer[1] = 0x11111111;
	buffer[2] = 0x22222222;
	buffer[3] = 0x33333333;
	data.addr = (char *)buffer;
	data.bits_per_pixel = 32;
	data.line_length = 2 * sizeof(unsigned int);
	data.endian = 0;
	my_pixel_put(&data, 1, 1, 0xAABBCCDD);

	expected[0] = 0x00000000;
	expected[1] = 0x11111111;
	expected[2] = 0x22222222;
	expected[3] = 0xAABBCCDD;
	my_pixel_put(&data, -1, 0, 0xFFFFFFFF);
	my_pixel_put(&data, 0, -1, 0xFFFFFFFF);
	my_pixel_put(&data, SCREEN_W, 0, 0xFFFFFFFF);
	my_pixel_put(&data, 0, SCREEN_H, 0xFFFFFFFF);
	assert(buffer[0] == expected[0]);
	assert(buffer[1] == expected[1]);
	assert(buffer[2] == expected[2]);
	assert(buffer[3] == expected[3]);
	return (0);
}
