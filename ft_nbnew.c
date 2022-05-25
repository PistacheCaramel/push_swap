/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:35:54 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 11:39:26 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbs	*ft_nbnew(int nb)
{
	t_nbs	*new;

	new = malloc(sizeof(t_nbs));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}
