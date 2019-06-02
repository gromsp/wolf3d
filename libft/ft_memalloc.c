/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:38:12 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/04 18:50:32 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *dest;

	if (size == 0)
		return (NULL);
	dest = (char *)malloc(size);
	if (dest == NULL)
		return (NULL);
	ft_bzero(dest, size);
	return (dest);
}
