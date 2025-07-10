/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:06:22 by pnurmi            #+#    #+#             */
/*   Updated: 2025/05/04 14:32:57 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(const char *s, char c);
static void		*ft_free(char **s);
static size_t	ft_len(const char *s, char c);

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	char	**array;

	i = 0;
	j = 0;
	array = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (s[j])
	{
		if (s[j] != c)
		{
			array[i] = ft_substr(s, j, ft_len(&s[j], c));
			if (!array[i])
				return (ft_free(array));
			j = j + ft_len(&s[j], c);
			i++;
		}
		else
			j++;
	}
	array[i] = NULL;
	return (array);
}

static size_t	ft_count(const char *s, char c)
{
	size_t	word;
	size_t	i;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i])
			i++;
		word++;
	}
	return (word);
}

static void	*ft_free(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static size_t	ft_len(const char *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}
// substr
/* allocate enough room for the word */
/* copy the word into the memory you allocated above */
/* return the allocated word */