/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:11:00 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 18:18:05 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] == 0 && s2[i] == 0)
		return (0);
	else
		return (1);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57))
			return (0);
		i++;
	}
	return (1);
}

int	error_handler(char **av, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		if (ft_atoi_verif(av[i]) == 1)
			return (0);
		if (ft_isnumber(av[i]) == 0)
			return (0);
		if (av[i][0] == 0)
			return (0);
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	error(char **strs, char **av)
{
	if (!strs || error_handler(strs, av) == 0)
	{
		write(1, "Error\n", 6);
		free_args(strs, av);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**strs;

	strs = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		if (av[1][0] == 0)
			return (error(strs, av));
		strs = ft_split(av[1], ' ');
		if (!strs)
			exit(EXIT_FAILURE);
	}
	else if (ac > 2)
		strs = &(av[1]);
	if (error(strs, av) == 0)
		return (0);
	if (ft_push_swap(strs) == 1)
	{
		free_args(strs, av);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
