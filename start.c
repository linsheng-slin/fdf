/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:27:19 by slin              #+#    #+#             */
/*   Updated: 2018/03/22 16:33:42 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_newline(char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int		find_length(char *s, int i)
{
	int		count;

	count = 0;
	while (s[i] != '\n')
	{
		if (s[i] != ' ')
		{
			count++;
			while (s[i] != ' ' && s[i] != '\n')
				i++;
		}
		else
			i++;
	}
	return (count);
}

int		ft_atoi2(const char *str, int *i)
{
	char	*s;
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	s = (char*)str;
	while (s[*i] == ' ')
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (s[*i] && s[*i] >= '0' && s[*i] <= '9')
	{
		result = result * 10 + (s[*i] - '0');
		(*i)++;
	}
	return (result * sign);
}

int		**ft_storestr(char *s, int d, int c, int i)
{
	int		**map;
	int		down;
	int		a;

	down = count_newline(s);
	if (!(map = (int**)malloc(sizeof(int*) * down)))
		return (NULL);
	while (s[i] != '\0')
	{
		a = 0;
		if (!(map[d] = (int*)malloc(sizeof(int) * find_length(s, i) + 1)))
			return (NULL);
		while (s[i] != '\n')
		{
			map[d][a++] = ft_atoi2(s, &i);
			while (s[i] == ' ')
				i++;
		}
		if (a != c && c != 0)
			return (NULL);
		c = a;
		map[d++][a] = 911;
		i++;
	}
	return (map);
}

int		go_go_go(char *str)
{
	t_info	t;

	if (!(t.map = ft_storestr(str, 0, 0, 0)))
		return (0);
	t.zoom = 350 / count_newline(str);
	t.down = count_newline(str);
	t.lr = 0;
	t.ud = 0;
	t.color = 0;
	t.mlx = mlx_init();
	t.win = mlx_new_window(t.mlx, 1000, 1000, "fdf");
	mlx_expose_hook(t.win, &ft_deal, &t);
	mlx_key_hook(t.win, &deal_key, &t);
	mlx_loop(t.mlx);
	return (0);
}
