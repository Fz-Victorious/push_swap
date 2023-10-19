/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:10:18 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 21:33:15 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_application(t_stack **stack_a, t_stack **stack_b, \
		t_moves *moves)
{
	while (moves)
	{
		moves_decision(stack_a, stack_b, (char *)moves->content);
		moves = moves->next;
	}
}

void	stock_moves(t_stack **stack_a, t_moves **moves)
{
	char	*move;
	t_moves	*new_move;

	move = get_next_line(0);
	while (move != NULL)
	{
		check_move(&move, stack_a, moves);
		new_move = ft_moves_new(move);
		if (!new_move)
		{
			free(move);
			exit_check(*stack_a, 0, moves, 0);
		}
		ft_movesadd_back(moves, new_move);
		move = get_next_line(0);
	}
	free(move);
}

void	check_and_create_checker(char **av, t_stack **stack_a)
{
	int			i;
	long long	data;
	t_stack		*new_node;

	i = 0;
	while (av[i])
	{
		if (!(is_num(av[i])))
			free_and_exitcheck(av, stack_a);
		data = ft_atoi(av[i]);
		if (!is_integer(data))
			free_and_exitcheck(av, stack_a);
		new_node = ft_stacknew(data);
		if (new_node == NULL)
			free_and_exitcheck(av, stack_a);
		ft_stackadd_back(stack_a, new_node);
		i++;
	}
}

void	manage_args_check(char **av, t_stack **stack_a)
{
	int		i;
	char	**arg;

	i = 0;
	while (av[i])
	{
		if (av[i][0] == '\0')
			exit_check(*stack_a, 0, 0, 0);
		arg = ft_split(av[i], ' ');
		if (arg == NULL)
		{
			free_mem(arg);
			exit_check(*stack_a, 0, 0, 0);
		}
		check_and_create_checker(arg, stack_a);
		free_mem(arg);
		i++;
	}
	if (!is_duplicate(stack_a))
		exit_check(*stack_a, 0, 0, 0);
}

int	main(int argc, char **argv)
{
	t_moves	*moves;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		exit(0);
	moves = 0;
	stack_a = 0;
	stack_b = 0;
	manage_args_check(&argv[1], &stack_a);
	stock_moves(&stack_a, &moves);
	moves_application(&stack_a, &stack_b, moves);
	if (is_sorted(stack_a) && !stack_b)
		exit_check(stack_a, stack_b, &moves, 2);
	exit_check(stack_a, stack_b, &moves, 1);
	return (0);
}
