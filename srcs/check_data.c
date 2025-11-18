/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:43:05 by chajeon           #+#    #+#             */
/*   Updated: 2024/06/29 12:23:09 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static long	ft_atoii(const char *str)
{
	int		i;
	long	res;
	int		min;

	i = 0;
	res = 0;
	min = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		if (i > 0)
		{
			if (str[i - 1] == '-')
				min = min * (-1);
		}
		res = res * 10 + (str[i++] - '0');
	}
	return (res * min);
}

int	check_empty(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (ft_isdigit(argv[i]) != 1)
		return (1);
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 1)
			i++;
		else if (ft_isdigit(argv[i]) != 1)
			return (1);
	}
	return (0);
}

int	check_int(char *num)
{
	if (ft_atoii(num) > (long)INT_MAX || ft_atoii(num) < (long)INT_MIN)
		return (1);
	return (0);
}

int	check_double(t_node *stack, int current)
{
	t_node	*first;
	t_node	*curr;

	first = stack;
	curr = first;
	while (curr->next != first && curr->next != NULL)
	{
		if (curr->data == current)
			return (1);
		curr = curr->next;
	}
	if (curr->data == current)
		return (1);
	stack = first;
	return (0);
}

int	check_is_sort(t_node *stack)
{
	t_node	*current;
	t_node	*first;

	first = stack;
	current = stack;
	while (current->next != first)
	{
		if (current->data > current->next->data)
			return (1);
		current = current->next;
	}
	return (0);
}
