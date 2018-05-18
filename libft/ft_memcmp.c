/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 22:02:11 by slin              #+#    #+#             */
/*   Updated: 2017/12/04 14:07:35 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *c1;
	const unsigned char *c2;
	size_t				i;

	c1 = s1;
	c2 = s2;
	i = 0;
	while (n > 0 && c1[i] == c2[i])
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (c1[i] - c2[i]);
}
