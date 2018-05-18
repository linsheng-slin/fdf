/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:32:40 by slin              #+#    #+#             */
/*   Updated: 2017/12/04 13:59:16 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	ch = (unsigned char)c;
	while (n-- > 0)
	{
		*d = *s;
		if (*d++ == ch)
			return (d);
		s++;
	}
	return (NULL);
}
