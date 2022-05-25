/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_call.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:00:35 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 15:51:35 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_insert(t_all **all)
{
	int	insert;

	if (sorting_checker(all) == 0)
		insert = (*all)->hit_count;
	else
		insert = 0;
	return (insert);
}

int	check_radix(t_all **all)
{
	int	rad;

	if (sorting_checker(all) == 0)
		rad = (*all)->hit_count;
	else
		rad = 0;
	return (rad);
}

int	radix_call(t_all **all)
{
	if (radix_sort(all, ft_strlen((*all)->a->binary_rank) - 1) == 1)
	{
		freer(all);
		return (1);
	}
	return (0);
}
