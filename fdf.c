/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:13:25 by slin              #+#    #+#             */
/*   Updated: 2018/03/27 11:36:02 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putstr2(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

int		check_fd(char *argv, int argc, int *fd)
{
	if (argc != 2)
	{
		ft_putstr2("usage: ./fdf input_file\n");
		return (-1);
	}
	if ((*fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putstr2("fd error");
		return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char	*line;
	char	*buf;
	char	*tmp;
	int		fd;

	if (check_fd(argv[1], argc, &fd) < 0)
		return (0);
	if (get_next_line(fd, &line) > 0)
		buf = ft_strjoin(line, "\n");
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strjoin(buf, line);
		free(buf);
		free(line);
		buf = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	go_go_go(buf);
	free(buf);
	if (close(fd) == -1)
		ft_putstr2("fd error");
	return (0);
}
