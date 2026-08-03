/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 17:24:54 by rafreire          #+#    #+#             */
/*   Updated: 2025/07/27 18:00:04 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*temp;

	if (!lst || !del || !lst[0])
		return ;
	current = lst[0];
	temp = current->next;
	while (current && current->next)
	{
		ft_lstdelone(current, del);
		current = temp;
		temp = current->next;
	}
	if (current)
		ft_lstdelone(current, del);
	lst[0] = NULL;
}
