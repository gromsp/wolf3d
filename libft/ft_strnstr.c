/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:23:05 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/07 16:03:07 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str2, const char *str1, size_t num)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	if (*(str1 + i) == '\0')
		return ((char*)str2 + i);
	while (*(str2 + i) && i < num)
	{
		j = 0;
		len = 0;
		if (*(str2 + i) == *(str1 + j))
		{
			while (*(str1 + j) != '\0' && i < num)
			{
				if ((*(str2 + i++)) == (*(str1 + j++)))
					len++;
				if (len == ft_strlen(str1))
					return ((char*)str2 + i - j);
			}
			i = i - len;
		}
		i++;
	}
	return (0);
}
