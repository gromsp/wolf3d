/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:04:20 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/07 18:01:39 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	int i;

	i = 0;
	if (!destptr && !srcptr)
		return (NULL);
	while (num-- > 0)
	{
		((char*)destptr)[i] = ((char*)srcptr)[i];
		i++;
	}
	return (destptr);
}
