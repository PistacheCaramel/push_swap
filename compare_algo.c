/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 20:06:18 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/18 18:31:08 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare_algo(int rad, int quick, int insert)
{
	if ((rad > 0 && quick == 0 && insert == 0)
		|| (rad > 0 && rad < quick && insert == 0)
		|| (rad > 0 && rad <= insert && quick == 0)
		|| (rad > 0 && rad <= insert && rad < quick))
		return (0);
	else if ((insert > 0 && quick == 0 && rad == 0)
		|| (insert > 0 && insert < quick && rad == 0)
		|| (insert > 0 && insert <= rad && quick == 0)
		|| (insert > 0 && insert <= rad && insert < quick))
		return (1);
	else if ((quick > 0 && rad == 0 && insert == 0)
		|| (quick > 0 && quick < rad && insert == 0)
		|| (quick > 0 && quick < insert && rad == 0)
		|| (quick > 0 && quick < insert && quick < rad))
		return (2);
	return (3);
}		
