/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:15:21 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 10:28:41 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sa(t_swap *stack)
{
	int	tmp;

	if (stack->a_len < 2)
		return ;
	tmp = stack->a_top->data;
	stack->a_top->data = stack->a_top-> next->data;
	stack->a_top->next->data = tmp;
}

void	ft_sb(t_swap *stack)
{
	int	tmp;

	if (stack->b_len < 2)
		return ;
	tmp = stack->b_top->data;
	stack->b_top->data = stack->b_top-> next->data;
	stack->b_top->next->data = tmp;
}

void	ft_pt_ss(t_swap *stack)
{
	if (stack->a_len > 1 && stack->b_len > 1)
	{
		ft_sa(stack);
		ft_sb(stack);
		ft_printf("ss\n");
	}
	return ;
}

void	ft_pt_sa(t_swap *stack)
{
	if (stack->a_len < 2)
		return ;
	ft_sa(stack);
	ft_printf("sa\n");
}

void	ft_pt_sb(t_swap *stack)
{
	if (stack->b_len < 2)
		return ;
	ft_sb(stack);
	ft_printf("sb\n");
}
