/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:54:36 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/06 22:32:46 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s;
	size_t	k;

	i = 0;
	k = 0;
	j = ft_strlen(dest);
	s = ft_strlen(str);
	if (n < j)
		return (s + n);
	while (dest[k] != '\0')
		k++;
	while (str[i] != '\0' && k < n - 1)
	{
		dest[k] = str[i];
		i++;
		k++;
	}
	dest[k] = '\0';
	return (j + s);
}
