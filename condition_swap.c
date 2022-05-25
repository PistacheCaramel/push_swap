/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:34:04 by ybendavi          #+#    #+#             */
/*   Updated: 2021/12/02 15:20:00 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	condition_swap(t_all **all)
{
	int	i;

	i = 0;
	if ((*all)->b != NULL && (*all)->b->next
		&& (*all)->b->nb < (*all)->b->next->nb
		&& (*all)->a && (*all)->a->next && (*all)->a->nb > (*all)->a->next->nb)
	{
		cmd_handler("ss", all);
		i++;
	}
	else if ((*all)->a && (*all)->a->next
		&& (*all)->a->nb > (*all)->a->next->nb)
	{
		cmd_handler("sa", all);
		i++;
	}
	else if ((*all)->b && (*all)->b->next
		&& (*all)->b->nb < (*all)->b->next->nb)
	{
		cmd_handler("sb", all);
		i++;
	}
	return (i);
}
