/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:10:28 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/18 16:57:40 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_all **all)
{
	if ((*all)->a->rank == 1 && (*all)->a->next->rank == 0
		&& (*all)->a->next->next->rank == 2)
		cmd_printer("sa", all);
	else if ((*all)->a->rank == 2 && (*all)->a->next->rank == 1
		&& (*all)->a->next->next->rank == 0)
	{
		cmd_printer("sa", all);
		cmd_printer("rra", all);
	}
	else if ((*all)->a->rank == 2 && (*all)->a->next->rank == 0
		&& (*all)->a->next->next->rank == 1)
		cmd_printer("ra", all);
	else if ((*all)->a->rank == 0 && (*all)->a->next->rank == 2
		&& (*all)->a->next->next->rank == 1)
	{
		cmd_printer("sa", all);
		cmd_printer("ra", all);
	}
	else if ((*all)->a->rank == 1 && (*all)->a->next->rank == 2
		&& (*all)->a->next->next->rank == 0)
		cmd_printer("rra", all);
}

void	find_place(t_all **all)
{
	if ((*all)->b && (*all)->b->next
		&& (*all)->b->rank < (*all)->b->next->rank)
		cmd_printer("sb", all);
	if ((*all)->b->rank != 0 && (*all)->b->rank != 4)
	{
		while ((!((*all)->a->rank > (*all)->b->rank
					&& (*all)->b->rank > ft_nblast(&(*all)->a)->rank))
			&& (compare_sup((*all)->b->nb, &(*all)->a) != 0
				&& compare_inf((*all)->b->nb, &(*all)->a) != 0))
		{
			cmd_printer("ra", all);
		}
	}
	cmd_printer("pa", all);
	if ((*all)->a->rank == 4)
		cmd_printer("ra", all);
}

void	loop1_2(t_all **all, int current)
{
	int		i;
	t_nbs	*tmp;

	i = 0;
	tmp = (*all)->a;
	while (tmp && tmp->rank != current)
	{
		tmp = tmp->next;
		i++;
	}
	if (i > 2)
	{
		while ((*all)->a->rank != current)
			cmd_printer("rra", all);
	}
	else
	{	
		while ((*all)->a->rank != current)
			cmd_printer("ra", all);
	}
	cmd_printer("pb", all);
}

void	push1_2(t_all **all)
{
	loop1_2(all, 0);
	loop1_2(all, 1);
}

int	sort_5(t_all **all)
{
	push1_2(all);
	init_rank_2(all);
	sort_3(all);
	cmd_printer("pa", all);
	cmd_printer("pa", all);
	return (0);
}
