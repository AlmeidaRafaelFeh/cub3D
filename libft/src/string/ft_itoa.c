/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:26:50 by rafreire          #+#    #+#             */
/*   Updated: 2025/07/26 16:51:30 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_convertnb(char *str, long int n, int index);
static	int	ft_nblen(long int n);

char	*ft_itoa(int n)
{
	char		*newstr;
	int			len;
	long int	nb;

	nb = (long int)n;
	len = ft_nblen(n);
	newstr = ft_calloc(len + 1, sizeof(char));
	if (!newstr)
		return (0);
	if (nb < 0)
	{
		newstr[0] = '-';
		nb *= -1;
	}
	ft_convertnb(newstr, nb, len - 1);
	return (newstr);
}

static	int	ft_nblen(long int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	void	ft_convertnb(char *str, long int n, int index)
{
	if (n > 9)
		ft_convertnb(str, n / 10, index - 1);
	str[index] = '0' + (n % 10);
}

// #include <stdio.h>

// int main ()
// {
// 	long int number = INT_MIN;
// 	long int number2 = INT_MAX;

// 	printf("result %s",  ft_itoa(number));
// 	printf("result %s",  ft_itoa(number2));
// }