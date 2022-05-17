/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:12:37 by inicole-          #+#    #+#             */
/*   Updated: 2022/05/12 13:21:38 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	unsigned char	str1;
	unsigned char	str2;

	if (size == 0)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2) && (size - 1))
	{
		s1++;
		s2++;
		size--;
	}
	str1 = (unsigned char)*s1;
	str2 = (unsigned char)*s2;
	return (str1 - str2);
}
