/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:37:09 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 10:40:05 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	big_sort(t_swap *stacks, int chunk)
{
	set_index_big(stacks);
	a_to_b(stacks, chunk, 0);
	b_to_a(stacks);
}

void	sort_three(t_swap *stacks, t_node *small, t_node *big)
{
	small = find_small(stacks->a_top);
	big = find_big(stacks->a_top);
	get_index(stacks, 0);
	if (small->index == 2 && small->next != big && check_is_sort(stacks->a_top))
	{
		ft_pt_rra(stacks);
		ft_pt_rra(stacks);
	}
	if (small->index == 2 && small->next == big && check_is_sort(stacks->a_top))
		ft_pt_sa(stacks);
	if (small->index == 3 && big->index == 2 && check_is_sort(stacks->a_top))
		ft_pt_rra(stacks);
	if (small->index == 3 && big->index == 1 && check_is_sort(stacks->a_top))
	{
		ft_pt_sa(stacks);
		ft_pt_rra(stacks);
	}
	else if (check_is_sort(stacks->a_top))
	{
		ft_pt_ra(stacks);
		ft_pt_sa(stacks);
		ft_pt_rra(stacks);
	}
	return ;
}

void	sort_four(t_swap *stacks, t_node *small)
{
	if (small->mid)
		while (small != stacks->a_top)
			ft_pt_ra(stacks);
	else
		while (small != stacks->a_top)
			ft_pt_rra(stacks);
	if (check_is_sort(stacks->a_top))
	{
		ft_pt_pb(stacks);
		get_index(stacks, 0);
		sort_three(stacks, small, stacks->a_big);
		ft_pt_pa(stacks);
	}
}

void	sort_five(t_swap *stacks, t_node *small, t_node *big)
{
	if (small->mid)
		while (small != stacks->a_top)
			ft_pt_ra(stacks);
	else
		while (small != stacks->a_top)
			ft_pt_rra(stacks);
	if (check_is_sort(stacks->a_top))
	{
		ft_pt_pb(stacks);
		get_index(stacks, 0);
		if (big->mid)
			while (big != stacks->a_top)
				ft_pt_ra(stacks);
		else
			while (big != stacks->a_top)
				ft_pt_rra(stacks);
		ft_pt_pb(stacks);
		sort_three(stacks, small, big);
		ft_pt_pa(stacks);
		ft_pt_pa(stacks);
	}
}

void	choose_sort(t_swap *stacks, int argc)
{
	if (argc == 3)
		ft_pt_sa(stacks);
	else if (argc == 4)
		sort_three(stacks, stacks->a_small, stacks->a_big);
	else if (argc == 5)
	{
		stacks->a_small = find_small(stacks->a_top);
		sort_four(stacks, stacks->a_small);
	}
	else if (argc == 6)
	{
		stacks->a_small = find_small(stacks->a_top);
		stacks->a_big = find_small_second(stacks->a_small);
		get_index(stacks, 0);
		sort_five(stacks, stacks->a_small, stacks->a_big);
	}
	else if (argc <= 121)
		big_sort(stacks, 15);
	else
		big_sort(stacks, 30);
	return ;
}
