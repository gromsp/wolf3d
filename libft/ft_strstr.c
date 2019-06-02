/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:20:48 by adoyle            #+#    #+#             */
/*   Updated: 2018/11/29 19:10:30 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str2, const char *str1)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	if (*(str1 + i) == '\0')
		return ((char*)str2 + i);
	while (*(str2 + i))
	{
		j = 0;
		len = 0;
		if (*(str2 + i) == *(str1 + j))
		{
			while (*(str1 + j))
			{
				if ((*(str2 + i++)) == (*(str1 + j++)))
					len++;
				if (len == ft_strlen(str1))
					return ((char*)str2 + i - j);
			}
			i = i - j + 1;
		}
		i++;
	}
	return (0);
}
