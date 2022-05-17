/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:11:47 by inicole-          #+#    #+#             */
/*   Updated: 2022/05/15 23:22:50 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	long long unsigned int	i;
	void					*result;

	i = nmemb * size;
	if (nmemb != 0 && i / nmemb != size)
		return (NULL);
	result = malloc(i);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, i);
	return (result);
}
