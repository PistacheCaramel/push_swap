/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   already_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:20:33 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/18 16:37:43 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alr_sort(t_all **all)
{
	t_nbs	*tmp;

	tmp = (*all)->a;
	while (tmp && tmp < tmp->next)
		tmp = tmp->next;
	while (tmp && tmp < tmp->next)
		tmp = tmp->next;
	if (tmp == NULL)
		return (0);
	return (1);
}
