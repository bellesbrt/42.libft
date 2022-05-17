/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:20:40 by inicole-          #+#    #+#             */
/*   Updated: 2022/05/14 03:40:36 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_start_count(char *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ft_strchr(set, s1[i]) != NULL)
	{
		j++;
		i++;
	}
	return (j);
}

size_t	ft_end_count(char *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) - 1;
	j = 0;
	while (ft_strchr(set, s1[i]) != NULL)
	{
		i--;
		j++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*middle;
	size_t	start;
	size_t	end;

	middle = (char *)s1;
	if (middle == NULL || set == NULL)
		return (NULL);
	start = ft_start_count(middle, set);
	end = ft_end_count(middle, set);
	middle = ft_substr(middle, start, ft_strlen(middle) - start - end);
	return (middle);
}
