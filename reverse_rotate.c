/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:27:31 by ybendavi          #+#    #+#             */
/*   Updated: 2021/12/01 21:38:58 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_nbs **ab)
{
	t_nbs	*last;
	t_nbs	*before_last;

	before_last = *ab;
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *ab;
	*ab = last;
}
