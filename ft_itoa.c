/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inicole- <inicole-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:19:25 by inicole-          #+#    #+#             */
/*   Updated: 2022/05/16 13:25:54 by inicole-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrs_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static long int	change_sign(int n, int *sign)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		*sign = 1;
		nbr = nbr * -1;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char			*itoa;
	int				itoa_nbrs;
	int				sign;
	long int		ncpy;

	sign = 0;
	itoa_nbrs = nbrs_count(n);
	ncpy = change_sign(n, &sign);
	itoa = (char *)malloc(sizeof(char) * (sign + itoa_nbrs + 1));
	if (!itoa)
		return (NULL);
	itoa[sign + itoa_nbrs] = '\0';
	if (sign == 1)
			itoa[0] = '-';
	while (itoa_nbrs)
	{
		itoa[sign + itoa_nbrs - 1] = (ncpy % 10) + '0';
		ncpy = ncpy / 10;
		itoa_nbrs--;
	}
	return (itoa);
}
