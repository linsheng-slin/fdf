/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:30:35 by slin              #+#    #+#             */
/*   Updated: 2017/12/07 14:06:23 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (s)
	{
		i = 0;
		if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s[start] != '\0' && len > 0)
		{
			new[i] = s[start];
			i++;
			start++;
			len--;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
