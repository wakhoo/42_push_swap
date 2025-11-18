/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rereverse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:43:16 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 10:28:17 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rra(t_swap *stack)
{
	stack->a_top = stack->a_top->pre;
	stack->a_bottom = stack->a_bottom->pre;
}

void	ft_pt_rra(t_swap *stack)
{
	if (stack->a_len > 1)
	{
		ft_rra(stack);
		ft_printf("rra\n");
	}
	return ;
}

void	ft_rrb(t_swap *stack)
{
	stack->b_top = stack->b_top->pre;
	stack->b_bottom = stack->b_bottom->pre;
}

void	ft_pt_rrb(t_swap *stack)
{
	if (stack->b_len > 1)
	{
		ft_rrb(stack);
		ft_printf("rrb\n");
	}
	return ;
}

void	ft_pt_rrr(t_swap *stack)
{
	if (stack->a_len > 1 && stack->b_len > 1)
	{
		ft_rra(stack);
		ft_rrb(stack);
		ft_printf("rrr\n");
	}
	return ;
}
