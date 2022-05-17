/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:19:58 by inicole-          #+#    #+#             */
/*   Updated: 2022/05/14 03:40:51 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	words_count(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	len = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			len++;
		else
		{
			if (len > 0)
				count++;
			len = 0;
		}
		i++;
	}
	if (len > 0)
		count++;
	return (count);
}

char	**allocate_count(char **str, size_t split_count)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != NULL)
	{
		i++;
		count++;
	}
	if (count != split_count)
	{
		while (j < split_count + 1)
		{
			free(str[j]);
			j++;
		}
		free(str);
		return (NULL);
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr;
	size_t			i;
	size_t			j;
	unsigned int	start;

	if (s == NULL)
		return (NULL);
	ptr = (char **)malloc((words_count(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (j < words_count(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > start)
			ptr[j++] = ft_substr(s, start, i - start);
	}
	ptr[j] = NULL;
	return (allocate_count(ptr, words_count(s, c)));
}
