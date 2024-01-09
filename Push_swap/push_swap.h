/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:46:55 by junssong          #+#    #+#             */
/*   Updated: 2023/05/17 17:36:17 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				data;
	struct s_list	*next;
}				t_list;

typedef struct s_field
{
	int		alist_min_data;
	int		alist_max_data;
	int		min_rotate_a;
	int		total_count;
	int		rotate_a;
	int		rotate_b;
	int		blist_size;
	int		b_data;
	int		find_index;
	int		size_a;
	int		i;
	int		flag;
	t_list	*tmp;
}				t_field;

int		is_one_argv(t_list **list, char **argv, int **int_list);
int		parse_split_string(char **split_string, t_list **list, int *int_list);
int		is_not_number(char **split_string);
int		is_more_argv(t_list **list, char **argv, int **int_list);
int		parse_argv(int argc, t_list **list_a, char **argv);
void	free_split(char **split_string);
void	sorted_data_list(int *int_list, int argv_num);
void	change_data_to_index(t_list **list, int *int_list);

void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int data);

void	sa(t_list **list_a);
void	sb(t_list **list_b);
void	ss(t_list **list_a, t_list **list_b);
void	pa(t_list **list_a, t_list **list_b);
void	pb(t_list **list_a, t_list **list_b);
void	ra(t_list **list);
void	rb(t_list **list);
void	rr(t_list **list_a, t_list **list_b);
void	rra(t_list **list_a);
void	rrb(t_list **list_b);
void	rrr(t_list **list_a, t_list **list_b);

void	n_rra(t_list **list, int n);
void	n_ra(t_list **list, int n);
void	n_rrb(t_list **list, int n);
void	n_rb(t_list **list, int n);
void	n_rrr(t_list **list_a, t_list **list_b, int n);
void	n_rr(t_list **list_a, t_list **list_b, int n);

int		add_list_top(t_list **list, t_list *node);
t_list	*remove_list_top(t_list **list);

int		is_sorted(t_list **list);
int		intcmp(int a, int b);

void	sort(t_list **list_a, t_list **list_b, int size_a);
void	sort_size2(t_list **list);
void	sort_size3(t_list **list);

void	sort_size5(t_list **list_a, t_list **list_b, int size_a);
int		index_node_middle(t_list **list_a, int list_b_data, int *size_a);
int		make_pa(t_list **list_a, t_list **list_b, int *size_a);
int		is_possible_pa(t_list **list_a, int list_b_data, int *size_a);

void	sort_size_more(t_list **list_a, t_list **list_b, int size_a);
void	less_3_pb(t_list **list_a, t_list **list_b, int size_a, int min_index);
int		stack_count(t_list **list);
void	rr_or_else(t_list **list_a, t_list **list_b,
			int rb_count, int count_ra_rra);
void	rrr_or_else(t_list **list_a, t_list **list_b,
			int rb_count, int count_ra_rra);

int		find_min(t_list **list_a);
int		find_max(t_list **list_a);
int		index_node(t_list **list_a, int min_data, int *size_a);

int		greedy(t_list **list_a, t_list **list_b, int *size_a);
int		greedy_pa(t_list **list_a, t_list **list_b,
			int *count_ra_rra, int *size_a);

void	free_list(t_list **list_a, int size_a);
int		check_dup(t_list **list, t_list *tmp_list);
int		check_sign(char **split_string, int i, int j);
#endif
