/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assets3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 22:00:56 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/18 16:36:21 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_b(t_all **all, t_nbs *pivot)
{
	if (ft_nblast(&(*all)->b)->nb > pivot->nb
		&& ft_nblast(&(*all)->b)->nb > (*all)->b->nb)
		cmd_handler("rrb", all);
}

int	q3b_loop(t_all **all, t_nbs *pivot)
{
	while ((*all)->b && ((*all)->b) != pivot)
	{
		if (sorting_checker(all) == 0)
			return (0);
		if ((*all)->b->nb > pivot->nb)
		{
			cmd_handler("pa", all);
			condition_swap(all);
		}
		else
			cmd_handler("rb", all);
	}
	cmd_handler("pa", all);
	return (1);
}

int	q3_loop(t_all **all, t_nbs *pivot)
{
	while ((*all)->a && ((*all)->a) != pivot)
	{
		if (sorting_checker(all) == 0)
			return (0);
		if (((*all)->a)->nb < pivot->nb)
		{
			cmd_handler("pb", all);
			condition_swap(all);
		}
		else
			cmd_handler("ra", all);
	}
	cmd_handler("pb", all);
	return (1);
}
