/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:23:05 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/06 21:10:34 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	int i;

	i = 0;
	while (n-- > 0)
	{
		if (((unsigned char *)arr)[i] == (unsigned char)c)
			return ((unsigned char *)arr + i);
		i++;
	}
	return (NULL);
}
