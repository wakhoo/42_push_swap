/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:00:30 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 03:49:35 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	set_stacks(t_swap *stacks, char **argv)
{
	stacks->b_bottom = NULL;
	stacks->b_len = 0;
	stacks->a_bottom = NULL;
	stacks->a_len = 0;
	create_chain(stacks, argv, 1, 2);
}

t_node	*create_node(int n)
{
	t_node	*new;

	new = (t_node *) malloc(sizeof (t_node));
	if (!new)
		return (NULL);
	new->data = n;
	new->mid = 0;
	new->next = NULL;
	new->pre = NULL;
	new->target = NULL;
	new->index = -1;
	return (new);
}

static int	chain_deux(char **argv, int i, t_node *current, t_swap *stacks)
{
	int		count;
	long	pre;

	count = 0;
	pre = current->data;
	current->next = create_node(ft_atoi(argv[i]));
	if (!current->next)
		ft_error(stacks, i);
	if (pre < current->next->data)
		count++;
	if (i > 1)
		current->next->pre = current;
	return (count);
}

void	create_chain(t_swap *stacks, char **argv, int i, int count)
{
	t_node	*first;
	t_node	*current;

	first = create_node(ft_atoi(argv[i]));
	stacks->a_top = first;
	if (!first || check_int(argv[i]) || check_empty(argv[i]))
		ft_error(stacks, i);
	i++;
	current = first;
	while (argv[i])
	{
		if (check_int(argv[i]) || check_empty(argv[i])
			|| check_double(first, ft_atoi(argv[i])))
			ft_error(stacks, i - 1);
		count += chain_deux(argv, i, current, stacks);
		current = current->next;
		i++;
	}
	if (i == count)
		ft_end(stacks, i - 1);
	current->next = first;
	first->pre = current;
	stacks->a_bottom = first->pre;
	stacks->a_len = i - 1;
	return ;
}
