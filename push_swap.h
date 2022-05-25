/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:26:04 by ybendavi          #+#    #+#             */
/*   Updated: 2022/01/19 17:55:46 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct n_list
{
	int				nb;
	int				rank;
	char			*binary_rank;
	struct n_list	*next;

}					t_nbs;

typedef struct a_list
{
	t_nbs	*a;
	t_nbs	*b;
	char	**cmds;
	int		hit_count;
}			t_all;

int		ft_push_swap(char **args);
t_nbs	*ft_nbnew(int nb);
void	swap(t_nbs **ab);
void	rotate(t_nbs **ab);
void	reverse_rotate(t_nbs **ab);
void	push(t_nbs **ab, t_nbs **ba);
void	ft_nbadd_front(t_nbs **alst, t_nbs *new);
int		cmd_handler(char *cmd, t_all **all);
int		quick_sort_3(t_all **all);
int		compare_sup(int nb, t_nbs **a);
int		check_invert_sorting(t_nbs **b);
int		check_sorting(t_nbs **a);
int		t_nbs_size(t_nbs **ab);
t_nbs	*ft_nblast(t_nbs **nbs);
int		sorting_checker(t_all **all);
void	rotate_handler(t_all **all, char on);
t_nbs	*pivot_selector(t_nbs **ab);
int		compare_inf(int nb, t_nbs **a);
int		check_sorting_all(t_nbs **a, t_nbs **b);
void	rev_b(t_all **all, t_nbs *pivot);
int		q3b_loop(t_all **all, t_nbs *pivot);
int		q3_loop(t_all **all, t_nbs *pivot);
int		condition_swap(t_all **all);
void	reverse_handler(t_all **all, t_nbs *pivot, char on);
int		init_rank(t_all **all);
char	*ft_itoa_base(unsigned long long int n, const char *base);
int		radix_sort(t_all **all, int on);
void	print(t_nbs *nb);
void	freer(t_all **all);
void	print_cmds(char **cmds);
int		insertion_sort(t_all **all);
int		compare_algo(int rad, int quick, int insert);
void	sort_3(t_all **all);
int		sort_5(t_all **all);
int		sorting_checker_b(t_all **all);
void	cmd_printer(char *cmd, t_all **all);
int		init_all(t_all **all, char **args);
void	init_rank_2(t_all **all);
void	free_args(char **strs, char **args);
int		alr_sort(t_all **all);
int		small_amount(t_all **all);
int		large_amount(t_all **all, char	**cmds, int rad, int insert);
int		ft_atoi_verif(const char *nptr);
int		cmds_size(char **args);
int		check_insert(t_all **all);
int		check_radix(t_all **all);
int		radix_call(t_all **all);
#endif
