/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafreire <rafreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:09:53 by rafreire          #+#    #+#             */
/*   Updated: 2025/07/28 18:57:22 by rafreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*last_node;

	if (!lst || !f || !del)
		return (NULL);
	first_node = ft_lstnew(f(lst->content));
	if (!first_node)
		return (NULL);
	while (lst->next)
	{
		last_node = ft_lstnew(f(lst->next->content));
		if (!last_node)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&first_node, last_node);
		lst = lst->next;
	}
	return (first_node);
}
