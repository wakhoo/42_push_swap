/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajeon <chajeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:59:59 by chajeon           #+#    #+#             */
/*   Updated: 2024/07/13 10:43:10 by chajeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/lib/ft_printf.h"
# include "../libft/lib/get_next_line_bonus.h"
# include "../libft/lib/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	struct s_node	*pre;
	int				data;
	struct s_node	*next;
	struct s_node	*target;
	int				index;
	int				mid;
	int				cost;
	int				cheapest;
}	t_node;

typedef struct s_swap
{
	t_node		*a_top;
	t_node		*a_bottom;
	int			a_len;
	t_node		*b_top;
	t_node		*b_bottom;
	int			b_len;
	t_node		*a_big;
	t_node		*a_small;
}	t_swap;

int		find_index(t_swap *stacks, int index, int i, int j);
void	set_mid(t_node *stack, int len);
void	a_to_b(t_swap *stacks, int chunk, int i);
void	b_to_a(t_swap *stacks);
void	sort_b(t_swap *stacks);
void	set_index_big(t_swap *stacks);
void	set_stacks(t_swap *stacks, char **argv);
t_node	*create_node(int n);
void	create_chain(t_swap *stacks, char **argv, int i, int count);
int		check_empty(char *argv);
int		check_int(char *num);
int		check_double(t_node *stack, int current);
int		check_is_sort(t_node *stack);
void	choose_sort(t_swap *stacks, int argc);
void	sort_three(t_swap *stacks, t_node *small, t_node *big);
void	sort_five(t_swap *stacks, t_node *small, t_node *big);
void	ft_move(t_swap *stacks);
void	go_to_place(t_swap *stacks);
void	finish_rotation(t_swap *stacks, t_node *b_target, t_node *a_target);
void	rotate_both(t_swap *stacks, t_node *cheapest);
void	reverse_rotate_both(t_swap *stacks, t_node *cheapest);
void	set_nodes(t_swap *stacks);
void	get_index(t_swap *stacks, int i);
t_node	*find_small(t_node *stack);
t_node	*find_big(t_node *stack);
t_node	*find_cheapest(t_node *stack);
t_node	*find_small_second(t_node *smallest);
t_node	*find_next(t_node *stack);
void	ft_sa(t_swap *stack);
void	ft_pt_sa(t_swap *stack);
void	ft_sb(t_swap *stack);
void	ft_pt_sb(t_swap *stack);
void	ft_ss(t_swap *stack);
void	ft_pt_ss(t_swap *stack);
void	ft_ra(t_swap *stack);
void	ft_rb(t_swap *stack);
void	ft_pt_ra(t_swap *stack);
void	ft_pt_rb(t_swap *stack);
void	ft_rr(t_swap *stack);
void	ft_pt_rr(t_swap *stack);
void	ft_rra(t_swap *stack);
void	ft_rrb(t_swap *stack);
void	ft_pt_rra(t_swap *stack);
void	ft_pt_rrb(t_swap *stack);
void	ft_rrr(t_swap *stack);
void	ft_pt_rrr(t_swap *stack);
void	ft_pa(t_swap *stack);
void	ft_pt_pa(t_swap *stack);
void	ft_pb(t_swap *stack);
void	ft_pt_pb(t_swap *stack);
void	ft_error(t_swap *stacks, int i);
void	ft_end(t_swap *stacks, int i);
void	test_print(t_swap *stack);

#endif
