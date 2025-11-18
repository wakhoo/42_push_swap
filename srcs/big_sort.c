/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:34:02 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 10:40:53 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	a_to_b(t_swap *stacks, int chunk, int i)
{
	while (stacks->a_len != 0)
	{
		if (stacks->a_top->index <= i)
		{
			ft_pt_pb(stacks);
			i++;
		}
		else if (stacks->a_top->index > i && stacks->a_top->index <= i + chunk)
		{
			ft_pt_pb(stacks);
			ft_pt_rb(stacks);
			i++;
		}
		else if ((stacks->a_top->index) > (i + chunk))
		{
			if (i < stacks->a_len / 2 && i >= 0)
				ft_pt_rra(stacks);
			else
				ft_pt_ra(stacks);
		}
	}
}

void	b_to_a(t_swap *stacks)
{
	t_node	*big;

	big = find_big(stacks->b_top);
	set_mid(stacks->b_top, stacks->b_len);
	while (stacks->b_top != big && big->mid == 0)
		ft_pt_rrb(stacks);
	while (stacks->b_top != big && big->mid == 1)
		ft_pt_rb(stacks);
	ft_pt_pa(stacks);
	while (stacks->b_len != 0)
		sort_b(stacks);
}

void	set_mid(t_node *stack, int len)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = stack;
	while (i < len)
	{
		if (i <= len / 2)
			curr->mid = 1;
		curr = curr->next;
		i++;
	}
}

void	sort_b(t_swap *stacks)
{
	int	index;

	index = find_index(stacks, stacks->b_len - 1, 0, 0);
	if (index == 0)
	{
		ft_pt_pa(stacks);
		return ;
	}
	else if (index < 0)
		while (index++ != 0)
			ft_pt_rb(stacks);
	else
		while (index-- != 0)
			ft_pt_rrb(stacks);
	ft_pt_pa(stacks);
}
