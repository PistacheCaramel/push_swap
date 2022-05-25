/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:37:25 by ybendavi          #+#    #+#             */
/*   Updated: 2021/12/01 21:37:38 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nbadd_front(t_nbs **alst, t_nbs *new)
{
	if (*alst == NULL && new != NULL)
	{
		*alst = new;
		new->next = NULL;
	}
	else if (*alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	push(t_nbs **ab, t_nbs **ba)
{
	t_nbs	*element;

	element = *ab;
	*ab = (*ab)->next;
	ft_nbadd_front(ba, element);
}
