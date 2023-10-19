/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 19:17:41 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 12:11:45 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_of_lis(int *sub_len, int len, int *index)
{
	int	max;
	int	i;

	max = sub_len[0];
	i = 0;
	while (i < len)
	{
		if (sub_len[i] > max)
		{
			max = sub_len[i];
			(*index) = i;
		}
		i++;
	}
	return (max);
}

int	*the_lis(int *arr, int *index_sub, int index, int len_lis)
{
	int	i;
	int	j;
	int	*lis;

	lis = malloc(len_lis * sizeof(int));
	if (!lis)
		return (NULL);
	i = index;
	j = len_lis - 1;
	while (index >= 0 && j >= 0)
	{
		lis[j] = arr[index];
		index = index_sub[index];
		j--;
	}
	return (lis);
}

void	start_from_min(int **arr, t_stack *stack_a, int len)
{
	int		min_of_stack;
	int		j;
	t_stack	*head;

	min_of_stack = ft_stack_min(stack_a);
	head = stack_a;
	while (head->data != min_of_stack)
		head = head->next;
	j = 0;
	while (head)
	{
		(*arr)[j] = head->data;
		head = head->next;
		j++;
	}
	head = stack_a;
	while (head->data != min_of_stack && j < len)
	{
		(*arr)[j] = head->data;
		head = head->next;
		j++;
	}
}

void	sub_len_arr(int *arr_min, int **sub_len, int **sub, int len)
{
	int	i;
	int	j;

	j = 0;
	while (j < len)
	{
		(*sub_len)[j] = 1;
		(*sub)[j] = -1;
		j++;
	}
	(*sub)[0] = arr_min[0];
	i = 0;
	while (++i < len)
	{
		j = 0;
		while (j < i)
		{
			if (arr_min[j] < arr_min[i] && (*sub_len)[j] + 1 > (*sub_len)[i])
			{
				(*sub_len)[i] += 1;
				(*sub)[i] = j;
			}
			j++;
		}
	}
}

int	*longest_inc_sub(t_stack *stack_a, int *len_lis)
{	
	t_lis_info	info;
	int			*sub_len;
	int			*sub;
	int			*lis;
	int			*arr_min;

	info.len = ft_stacksize(stack_a);
	sub_len = (int *) malloc(info.len * sizeof(int));
	sub = (int *) malloc(info.len * sizeof(int));
	arr_min = malloc(info.len * sizeof(int));
	if (!sub_len || !sub || !arr_min)
		return (NULL);
	start_from_min(&arr_min, stack_a, info.len);
	sub_len_arr(arr_min, &sub_len, &sub, info.len);
	info.index = 0;
	(*len_lis) = len_of_lis(sub_len, info.len, &info.index);
	lis = the_lis(arr_min, sub, info.index, (*len_lis));
	free(sub_len);
	free(sub);
	free(arr_min);
	return (lis);
}
