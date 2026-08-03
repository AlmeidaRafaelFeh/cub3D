/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:27:52 by rafreire          #+#    #+#             */
/*   Updated: 2025/07/28 10:56:58 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_found_words(const char *s, char c);
static	int	ft_count_letters(const char *s, char c);
static	char	**ft_final_str(const char *s, char c, char **new_str);
static	void	ft_free(char **str);

char	**ft_split(char const *s, char c)
{
	char	**new_str;

	if (!s)
		return (0);
	new_str = ft_calloc(ft_found_words(s, c) + 1, sizeof(char *));
	if (!new_str)
	{
		ft_free(new_str);
		return (0);
	}
	new_str = ft_final_str(s, c, new_str);
	return (new_str);
}

static	int	ft_count_letters(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	int	ft_found_words(const char *s, char c)
{
	int	i;
	int	words;
	int	in_word;

	i = 0;
	in_word = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			words++;
		}
		else if (s[i] == c)
			in_word = 0;
	i++;
	}
	return (words);
}

static	char	**ft_final_str(const char *s, char c, char **new_str)
{
	int		j;
	int		i;

	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			i = 0;
			new_str[j] = ft_calloc(ft_count_letters(s, c) + 1, sizeof(char));
			if (!new_str[j])
			{
				ft_free(new_str);
				return (0);
			}
			while (*s && *s != c)
				new_str[j][i++] = *s++;
			j++;
		}
	}
	new_str[j] = NULL;
	return (new_str);
}

static	void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		free(str[i++]);
	free (str);
}
