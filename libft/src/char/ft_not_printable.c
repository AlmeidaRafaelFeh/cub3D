/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotprintable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 08:38:51 by rafreire          #+#    #+#             */
/*   Updated: 2026/07/08 08:39:01 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_not_printable(char c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if ((uc <= 31) || uc == 127)
		return (1);
	return (0);
}
