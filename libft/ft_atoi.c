/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:02:21 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/06 21:07:29 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	n;
	int		j;
	long	a;

	i = 1;
	j = 0;
	n = 0;
	while (str[j] == ' ' || (str[j] >= 8 && str[j] <= 13))
		j++;
	if (str[j] == '-')
		i = -1;
	if (str[j] == '+' || str[j] == '-')
		j++;
	while (str[j] > 47 && str[j] < 58)
	{
		a = n;
		n = str[j] - 48 + n * 10;
		if (a > n)
			return (i < 0 ? 0 : -1);
		j++;
	}
	n = n * i;
	return (n);
}
