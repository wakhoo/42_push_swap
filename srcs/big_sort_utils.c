/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:38:55 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 10:41:02 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*find_next(t_node *stack)
{
	t_node	*curr;
	t_node	*first;
	t_node	*small;

	first = stack;
	curr = stack->next;
	small = stack;
	while (curr != first)
	{
		if (small->data > curr->data && curr->index == -1)
			small = curr;
		if (small->index != -1)
			small = curr;
		curr = curr->next;
	}
	return (small);
}

int	find_index(t_swap *stacks, int index, int i, int j)
{
	t_node	*curr;

	curr = stacks->b_top;
	while (i < stacks->b_len)
	{
		if (curr->index == index)
			break ;
		curr = curr->next;
		i++;
	}
	curr = stacks->b_top;
	while (j < stacks->b_len)
	{
		if (curr->index == index)
			break ;
		curr = curr->pre;
		j++;
	}
	if (i < j)
		return (i * (-1));
	else
		return (j);
}

void	set_index_big(t_swap *stacks)
{
	t_node	*small;
	int		i;

	i = 1;
	small = find_small(stacks->a_top);
	small->index = 0;
	while (i < stacks->a_len)
	{
		small = find_next(stacks->a_top);
		small->index = i;
		i++;
	}
}
