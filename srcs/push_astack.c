/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_astack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:39:47 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/15 10:16:37 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_one_a(t_swap *stack)
{
	t_node	*tmp;

	tmp = stack->b_top->next;
	stack->a_top = stack->b_top;
	stack->b_top = tmp;
	stack->a_top->next = stack->a_top;
	stack->a_top->pre = stack->a_top;
	stack->a_bottom = stack->a_top;
	stack->b_top->pre = stack->b_bottom;
	stack->b_bottom->next = stack->b_top;
	stack->a_len++;
	stack->b_len--;
}

void	ft_two_a(t_swap *stack)
{
	t_node	*tmp;
	t_node	*new;

	tmp = stack->b_top->next;
	new = stack->b_top;
	new->pre = stack->a_bottom;
	new->next = stack->a_top;
	stack->a_top->pre = new;
	stack->a_top->next = new;
	stack->a_top = new;
	stack->b_top = tmp;
	stack->b_top->pre = stack->b_bottom;
	stack->b_bottom->next = stack->b_top;
	stack->a_len++;
	stack->b_len--;
}

void	ft_left_one_b(t_swap *stack)
{
	t_node	*new;

	new = stack->b_top;
	new->pre = stack->a_bottom;
	new->next = stack->a_top;
	stack->a_top->pre = new;
	stack->a_bottom->next = new;
	stack->a_top = new;
	stack->b_top = NULL;
	stack->b_bottom = NULL;
	stack->a_len++;
	stack->b_len--;
}

void	ft_pa(t_swap *stack)
{
	t_node	*tmp;
	t_node	*new;

	if (stack->a_len == 0)
		return (ft_one_a(stack));
	else if (stack->a_len == 1)
		return (ft_two_a(stack));
	else if (stack->b_len == 1)
		return (ft_left_one_b(stack));
	else
	{
		tmp = stack->b_top->next;
		new = stack->b_top;
		new->pre = stack->a_bottom;
		new->next = stack->a_top;
		stack->a_top->pre = new;
		stack->a_bottom->next = new;
		stack->a_top = new;
		stack->b_top = tmp;
		stack->b_top->pre = stack->b_bottom;
		stack->b_bottom->next = stack->b_top;
		stack->a_len++;
		stack->b_len--;
	}
}

void	ft_pt_pa(t_swap *stack)
{
	if (!stack->b_top)
		return ;
	ft_pa(stack);
	ft_printf("pa\n");
}
