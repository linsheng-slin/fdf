/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 20:19:25 by slin              #+#    #+#             */
/*   Updated: 2017/12/03 22:20:15 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*a;

	a = (char*)s;
	len = ft_strlen(s);
	if ((char)c == '\0')
		return (a + len);
	while (len >= 0)
	{
		if (a[len] == (char)c)
			return (a + len);
		len--;
	}
	return (NULL);
}
