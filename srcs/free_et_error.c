/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_et_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 18:10:18 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/02 13:32:04 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*clear_list(t_node **stack, int len)
{
	t_node	*current;
	int		i;

	i = 0;
	while (i < len && len > 1)
	{
		current = (*stack)->next;
		free((*stack));
		(*stack) = current;
		i++;
	}
	if (len == 1 && len != 0)
		free(*stack);
	return (NULL);
}

void	ft_error(t_swap *stacks, int i)
{
	ft_putstr_fd("Error\n", 2);
	if (i > 0)
		stacks->a_len = i;
	if (stacks->a_top != NULL)
		clear_list(&stacks->a_top, stacks->a_len);
	if (stacks->b_top != NULL)
		clear_list(&stacks->b_top, stacks->b_len);
	exit (0);
}

void	ft_end(t_swap *stacks, int i)
{
	if (i > 0)
		stacks->a_len = i;
	if (stacks->a_top != NULL && stacks->a_len > 0)
		clear_list(&stacks->a_top, stacks->a_len);
	if (stacks->b_top != NULL && stacks->b_len > 0)
		clear_list(&stacks->b_top, stacks->b_len);
	exit (0);
}
