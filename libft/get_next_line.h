/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoyle <adoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:45:52 by adoyle            #+#    #+#             */
/*   Updated: 2019/03/24 15:09:19 by adoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# define BUFF_SIZE 256
# define FD_MAX 2147483647

int		get_next_line(const int fd, char **line);

#endif
