/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:12:26 by ybendavi          #+#    #+#             */
/*   Updated: 2021/12/01 21:39:26 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate(t_nbs **ab)
{
	t_nbs	*first;
	t_nbs	*new_first;

	first = *ab;
	new_first = first->next;
	while (first->next != NULL)
		first = first->next;
	first->next = *ab;
	first->next->next = NULL;
	*ab = new_first;
}
