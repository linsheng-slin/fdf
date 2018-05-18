/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:57:47 by slin              #+#    #+#             */
/*   Updated: 2018/03/22 16:47:53 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key3(int key, t_info *t)
{
	if (key == 0 && t->color > 0)
	{
		t->color -= 1;
		mlx_clear_window(t->mlx, t->win);
		ft_deal(t);
	}
	else if (key == 1 && t->color < 8)
	{
		t->color += 1;
		mlx_clear_window(t->mlx, t->win);
		ft_deal(t);
	}
	return (0);
}

int		deal_key2(int key, t_info *t)
{
	if (key == 125)
	{
		t->ud -= 1;
		mlx_clear_window(t->mlx, t->win);
		ft_deal(t);
	}
	else if (key == 124)
	{
		t->lr += 1;
		mlx_clear_window(t->mlx, t->win);
		ft_deal(t);
	}
	else if (key == 123)
	{
		t->lr -= 1;
		mlx_clear_window(t->mlx, t->win);
		ft_deal(t);
	}
	else
		deal_key3(key, t);
	return (0);
}

int		deal_key(int key, t_info *t)
{
	if (key == 53)
		exit(0);
	else if (key == 69)
	{
		t->zoom += 1;
		mlx_clear_window(t->mlx, t->win);
		ft_deal(t);
	}
	else if (key == 78)
	{
		t->zoom -= 1;
		mlx_clear_window(t->mlx, t->win);
		ft_deal(t);
	}
	else if (key == 126)
	{
		t->ud += 1;
		mlx_clear_window(t->mlx, t->win);
		ft_deal(t);
	}
	else
		deal_key2(key, t);
	return (0);
}
