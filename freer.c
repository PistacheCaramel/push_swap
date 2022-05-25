/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:39:11 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 18:18:58 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freer(t_all **all)
{	
	t_nbs	*tmp;
	int		i;

	i = 0;
	while ((*all)->a)
	{
		tmp = (*all)->a;
		(*all)->a = (*all)->a->next;
		free(tmp->binary_rank);
		free(tmp);
	}
	while ((*all)->b)
	{
		tmp = (*all)->b;
		(*all)->b = (*all)->b->next;
		free(tmp->binary_rank);
		free(tmp);
	}
	while ((*all)->cmds[i])
	{
		free((*all)->cmds[i]);
		i++;
	}
	free((*all)->cmds);
	free(*all);
}

void	free_args(char **strs, char **args)
{
	int	i;

	i = 0;
	if (strs && strs != &args[1])
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}
