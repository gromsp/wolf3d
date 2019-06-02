/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:14:51 by adoyle            #+#    #+#             */
/*   Updated: 2018/11/29 19:07:07 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *str, size_t n)
{
	int		l;
	size_t	i;
	int		c;

	l = 0;
	i = 0;
	c = n;
	while (c-- > 0)
	{
		if (i > n || str[i] == '\0')
		{
			dest[l] = '\0';
			l++;
		}
		else
		{
			dest[l] = str[i];
			i++;
			l++;
		}
	}
	return (dest);
}
