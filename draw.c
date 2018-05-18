/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:38:28 by slin              #+#    #+#             */
/*   Updated: 2018/03/27 11:02:17 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		out_put(t_info *t, double tx, double dx, double dy)
{
	while (tx <= 1)
	{
		t->xx = t->x + (dx * tx);
		t->yy = t->y + (dy * tx);
		if (t->color == 1)
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0xFF69B4);
		else if (t->color == 2)
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0xe55ea2);
		else if (t->color == 3)
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0xcc5490);
		else if (t->color == 4)
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0xb2497d);
		else if (t->color == 5)
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0x993f6c);
		else if (t->color == 6)
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0x7f345a);
		else if (t->color == 7)
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0x662a48);
		else if (t->color == 8)
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0x4c1f36);
		else
			mlx_pixel_put(t->mlx, t->win, t->yy, t->xx, 0xff78bb);
		tx += 1. / sqrt((dx * dx) + (dy * dy));
	}
	return (0);
}

int		draw_down(t_info *t, int a, int c, int i)
{
	double		tx;
	double		dx;
	double		dy;

	t->degree = t->map[a][c] * 0.25;
	t->degree2 = t->map[a + 1][c] * 0.25;
	t->x = 300 + (a - t->degree - t->ud) * t->zoom;
	t->y = 100 + (c + i + t->lr) * t->zoom;
	t->x1 = 300 + (a + 1 - t->degree2 - t->ud) * t->zoom;
	t->y1 = 100 + (c + 1 + i + t->lr) * t->zoom;
	tx = 0.0;
	dx = t->x1 - t->x;
	dy = t->y1 - t->y;
	out_put(t, tx, dx, dy);
	return (0);
}

int		draw_across(t_info *t, int a, int c, int i)
{
	double		tx;
	double		dx;
	double		dy;

	t->degree = t->map[a][c] * 0.25;
	t->degree2 = t->map[a][c + 1] * 0.25;
	t->x = 300 + (a - t->degree - t->ud) * t->zoom;
	t->y = 100 + (c + i + t->lr) * t->zoom;
	t->x1 = 300 + (a - t->degree2 - t->ud) * t->zoom;
	t->y1 = 100 + (c + 1 + i + t->lr) * t->zoom;
	tx = 0.0;
	dx = t->x1 - t->x;
	dy = t->y1 - t->y;
	out_put(t, tx, dx, dy);
	return (0);
}

int		draw(t_info *t, int b, int a, int i)
{
	while (t->map[a - 1][b + 1] != 911)
	{
		a = 0;
		i = 1;
		while (a < t->down)
			draw_across(t, a++, b, i++);
		b++;
	}
	b = 0;
	a = 1;
	while (t->map[a - 1][b] != 911)
	{
		a = 0;
		i = 1;
		while (a < t->down - 1)
			draw_down(t, a++, b, i++);
		b++;
	}
	return (0);
}

int		ft_deal(t_info *t)
{
	int		x;
	int		y;

	x = 27;
	y = 34;
	while (x <= 180)
		mlx_pixel_put(t->mlx, t->win, x++, y, 0xFFFFFF);
	while (y <= 117)
		mlx_pixel_put(t->mlx, t->win, x, y++, 0xFFFFFF);
	while (x >= 27)
		mlx_pixel_put(t->mlx, t->win, x--, y, 0xFFFFFF);
	while (y >= 34)
		mlx_pixel_put(t->mlx, t->win, x, y--, 0xFFFFFF);
	mlx_string_put(t->mlx, t->win, 35, 35, 0xFFFFFF, "Quit = ESC");
	mlx_string_put(t->mlx, t->win, 35, 55, 0xFFFFFF, "Move = ^ v < >");
	mlx_string_put(t->mlx, t->win, 35, 75, 0xFFFFFF, "Zoom = + -");
	mlx_string_put(t->mlx, t->win, 35, 95, 0xFFFFFF, "Light = a s");
	draw(t, 0, 1, 0);
	return (0);
}
