/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_in_stack_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:24:40 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/09 18:31:20 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	elem_moves_in_b(t_stack **stack_b, int *arr)
{
	int	i;
	int	len;

	len = ft_stacksize(*stack_b);
	i = 0;
	while (i <= len / 2)
	{
		(arr[i]) = i;
		i++;
	}
	while (i < len)
	{
		(arr[i]) = (len - i) * (-1);
		i++;
	}
}
