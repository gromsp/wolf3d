/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:11:02 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/04 18:54:33 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if (s == 0)
		return (NULL);
	k = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == k + 1)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	k = k - i + 1;
	str = ft_strsub(s, i, k);
	return (str);
}
