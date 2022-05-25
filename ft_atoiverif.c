/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoiverif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 10:06:31 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 10:53:12 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_minus(const char *nptr, long long int i)
{
	int	minus;

	minus = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus++;
	}
	return (minus);
}

int	ft_atoi_verif(const char *nptr)
{
	long long int		r;
	long long int		i;
	int					minus;

	i = 0;
	r = 0;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == ' ' || nptr[i] == '\f')
		i++;
	minus = check_minus(nptr, i);
	if (minus > 0)
		i++;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + nptr[i] - 48;
		i++;
		if (r > 2147483647)
		{
			if (minus == 0 || (minus != 0 && r > 2147483648))
				return (1);
		}
	}
	return (0);
}
