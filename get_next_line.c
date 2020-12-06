/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmomose <tmomose@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 21:34:06 by tmomose           #+#    #+#             */
/*   Updated: 2020/12/05 12:32:34 by tmomose          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*line)
			tmp = ft_strdup(buf);
		else
			tmp = ft_strjoin(*line, buf);
		if (*line)
			free(*line);
		*line = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret > 0)
		ret = 1;
	return (ret);
}
