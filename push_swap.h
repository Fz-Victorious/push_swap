/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:35:56 by fabou-za          #+#    #+#             */
/*   Updated: 2022/08/15 21:34:44 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>

typedef struct s_lis_info
{
	int	len;
	int	len_lis;
	int	index;
}		t_lis_info;
typedef struct s_stack
{
	int				data;
	int				pos;
	struct s_stack	*next;
}				t_stack;

typedef struct s_moves
{
	void	*content;
	void	*next;
}			t_moves;

void	freeing_memory(int **arr1, int **arr2);
void	alloc_for_arrays_moves(t_stack **stack_a, \
		t_stack **stack_b, int **a_mov, int **b_mov);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackdel_node(t_stack **stack);
void	ft_stackclear(t_stack **stack);
int		ft_stacksize(t_stack *stack);
int		ft_stack_max(t_stack *stack);
long	ft_atoi(const char *str);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_stacknew(int data);
int		ft_stack_min(t_stack *stack);
void	check_and_create(char **av, t_stack **stack);
void	ft_putstr(char *message);
void	ft_stackdel_last(t_stack **stack);
int		is_integer(long long int data);
int		is_num(char *av);
int		is_sorted(t_stack *stack);
int		is_duplicate(t_stack **av);
void	exit_push_swap(t_stack *stack_a, t_stack *stack_b, int is_succes);
void	ft_swap(int *data_a, int *data_b);
void	swap_stack(t_stack *main_stack, t_stack *other_stack, char *message);
void	push_stack(t_stack **from_stack, t_stack **to_stack, char *message);
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_stack(t_stack **main_stack, t_stack **other_stack, \
		char *message);
void	reverse_rotate_stack(t_stack **main_stack, \
		t_stack **other_stack, char *message);
void	sorting_stack_len_two(t_stack **stack_a);
void	sorting_small_stack(t_stack **stack_a, \
		t_stack **stack_b, int stack_len);
int		is_in_lis(int *lis, int nb, int len_lis);
int		rotate_choice(t_stack **stack_a, int *lis, int len, int len_lis);
void	push_to_b(t_stack **stack_a, t_stack **stack_b, int *lis, int len_lis);
void	sorting_medium_stack(t_stack **stack_a, t_stack **stack_b);
int		*longest_inc_sub(t_stack *stack_a, int *len_lis);
void	sub_len_arr(int *arr_min, int **sub_len, int **sub, int len);
void	start_from_min(int **arr, t_stack *stack_a, int len);
int		*the_lis(int *arr, int *index_sub, int index, int len_lis);
int		len_of_lis(int *sub_len, int len, int *index);
void	sorting_big_stack(t_stack **stack_a, t_stack **stack_b);
// functions to find position in a and b
void	elem_moves_in_b(t_stack **stack_b, int *arr);
void	moves_top_a(t_stack **stack_a);
int		max_a_pos(t_stack *stack_a, int len);
int		is_bigger_than_max(t_stack **stack_a, int number);
int		find_position(t_stack **stack_a, int len, int number);
void	elem_moves_in_a(t_stack **stack_a, t_stack **stack_b, int *arr);
// functions to find min moves
int		ft_abs(int a);
int		max(int a, int b);
int		min_moves(int *moves, int len);
int		min_moves_index(int *a_moves, int *b_moves, int len);
//sort the elem with min moves
int		min(int a, int b);
void	sort_elem_with_min_moves(t_stack **stack_a, \
		t_stack **stack_b, int a_mv, int b_mv);
void	checker_func(t_stack **stack_a, t_stack **stack_b, \
		int a_movs, int b_movs);
void	same_sign_moves(t_stack **stack_a, t_stack **stack_b, \
		int a_moves, int b_moves);
void	b_moves(t_stack **stack_b, int b_moves);
void	a_moves(t_stack **stack_a, int a_moves);
void	diff_signs(t_stack **stack_a, t_stack **stack_b, \
		int a_mov, int b_mov);
//start stack a from min to be sorted
int		min_pos(t_stack *stack_a);
void	rotate_to_start_min(t_stack **stack_a);
//functions utils for get_next_line
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *str, int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
//checker utils
void	exit_check(t_stack *stack_a, t_stack *stack_b, \
		t_moves **moves, int message);
void	moves_decision(t_stack **stack_a, t_stack **stack_b, char *move);
void	moves_application(t_stack **stack_a, \
		t_stack **stack_b, t_moves *moves);
int		check_moves(char **moves);
void	check_move(char **move, t_stack **stack_a, t_moves **moves);
void	stock_moves(t_stack **stack_a, t_moves **moves);
void	ft_movesadd_back(t_moves **alst, t_moves *new);
void	ft_moves_clear(t_moves **move);
void	ft_movesdel_node(t_moves **move);
t_moves	*ft_moves_new(void *content);
int		ft_strcmp(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	check_and_create_cheker(char **av, t_stack **stack_a);
void	manage_args_check(char **av, t_stack **stack_a);
void	manage_args(char **av, t_stack **stack_a);
void	free_mem(char **av);
void	free_and_exit(char **av, t_stack **stack_a);
void	free_and_exitcheck(char **av, t_stack **stack_a);

#endif
