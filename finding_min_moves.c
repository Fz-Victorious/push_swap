/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_min_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:16:05 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 12:08:27 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_moves(int *moves, int len)
{
	int	min_index;
	int	i;

	i = 0;
	min_index = 0;
	while (i < len)
	{
		if (moves[i] < moves[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	min_moves_index(int *a_moves, int *b_moves, int len)
{
	int	*moves;
	int	min_index;
	int	i;

	moves = malloc(sizeof(int) * len);
	if (!moves)
		return (-1);
	i = 0;
	while (i < len)
	{
		if (b_moves[i] * a_moves[i] >= 0)
			moves[i] = max(ft_abs(b_moves[i]), ft_abs(a_moves[i]));
		else
			moves[i] = ft_abs(b_moves[i]) + ft_abs(a_moves[i]);
		i++;
	}
	min_index = min_moves(moves, len);
	free (moves);
	return (min_index);
}

void	sort_elem_with_min_moves(t_stack **stack_a, t_stack **stack_b, \
		int a_mv, int b_mv)
{
	if ((a_mv >= 0 && b_mv >= 0) || (a_mv <= 0 && b_mv <= 0))
		same_sign_moves(stack_a, stack_b, a_mv, b_mv);
	else
		diff_signs(stack_a, stack_b, a_mv, b_mv);
}
