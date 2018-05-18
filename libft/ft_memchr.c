/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:25:29 by slin              #+#    #+#             */
/*   Updated: 2017/12/04 14:06:38 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	int				i;

	s_ptr = (unsigned char*)s;
	i = 0;
	while (n-- > 0)
	{
		if (s_ptr[i] == (unsigned char)c)
			return ((void*)s_ptr + i);
		i++;
	}
	return (NULL);
}
