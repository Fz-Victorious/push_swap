/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_in_lis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:20:24 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/09 17:51:06 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_in_lis(int *lis, int nb, int len_lis)
{
	int	i;

	i = 0;
	while (i < len_lis)
	{
		if (nb == lis[i])
			return (1);
		i++;
	}
	return (0);
}

int	rotate_choice(t_stack **stack_a, int *lis, int len, int len_lis)
{
	int		i;
	int		rot_count;
	int		revrot_count;
	t_stack	*p;

	i = 0;
	rot_count = 0;
	revrot_count = 0;
	p = (*stack_a);
	while (i < len / 2)
	{
		if (!is_in_lis(lis, p->data, len_lis))
			rot_count++;
		p = p->next;
		i++;
	}
	while (p)
	{
		if (!is_in_lis(lis, p->data, len_lis))
			revrot_count++;
		p = p->next;
	}
	if (rot_count >= revrot_count)
		return (1);
	return (0);
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b, int *lis, int len_lis)
{
	int	flag;

	flag = rotate_choice(stack_a, lis, ft_stacksize(*stack_a), len_lis);
	while (ft_stacksize(*stack_a) > len_lis)
	{
		if (!is_in_lis(lis, (*stack_a)->data, len_lis))
			push_stack(stack_a, stack_b, "pb\n");
		else if (flag)
			rotate_stack(stack_a, 0, "ra\n");
		else if (!flag)
			reverse_rotate_stack(stack_a, 0, "rra\n");
	}
}
