/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:04:09 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/12 06:28:03 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_index(t_swap *stacks, int i)
{
	t_node	*curr;

	curr = stacks->a_top;
	while (i < stacks->a_len)
	{
		if (i <= stacks->a_len / 2)
			curr->mid = 1;
		curr->index = i + 1;
		curr = curr->next;
		i++;
	}
	i = 0;
	curr = stacks->b_top;
	while (i < stacks->b_len)
	{
		if (i <= stacks->b_len / 2)
			curr->mid = 1;
		curr->index = i + 1;
		curr = curr->next;
		i++;
	}
}

void	set_target(t_swap *stacks, int good_data, int i, int j)
{
	t_node	*b_curr;
	t_node	*a_curr;

	b_curr = stacks->b_top;
	while (i++ < stacks->b_len)
	{
		j = 0;
		a_curr = stacks->a_top;
		good_data = INT_MAX;
		while (j < stacks->a_len)
		{
			if (a_curr->data > b_curr->data && a_curr->data < good_data)
			{
				good_data = a_curr->data;
				stacks->a_top->target = a_curr;
			}
			a_curr = a_curr->next;
			j++;
		}
		if (INT_MAX == good_data)
			b_curr->target = find_small(stacks->a_top);
		else
			b_curr->target = stacks->a_top->target;
		b_curr = b_curr->next;
	}
}

void	check_cost(t_swap *stacks)
{
	int		i;
	t_node	*b_curr;

	b_curr = stacks->b_top;
	i = 0;
	while (i < stacks->b_len)
	{
		b_curr->cost = b_curr->index;
		if (b_curr->mid == 0)
			b_curr->cost = stacks->b_len - b_curr->index;
		if (b_curr->target->mid == 1)
			b_curr->cost += b_curr->target->index;
		else
			b_curr->cost += (stacks->a_len - b_curr->target->index);
		b_curr = b_curr->next;
		i++;
	}
}

void	tag_cheapest(t_swap *stacks)
{
	int		cheapest_data;
	int		i;
	t_node	*cheapest_node;
	t_node	*b_curr;

	b_curr = stacks->b_top;
	i = 0;
	cheapest_data = INT_MAX;
	while (i < stacks->b_len)
	{
		if (b_curr->cost < cheapest_data)
		{
			cheapest_data = b_curr->cost;
			cheapest_node = b_curr;
		}
		b_curr->cheapest = 0;
		b_curr = b_curr->next;
		i++;
	}
	cheapest_node->cheapest = 1;
}

void	set_nodes(t_swap *stacks)
{
	get_index(stacks, 0);
	set_target(stacks, 0, 0, 0);
	check_cost(stacks);
	tag_cheapest(stacks);
}
