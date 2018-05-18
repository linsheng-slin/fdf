/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:41:58 by slin              #+#    #+#             */
/*   Updated: 2018/01/17 19:23:57 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_stock(char **stock, char **line)
{
	char			*tmp;

	tmp = ft_strchr(*stock, '\n');
	if (tmp)
	{
		*line = ft_strsub(*stock, 0, tmp - *stock);
		ft_memmove(*stock, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int		fill_stock(int fd, char **stock, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp = NULL;
		if (*stock)
		{
			tmp = ft_strdup(*stock);
			ft_memdel((void**)stock);
			*stock = ft_strjoin(tmp, buf);
			ft_memdel((void**)&tmp);
		}
		else
			*stock = ft_strdup(buf);
		if (check_stock(stock, line))
			return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char		*stock[4242];
	int				result;

	if (!line || fd < 0 || fd > 4242)
		return (-1);
	if (stock[fd] && check_stock(&stock[fd], line))
		return (1);
	result = fill_stock(fd, &stock[fd], line);
	if (result != 0)
		return (result);
	if (stock[fd] == NULL || stock[fd][0] == '\0')
		return (0);
	*line = stock[fd];
	stock[fd] = NULL;
	return (1);
}
