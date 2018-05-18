/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:16:28 by slin              #+#    #+#             */
/*   Updated: 2017/12/07 15:14:43 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	n;

	i = 0;
	n = ft_strlen(little);
	if (ft_strlen(little) == 0)
		return ((char*)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if ((j == n - 1) && (i + j < len))
				return ((char*)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
