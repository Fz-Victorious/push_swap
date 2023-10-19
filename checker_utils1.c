/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 22:16:54 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/16 13:34:25 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_and_exitcheck(char **av, t_stack **stack_a)
{
	if (av)
		free_mem(av);
	exit_check(*stack_a, 0, 0, 0);
}

void	exit_check(t_stack *stack_a, t_stack *stack_b, \
		t_moves **moves, int message)
{
	if (stack_a)
		ft_stackclear(&stack_a);
	if (stack_b)
		ft_stackclear(&stack_b);
	if (moves && *moves)
	{
		while (*moves)
		{
			free((*moves)->content);
			ft_movesdel_node(moves);
		}
	}
	if (!message)
		write(2, "Error\n", 6);
	else if (message == 1)
		write(1, "KO\n", 3);
	else if (message == 2)
	{
		write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

void	moves_decision(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (!ft_strcmp("pa", move))
		push_stack(stack_b, stack_a, 0);
	if (!ft_strcmp("sa", move))
		swap_stack(*stack_a, 0, 0);
	if (!ft_strcmp("ra", move))
		rotate_stack(stack_a, 0, 0);
	if (!ft_strcmp("rra", move))
		reverse_rotate_stack(stack_a, 0, 0);
	if (!ft_strcmp("sb", move))
		swap_stack(*stack_b, 0, 0);
	if (!ft_strcmp("pb", move))
		push_stack(stack_a, stack_b, 0);
	if (!ft_strcmp("rb", move))
		rotate_stack(stack_b, 0, 0);
	if (!ft_strcmp("rrb", move))
		reverse_rotate_stack(stack_b, 0, 0);
	if (!ft_strcmp("ss", move))
		swap_stack(*stack_a, *stack_b, 0);
	if (!ft_strcmp("rr", move))
		rotate_stack(stack_a, stack_b, 0);
	if (!ft_strcmp("rrr", move))
		reverse_rotate_stack(stack_a, stack_b, 0);
}

void	check_move(char **move, t_stack **stack_a, t_moves **moves)
{
	if ((ft_strcmp("sa", *move) && ft_strcmp("sb", *move) \
				&& ft_strcmp("ss", *move) && ft_strcmp("pa", *move) \
				&& ft_strcmp("pb", *move) && ft_strcmp("ra", *move) \
				&& ft_strcmp("rb", *move) && ft_strcmp("rr", *move) \
				&& ft_strcmp("rra", *move) && ft_strcmp("rrb", *move) \
				&& ft_strcmp("rrr", *move)))
	{
		free(*move);
		exit_check(*stack_a, 0, moves, 0);
	}
}
