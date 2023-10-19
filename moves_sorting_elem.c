/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sorting_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:36:18 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/13 12:43:41 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_func(t_stack **stack_a, t_stack **stack_b, \
		int a_movs, int b_movs)
{
	int	max_moves;

	max_moves = max(ft_abs(a_movs), ft_abs(b_movs));
	if (max_moves == ft_abs(a_movs))
	{
		if (a_movs >= 0 && b_movs >= 0)
			rotate_stack(stack_a, 0, "ra\n");
		else
			reverse_rotate_stack(stack_a, 0, "rra\n");
	}
	else if (max_moves == ft_abs(b_movs))
	{
		if (a_movs >= 0 && b_movs >= 0)
			rotate_stack(stack_b, 0, "rb\n");
		else
			reverse_rotate_stack(stack_b, 0, "rrb\n");
	}
}

void	same_sign_moves(t_stack **stack_a, t_stack **stack_b, \
		int a_mov, int b_mov)
{
	int	min_moves;
	int	max_moves;
	int	substract;

	min_moves = min(ft_abs(a_mov), ft_abs(b_mov));
	max_moves = max(ft_abs(a_mov), ft_abs(b_mov));
	substract = max_moves - min_moves;
	if ((a_mov >= 0 && b_mov >= 0) \
			|| (a_mov <= 0 && b_mov <= 0))
	{
		while (min_moves > 0)
		{
			if (a_mov >= 0 && b_mov >= 0)
				rotate_stack(stack_a, stack_b, "rr\n");
			else
				reverse_rotate_stack(stack_a, stack_b, "rrr\n");
			min_moves--;
		}
		while (substract > 0)
		{
			checker_func(stack_a, stack_b, a_mov, b_mov);
			substract--;
		}
	}
	push_stack(stack_b, stack_a, "pa\n");
}

void	b_moves(t_stack **stack_b, int b_mov)
{
	int	moves;

	moves = ft_abs(b_mov);
	if (b_mov >= 0)
	{
		while (moves > 0)
		{
			rotate_stack(stack_b, 0, "rb\n");
			moves--;
		}
	}
	else
	{
		while (moves > 0)
		{
			reverse_rotate_stack(stack_b, 0, "rrb\n");
			moves--;
		}
	}
}

void	a_moves(t_stack **stack_a, int a_mov)
{
	int	moves;

	moves = ft_abs(a_mov);
	if (a_mov >= 0)
	{
		while (moves > 0)
		{
			rotate_stack(stack_a, 0, "ra\n");
			moves--;
		}
	}
	else
	{
		while (moves > 0)
		{
			reverse_rotate_stack(stack_a, 0, "rra\n");
			moves--;
		}
	}
}

void	diff_signs(t_stack **stack_a, t_stack **stack_b, \
		int a_mov, int b_mov)
{
	a_moves(stack_a, a_mov);
	b_moves(stack_b, b_mov);
	push_stack(stack_b, stack_a, "pa\n");
}
