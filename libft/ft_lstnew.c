/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:39:53 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/04 16:41:43 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	temp = (t_list*)malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		temp->content = NULL;
		temp->content_size = 0;
	}
	else
	{
		temp->content = malloc(content_size);
		if (temp->content == NULL)
			return (NULL);
		ft_memmove(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	temp->next = NULL;
	return (temp);
}
