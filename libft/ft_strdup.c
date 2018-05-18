/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 23:25:05 by slin              #+#    #+#             */
/*   Updated: 2017/12/04 14:12:53 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*b;
	int		len;

	len = ft_strlen(s1);
	if (!(b = (char*)malloc(sizeof(*s1) * (len + 1))))
		return (NULL);
	ft_strcpy(b, s1);
	return (b);
}
