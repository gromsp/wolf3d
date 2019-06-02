/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:25:34 by adoyle            #+#    #+#             */
/*   Updated: 2018/11/29 18:38:34 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char		*dst_tempo;
	const unsigned char	*src_tempo;
	int					i;

	i = 0;
	if (dest < src)
		ft_memcpy(dest, src, num);
	else if (dest > src)
	{
		dst_tempo = (unsigned char *)dest;
		src_tempo = (const unsigned char *)src;
		while (num--)
			dst_tempo[num] = src_tempo[num];
	}
	return ((char*)dest);
}
