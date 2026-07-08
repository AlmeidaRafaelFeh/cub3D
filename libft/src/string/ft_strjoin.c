/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:17:59 by rafreire          #+#    #+#             */
/*   Updated: 2025/07/24 14:06:07 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*newstr;
	size_t		real_len;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	real_len = ft_strlen(s1) + ft_strlen(s2);
	newstr = ft_calloc(real_len + 1, sizeof(char));
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
	i++;
	}
	while (s2[j])
	{
		newstr[i + j] = s2[j];
	j++;
	}
	newstr[i + j] = '\0';
	return (newstr);
}
