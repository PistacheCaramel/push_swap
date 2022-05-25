/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assets2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:28:34 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/18 16:35:24 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting_all(t_nbs **a, t_nbs **b)
{
	if (check_sorting(a) == 0 && check_invert_sorting(b) == 0
		&& (*a)->nb > (*b)->nb)
		return (0);
	return (1);
}

int	compare_inf(int nb, t_nbs **a)
{
	t_nbs	*c;
	int		i;

	c = *a;
	i = 0;
	while (c != NULL && c->next != NULL)
	{
		if (nb < c->nb)
			i++;
		c = c->next;
	}
	if (c != NULL && nb < c->nb)
		i++;
	return (i);
}

t_nbs	*pivot_selector(t_nbs **ab)
{
	t_nbs	*pivot;
	t_nbs	*pivot2;
	int		inf;
	int		sup;

	pivot = *ab;
	inf = compare_inf(pivot->nb, ab);
	sup = compare_sup(pivot->nb, ab);
	while (pivot && (inf - sup > 2 || inf - sup < -2))
	{
		pivot = pivot->next;
		inf = compare_inf(pivot->nb, ab);
		sup = compare_sup(pivot->nb, ab);
	}
	pivot2 = pivot->next;
	while (pivot2
		&& compare_inf(pivot2->nb, ab) - compare_sup(pivot->nb, ab) != 0)
		pivot2 = pivot2->next;
	if (pivot2)
		pivot = pivot2;
	if (t_nbs_size(ab) < 3)
		return (NULL);
	if (pivot)
		return (pivot);
	return (NULL);
}

int	sorting_checker(t_all **all)
{
	if (check_sorting(&(*all)->a) == 0 && (*all)->b == NULL)
		return (0);
	if (check_sorting_all(&(*all)->a, &(*all)->b) == 0)
	{
		while ((*all)->b)
			cmd_handler("pa", all);
		return (0);
	}
	return (1);
}

int	sorting_checker_b(t_all **all)
{
	if (check_sorting(&(*all)->a) == 0 && (*all)->b == NULL)
		return (0);
	if (check_sorting_all(&(*all)->a, &(*all)->b) == 0)
	{
		while ((*all)->b)
			cmd_printer("pa", all);
		return (0);
	}
	return (1);
}
