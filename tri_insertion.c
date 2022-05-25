/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_insertion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:54:19 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 15:40:24 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	j_loop(t_nbs *tmp)
{
	int	j;

	j = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		j++;
	}
	return (j);
}

int	i_loop(t_nbs *tmp, int to_find)
{
	int	i;

	i = 0;
	while (tmp->rank != to_find)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_rotation(t_all **all, int to_find)
{
	int		i;
	int		j;
	t_nbs	*tmp;

	tmp = (*all)->a;
	i = i_loop(tmp, to_find);
	tmp = (*all)->a;
	while (tmp->rank != to_find)
		tmp = tmp->next;
	j = j_loop(tmp);
	if (i > j)
	{
		if (cmd_handler("rra", all) == 1)
			return (1);
	}
	else
	{
		if (cmd_handler("ra", all) == 1)
			return (1);
	}
	return (0);
}

int	insert_loop(t_all **all, int i)
{
	while ((*all)->a->rank != i)
	{
		if (sorting_checker(all) == 0)
			break ;
		if (find_rotation(all, i) == 1)
			return (1);
	}
	return (0);
}

int	insertion_sort(t_all **all)
{
	int	i;
	int	size;

	i = 0;
	size = t_nbs_size(&(*all)->a);
	condition_swap(all);
	while (i < size)
	{
		if ((*all)->hit_count > 9000 || sorting_checker(all) == 0)
			break ;
		if (insert_loop(all, i) == 1)
			return (1);
		if (cmd_handler("pb", all) == 1)
			return (1);
		i++;
	}
	while ((*all)->b)
	{
		if (cmd_handler("pa", all) == 1)
			return (1);
	}
	return (0);
}
