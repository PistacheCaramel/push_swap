/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:29:21 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 17:54:52 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cmd_handler_p2(char *cmd, t_nbs **a, t_nbs **b)
{
	if (ft_strncmp("ra", cmd, 3) == 0)
		rotate(a);
	if (ft_strncmp("rb", cmd, 3) == 0)
		rotate(b);
	if (ft_strncmp("rr", cmd, 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	if (ft_strncmp("rra", cmd, 3) == 0)
		reverse_rotate(a);
	if (ft_strncmp("rrb", cmd, 3) == 0)
		reverse_rotate(b);
	if (ft_strncmp("rrr", cmd, 3) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
}

int	copy_cmds(t_all **all, char *cmd)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*all)->cmds[i])
		i++;
	(*all)->cmds[i] = ft_calloc(sizeof(char), 4);
	if (!((*all)->cmds[i]))
	{
		freer(all);
		return (1);
	}
	while (cmd[j])
	{
		(*all)->cmds[i][j] = cmd[j];
		j++;
	}
	return (0);
}

int	cmd_handler(char *cmd, t_all **all)
{
	if (ft_strncmp("sa", cmd, 2) == 0)
		swap(&(*all)->a);
	else if (ft_strncmp("sb", cmd, 2) == 0)
		swap(&(*all)->b);
	else if (ft_strncmp("ss", cmd, 2) == 0)
	{
		swap(&(*all)->a);
		swap(&(*all)->b);
	}
	else if (ft_strncmp("pa", cmd, 2) == 0)
		push(&(*all)->b, &(*all)->a);
	else if (ft_strncmp("pb", cmd, 2) == 0)
		push(&(*all)->a, &(*all)->b);
	else
		cmd_handler_p2(cmd, &(*all)->a, &(*all)->b);
	(*all)->hit_count++;
	if (copy_cmds(all, cmd) == 1)
		return (1);
	return (0);
}

void	cmd_printer(char *cmd, t_all **all)
{
	if (ft_strncmp("sa", cmd, 2) == 0)
		swap(&(*all)->a);
	else if (ft_strncmp("sb", cmd, 2) == 0)
		swap(&(*all)->b);
	else if (ft_strncmp("ss", cmd, 2) == 0)
	{
		swap(&(*all)->a);
		swap(&(*all)->b);
	}
	else if (ft_strncmp("pa", cmd, 2) == 0)
		push(&(*all)->b, &(*all)->a);
	else if (ft_strncmp("pb", cmd, 2) == 0)
		push(&(*all)->a, &(*all)->b);
	else
		cmd_handler_p2(cmd, &(*all)->a, &(*all)->b);
	(*all)->hit_count++;
	write(1, cmd, ft_strlen(cmd));
	write(1, "\n", 1);
}
