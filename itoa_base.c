/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:41:49 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/18 16:44:23 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_itoa_base_len(unsigned long long int n, int i)
{
	long long unsigned int	tmp;
	int						len;

	tmp = n;
	len = 0;
	if (tmp <= 0)
	{
		tmp = tmp * -1;
		len++;
	}
	while (tmp >= 1)
	{
		tmp = tmp / i;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long int n, const char *base)
{
	int						lbase;
	long long unsigned int	tmp2;
	int						len;
	char					*str;

	tmp2 = n;
	lbase = 0;
	while (base[lbase])
		lbase++;
	len = ft_itoa_base_len(tmp2, lbase);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!(str))
		return (NULL);
	str[len--] = 0;
	while (len >= 0 && str[len] == 0)
	{
		str[len--] = base[tmp2 % lbase];
		tmp2 = tmp2 / lbase;
	}
	return (str);
}
