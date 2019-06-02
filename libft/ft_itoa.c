/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:32:27 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/06 20:28:15 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*algitoa(char *str, long long int n)
{
	long long int i;
	long long int a;
	long long int t;

	i = 0;
	a = 10000000000;
	if (n < 0)
	{
		n = n * (-1);
		str[i++] = '-';
	}
	t = n;
	while (a != 0)
	{
		if (n / a != 0)
			str[i++] = (t / a) + 48;
		t = t - (t / a) * a;
		a = a / 10;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	int				i;
	char			*str;
	long long int	p;

	i = 0;
	p = n;
	str = malloc(sizeof(char *) * 2);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str = algitoa(str, p);
	}
	else
	{
		if (n == 0)
		{
			str[i++] = '0';
			str[i++] = '\0';
			return (str);
		}
		str = algitoa(str, p);
	}
	return (str);
}
