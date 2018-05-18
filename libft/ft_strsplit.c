/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:16:54 by slin              #+#    #+#             */
/*   Updated: 2017/12/07 14:08:23 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char		*next_word(const char *s, char c)
{
	size_t		len;
	char		*word;
	int			i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen_char(s, c);
	if (!(word = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s && *s != c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		count;
	int		i;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	if (!(new = (char**)malloc(sizeof(*new) * (count + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			new[i] = next_word(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	new[i] = NULL;
	return (new);
}
