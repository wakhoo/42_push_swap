/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:39:47 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/15 13:00:41 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_one_b(t_swap *stack)
{
	t_node	*tmp;

	tmp = stack->a_top->next;
	stack->b_top = stack->a_top;
	stack->a_top = tmp;
	stack->b_top->next = stack->b_top;
	stack->b_top->pre = stack->b_top;
	stack->b_bottom = stack->b_top;
	stack->a_top->pre = stack->a_bottom;
	stack->a_bottom->next = stack->a_top;
	stack->b_len++;
	stack->a_len--;
}

void	ft_two_b(t_swap *stack)
{
	t_node	*tmp;
	t_node	*new;

	tmp = stack->a_top->next;
	new = stack->a_top;
	new->pre = stack->b_bottom;
	new->next = stack->b_top;
	stack->b_top->pre = new;
	stack->b_top->next = new;
	stack->b_top = new;
	stack->a_top = tmp;
	stack->a_top->pre = stack->a_bottom;
	stack->a_bottom->next = stack->a_top;
	stack->b_len++;
	stack->a_len--;
}

void	ft_left_one_a(t_swap *stack)
{
	t_node	*new;

	new = stack->a_top;
	new->pre = stack->b_bottom;
	new->next = stack->b_top;
	stack->b_top->pre = new;
	stack->b_bottom->next = new;
	stack->b_top = new;
	stack->a_top = NULL;
	stack->a_bottom = NULL;
	stack->b_len++;
	stack->a_len--;
}

void	ft_pb(t_swap *stack)
{
	t_node	*tmp;
	t_node	*new;

	if (stack->b_len == 0)
		return (ft_one_b(stack));
	else if (stack->b_len == 1)
		return (ft_two_b(stack));
	else if (stack->a_len == 1)
		return (ft_left_one_a(stack));
	else
	{
		tmp = stack->a_top->next;
		new = stack->a_top;
		new->pre = stack->b_bottom;
		new->next = stack->b_top;
		stack->b_top->pre = new;
		stack->b_bottom->next = new;
		stack->b_top = new;
		stack->a_top = tmp;
		stack->a_top->pre = stack->a_bottom;
		stack->a_bottom->next = stack->a_top;
		stack->b_len++;
		stack->a_len--;
	}
}

void	ft_pt_pb(t_swap *stack)
{
	if (!stack->a_top)
		return ;
	ft_pb(stack);
	ft_printf("pb\n");
}
