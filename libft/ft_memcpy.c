/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:51:24 by slin              #+#    #+#             */
/*   Updated: 2017/12/04 13:32:10 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	int				i;

	i = 0;
	d = dst;
	s = src;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dst);
}
