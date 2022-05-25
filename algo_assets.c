/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:24:55 by ybendavi          #+#    #+#             */
/*   Updated: 2021/12/01 21:29:58 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_nbs	*ft_nblast(t_nbs **nbs)
{
	t_nbs	*lst;

	lst = *nbs;
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	t_nbs_size(t_nbs **ab)
{
	t_nbs	*tmp;
	int		i;

	tmp = *ab;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	check_sorting(t_nbs **a)
{
	t_nbs	*tmp;

	tmp = *a;
	if (!tmp)
		return (1);
	while (tmp->next != NULL && tmp->nb < tmp->next->nb)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (0);
	return (1);
}

int	check_invert_sorting(t_nbs **b)
{
	t_nbs	*tmp;

	tmp = *b;
	if (!tmp)
		return (0);
	while (tmp != NULL && tmp->next != NULL && tmp->nb > tmp->next->nb)
		tmp = tmp->next;
	if (tmp != NULL && tmp->next == NULL)
		return (0);
	return (1);
}

int	compare_sup(int nb, t_nbs **a)
{
	t_nbs	*c;
	int		i;

	c = *a;
	i = 0;
	while (c != NULL && c->next != NULL)
	{
		if (nb > c->nb)
			i++;
		c = c->next;
	}	
	if (c != NULL && nb > c->nb)
		i++;
	return (i);
}
