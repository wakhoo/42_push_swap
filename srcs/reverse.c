/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:27:08 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 10:27:50 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ra(t_swap *stack)
{
	stack->a_top = stack->a_top->next;
	stack->a_bottom = stack->a_bottom->next;
}

void	ft_pt_ra(t_swap *stack)
{
	if (stack->a_len > 1)
		ft_ra(stack);
	ft_printf("ra\n");
}

void	ft_rb(t_swap *stack)
{
	stack->b_top = stack->b_top->next;
	stack->b_bottom = stack->b_bottom->next;
}

void	ft_pt_rb(t_swap *stack)
{
	if (stack->b_len > 1)
		ft_rb(stack);
	ft_printf("rb\n");
}

void	ft_pt_rr(t_swap *stack)
{
	if (stack->a_len > 1)
		ft_ra(stack);
	if (stack->b_len > 1)
		ft_rb(stack);
	ft_printf("rr\n");
}
