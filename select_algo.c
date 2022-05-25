/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:31:39 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 15:50:56 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small_amount(t_all **all)
{
	if (sorting_checker_b(all) == 0)
	{
		freer(all);
		return (0);
	}
	if (t_nbs_size(&(*all)->a) == 2)
	{
		if (sorting_checker_b(all) != 0)
			cmd_printer("sa", all);
		freer(all);
		return (0);
	}
	if (t_nbs_size(&(*all)->a) == 3)
	{
		sort_3(all);
		freer(all);
		return (0);
	}
	if (t_nbs_size(&(*all)->a) == 5)
	{
		sort_5(all);
		freer(all);
		return (0);
	}
	return (1);
}

int	condition_choice(t_all **all, int rad, int quick, int insert)
{	
	if (compare_algo(rad, quick, insert) == 1)
	{
		if (insertion_sort(all) == 1)
		{
			freer(all);
			return (1);
		}
		print_cmds((*all)->cmds);
	}
	return (0);
}

int	large_amount(t_all **all, char **args, int rad, int insert)
{
	int	quick;

	quick = 0;
	if (compare_algo(rad, quick, insert) == 0)
		print_cmds((*all)->cmds);
	if (compare_algo(rad, quick, insert) == 1
		|| compare_algo(rad, quick, insert) == 2)
	{
		freer(all);
		if (init_all(all, args) == 1)
		{
			freer(all);
			return (1);
		}
		if (condition_choice(all, rad, quick, insert) == 1)
			return (1);
	}	
	freer(all);
	return (0);
}
