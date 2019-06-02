/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:17:33 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/06 19:46:10 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;

	if (!lst || !f || !(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = (t_list*)malloc(sizeof(t_list));
		if (!(new->next))
		{
			free(new->next);
			return (NULL);
		}
		new->next = f(lst);
		if (!(new->next))
		{
			free(new->next);
			return (NULL);
		}
		new = new->next;
	}
	return (tmp);
}
