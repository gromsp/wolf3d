/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:09:18 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/09 16:07:14 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i])
			k++;
		i++;
	}
	return (k + 1);
}

static char	*ft_strsubn(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	if (s == 0 || len == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (*(s + start) && len-- > 0)
	{
		*(str + i) = *(s + start);
		i++;
		start++;
	}
	*(str + i) = '\0';
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**q;
	int		i;
	int		k;
	int		p;

	i = 0;
	p = 0;
	k = 0;
	if (!s || !c)
		return (NULL);
	if (!(q = (char **)malloc(sizeof(char *) * (count(s, c)) + 1)))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		p = i;
		while (s[p] != '\0' && s[p] != c)
			p++;
		q[k] = ft_strsubn(s, i, p - i);
		k++;
		i = p;
	}
	q[k] = NULL;
	return (q);
}
