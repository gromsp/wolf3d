/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:44:55 by adoyle            #+#    #+#             */
/*   Updated: 2018/12/27 15:47:42 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_lncut(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str[i] == '\0')
		return (NULL);
	if (str[i] == '\n' || str[i] == '\0')
	{
		tmp = ft_strnew(1);
		tmp[0] = '\0';
		return (tmp);
	}
	while ((str[i] != '\n') && str[i] != '\0')
		i++;
	tmp = ft_strsub(str, j, i - j);
	return (tmp);
}

static char	*ft_strcut(char *str)
{
	char	*tmp;
	int		j;

	j = 0;
	if (str[j] == '\0')
		return (NULL);
	if (str[j] == '\n' && str[j] != '\0')
		return (tmp = ft_strdup(str + 1));
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	if (str[j] == '\n' && str[j] != '\0')
		j++;
	if (str[j] == '\0')
		return (NULL);
	tmp = ft_strdup(str + j);
	return (tmp);
}

static int	ft_flag(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] == '\n')
		i++;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[FD_MAX];
	char		tmp[BUFF_SIZE + 1];
	int			i;
	char		*fr;

	if (fd < 0 || !line)
		return (-1);
	while ((ft_flag(str[fd]) == 0) && (i = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[i] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(BUFF_SIZE + 1);
		fr = str[fd];
		str[fd] = ft_strjoin(str[fd], tmp);
		free((void *)fr);
	}
	if (str[fd] == NULL && tmp[0] == '\0')
		return (-1);
	if ((str[fd] == NULL) || (!(*line = ft_lncut(str[fd]))))
		return (0);
	fr = str[fd];
	str[fd] = ft_strcut(str[fd]);
	free((void *)fr);
	return (1);
}
