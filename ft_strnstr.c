/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:12:40 by inicole-          #+#    #+#             */
/*   Updated: 2022/05/12 18:38:06 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t size)
{
	size_t	len2;

	if (!*s2)
		return ((char *)(s1));
	len2 = ft_strlen(s2);
	while (*s1 && size >= len2)
	{
		if ((*s1 == *s2) && (ft_strncmp(s1, s2, len2) == 0))
			return ((char *)(s1));
		s1++;
		size--;
	}
	return (NULL);
}
