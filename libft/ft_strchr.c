/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:29:12 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/07 17:53:01 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return ((char*)str + i);
		i++;
	}
	if (str[i] == '\0' && ch == '\0')
		return ((char*)str + i);
	return (0);
}
