/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:35:57 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 02:55:33 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_swap	stacks;

	stacks.a_top = NULL;
	stacks.b_top = NULL;
	if (argc < 2)
		ft_end(&stacks, 0);
	set_stacks(&stacks, argv);
	choose_sort(&stacks, argc);
	ft_end(&stacks, stacks.a_len);
	return (0);
}
