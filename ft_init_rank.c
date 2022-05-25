/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_rank.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:37:01 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 16:28:23 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*zero(int width, char *str)
{
	char	*str2;
	int		i;
	int		n;

	i = width;
	n = ft_strlen(str);
	if (width <= n)
		return (str);
	str2 = (char *)ft_calloc(width + 1, sizeof(char));
	if (!str2)
	{
		free(str);
		return (NULL);
	}
	while (n >= 0 && i >= 0)
	{
		str2[i] = str[n--];
		i--;
	}
	while (i >= 0 && str2[i] == 0)
		str2[i--] = '0';
	free(str);
	return (str2);
}

int	zero_fill(t_all **all)
{
	int		width;
	t_nbs	*tmp;
	int		nbs_size;

	tmp = (*all)->a;
	nbs_size = t_nbs_size(&((*all)->a)) - 1;
	while (tmp->rank != nbs_size)
		tmp = tmp->next;
	width = ft_strlen(tmp->binary_rank);
	tmp = (*all)->a;
	while (tmp)
	{
		tmp->binary_rank = zero(width, tmp->binary_rank);
		if (!tmp->binary_rank)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	cond_free(t_all **all, t_nbs *tmp, int i)
{
	tmp->rank = i;
	tmp->binary_rank = ft_itoa_base(i, "01");
	if (!tmp->binary_rank)
	{
		free(all);
		return (1);
	}
	return (0);
}

int	init_rank(t_all **all)
{
	t_nbs	*tmp;
	t_nbs	*tmp2;
	int		i;

	tmp = (*all)->a;
	while (tmp)
	{
		tmp2 = (*all)->a;
		i = 0;
		while (tmp2)
		{
			if (tmp2 != tmp)
			{
				if (tmp->nb > tmp2->nb)
					i++;
			}
			tmp2 = tmp2->next;
		}
		if (cond_free(all, tmp, i) == 1)
			return (1);
		tmp = tmp->next;
	}
	if (zero_fill(all) == 1)
		return (1);
	return (0);
}

void	init_rank_2(t_all **all)
{
	t_nbs	*tmp;
	t_nbs	*tmp2;
	int		i;

	tmp = (*all)->a;
	while (tmp)
	{
		tmp2 = (*all)->a;
		i = 0;
		while (tmp2)
		{
			if (tmp2 != tmp)
			{
				if (tmp->nb > tmp2->nb)
					i++;
			}
			tmp2 = tmp2->next;
		}
		tmp->rank = i;
		tmp = tmp->next;
	}
}
