/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmfanfa <tmfanfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 12:51:44 by rafreire          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/08/02 14:46:12 by rafreire         ###   ########.fr       */
=======
/*   Updated: 2026/08/03 by tmfanfa                 ###   ########.fr       */
>>>>>>> tai-merge
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

<<<<<<< HEAD
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int c);
=======
>>>>>>> tai-merge
char	*ft_read_append(int fd, char *content, char *buffer);
char	*get_next_line(int fd);
char	*validate_line(char **content);
void	*free_mem(void **ptr1, void **ptr2);

#endif
