/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 12:31:14 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 10:39:38 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*find_big(t_node *stack)
{
	t_node	*curr;
	t_node	*first;
	t_node	*big;

	first = stack;
	curr = stack->next;
	big = stack;
	while (curr != first)
	{
		if (big->data < curr->data)
			big = curr;
		curr = curr->next;
	}
	return (big);
}

t_node	*find_small(t_node *stack)
{
	t_node	*curr;
	t_node	*first;
	t_node	*small;

	first = stack;
	curr = stack->next;
	small = stack;
	while (curr != first)
	{
		if (small->data > curr->data)
			small = curr;
		curr = curr->next;
	}
	return (small);
}

t_node	*find_small_second(t_node *smallest)
{
	t_node	*curr;
	t_node	*small;

	curr = smallest->next;
	small = smallest->next;
	while (curr != smallest)
	{
		if (small->data > curr->data)
			small = curr;
		curr = curr->next;
	}
	return (small);
}

t_node	*find_cheapest(t_node *stack)
{
	t_node	*curr;
	t_node	*first;

	first = stack;
	curr = stack->next;
	while (curr != first)
	{
		if (curr->cheapest == 1)
			return (curr);
		curr = curr->next;
	}
	return (curr);
}
