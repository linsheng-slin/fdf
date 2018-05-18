/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:19:46 by slin              #+#    #+#             */
/*   Updated: 2018/03/22 16:31:32 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct	s_info
{
	int		color;
	int		hi;
	int		bye;
	int		**map;
	int		zoom;
	int		down;
	void	*mlx;
	void	*win;
	double	x;
	double	y;
	double	x1;
	double	y1;
	double	xx;
	double	yy;
	double	degree;
	double	degree2;
	int		high;
	int		ud;
	int		lr;
}				t_info;

int				go_go_go(char *str);
int				ft_deal(t_info *t);
int				deal_key(int key, t_info *t);

#endif
