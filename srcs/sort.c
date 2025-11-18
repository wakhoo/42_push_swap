/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:26:18 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/11 16:16:45 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_both(t_swap *stacks, t_node *cheapest)
{
	while (stacks->a_top != cheapest->target
		&& stacks->b_top != cheapest)
		ft_rrr(stacks);
	get_index(stacks, 0);
}

void	rotate_both(t_swap *stacks, t_node *cheapest)
{
	while (stacks->a_top != cheapest->target
		&& stacks->b_top != cheapest)
		ft_rr(stacks);
	get_index(stacks, 0);
}

void	finish_rotation(t_swap *stacks, t_node *b_target, t_node *a_target)
{
	while (stacks->b_top != b_target)
	{
		if (b_target->mid == 1)
			ft_pt_rb(stacks);
		else
			ft_pt_rrb(stacks);
	}
	while (stacks->a_top != a_target)
	{
		if (a_target->mid == 1)
			ft_pt_ra(stacks);
		else
			ft_pt_rra(stacks);
	}
}

void	go_to_place(t_swap *stacks)
{
	t_node	*cheapest;

	cheapest = find_cheapest(stacks->b_top);
	if (cheapest->mid
		&& cheapest->target->mid)
		rotate_both(stacks, cheapest);
	else if ((cheapest->mid == 0)
		&& (cheapest->target->mid == 0))
		reverse_rotate_both(stacks, cheapest);
	finish_rotation(stacks, cheapest, cheapest->target);
	ft_pt_pa(stacks);
}
