/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:49:20 by adoyle            #+#    #+#             */
/*   Updated: 2018/11/29 18:36:12 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		if (*(char*)str1 != *(char*)str2)
			return (*(const unsigned char*)str1 - *(const unsigned char*)str2);
		i++;
		str1++;
		str2++;
	}
	return (0);
}
