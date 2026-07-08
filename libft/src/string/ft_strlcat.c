/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:33:16 by rafreire          #+#    #+#             */
/*   Updated: 2025/07/24 14:05:03 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;

	if (size > 0)
	{
		i = 0;
		dest_len = ft_strlen(dest);
		if (dest_len >= size)
			return (size + ft_strlen(src));
		while (i + dest_len < size - 1 && src[i])
		{
			dest[dest_len + i] = src[i];
			i++;
		}
		dest[dest_len + i] = '\0';
	}
	if (!dest || size == 0)
		return (ft_strlen(src));
	return (dest_len + ft_strlen(src));
}
