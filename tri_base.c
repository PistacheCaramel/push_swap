/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:59:10 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 12:05:54 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_binary(t_all **all, int on)
{
	t_nbs	*tmp;

	tmp = (*all)->a;
	while (tmp && tmp->binary_rank[on] == '1')
		tmp = tmp->next;
	if (tmp)
		return (0);
	else
		return (1);
}

int	radix_loop(t_all **all, int on, t_nbs *current)
{	
	if (current->binary_rank[on] == '0')
	{
		if (cmd_handler("pb", all) == 1)
			return (1);
	}
	else
	{
		if (cmd_handler("ra", all) == 1)
			return (1);
	}
	return (0);
}

int	radix_sort(t_all **all, int on)
{
	t_nbs	*current;
	int		size;
	int		i;

	current = (*all)->a;
	i = 0;
	size = t_nbs_size(&((*all)->a));
	while (i < size)
	{
		if (radix_loop(all, on, current) == 1)
			return (1);
		current = (*all)->a;
		i++;
	}
	while ((*all)->b)
	{
		if (cmd_handler("pa", all) == 1)
			return (1);
	}
	if (on != 0)
	{
		if (radix_sort(all, on - 1) == 1)
			return (1);
	}
	return (0);
}
