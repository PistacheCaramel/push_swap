/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:07:22 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 18:30:36 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int	invalid_init(t_nbs *a, t_nbs *nb)
{
	if (nb == NULL)
	{
		a->rank = 86;
		return (1);
	}
	return (0);
}

t_nbs	*init_a(char **args)
{
	t_nbs	*nb;
	t_nbs	*a;
	int		i;
	int		j;

	i = 1;
	j = ft_atoi(args[0]);
	a = ft_nbnew(j);
	if (!a)
		return (NULL);
	nb = a;
	a->rank = 0;
	while (args[i])
	{
		j = ft_atoi(args[i]);
		nb->next = ft_nbnew(j);
		nb = nb->next;
		if (invalid_init(a, nb) == 1)
			return (a);
		i++;
	}
	nb->next = NULL;
	return (a);
}

int	init_all(t_all **all, char **args)
{
	*all = ft_calloc(sizeof(t_all), 2);
	if (!*all)
		return (1);
	(*all)->a = init_a(args);
	if (!(*all)->a || (*all)->a->rank == 86)
	{
		freer(all);
		return (1);
	}
	(*all)->b = NULL;
	(*all)->hit_count = 0;
	(*all)->cmds = ft_calloc(sizeof(char *), cmds_size(args) * 100);
	if (!(*all)->cmds)
	{
		freer(all);
		return (1);
	}
	init_rank(all);
	return (0);
}

int	ft_push_swap(char **args)
{
	t_all	*all;
	int		rad;
	int		insert;

	insert = 0;
	if (init_all(&all, args) == 1)
		return (1);
	if (small_amount(&all) == 0)
		return (0);
	if (t_nbs_size(&all->a) < 100)
	{
		if (insertion_sort(&all) == 1)
		{
			freer(&all);
			return (1);
		}
		insert = check_insert(&all);
		freer(&all);
		if (init_all(&all, args) == 1)
			return (1);
	}
	if (radix_call(&all) == 1)
		return (1);
	rad = check_radix(&all);
	return (large_amount(&all, args, rad, insert));
}
