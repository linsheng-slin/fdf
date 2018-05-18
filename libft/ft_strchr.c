/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 19:19:07 by slin              #+#    #+#             */
/*   Updated: 2017/12/03 22:06:36 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char*)s;
	while (a[i] != '\0')
	{
		if (a[i] == (char)c)
			return (a + i);
		i++;
	}
	if (c == '\0')
		return (a + i);
	else
		return (NULL);
}
