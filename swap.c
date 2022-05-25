/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:40:17 by ybendavi          #+#    #+#             */
/*   Updated: 2021/12/01 21:40:20 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_nbs **ab)
{
	t_nbs	*element;

	if ((*ab)->next != NULL)
	{
		element = (*ab)->next->next;
		ft_nbadd_front(ab, (*ab)->next);
		(*ab)->next->next = element;
	}
}
