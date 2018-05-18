/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:12:57 by slin              #+#    #+#             */
/*   Updated: 2017/12/04 21:57:55 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *s1;
	const char *s2;

	if (*little == '\0')
		return ((char*)big);
	while (*big != '\0')
	{
		s1 = big;
		s2 = little;
		while (*s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
