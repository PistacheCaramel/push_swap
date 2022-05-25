/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:42:49 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/17 12:45:38 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		write(1, cmds[i], ft_strlen(cmds[i]));
		write(1, "\n", 1);
		i++;
	}
}