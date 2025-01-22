/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehmy <jmehmy@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:45:18 by jmehmy            #+#    #+#             */
/*   Updated: 2025/01/22 10:36:17 by jmehmy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <errno.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(int content);
int					ft_lstsize(t_list **lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				handle_sorting(t_list **a, t_list **b, int count);
int					process_single_input(t_list **a, char *list);
int					process_multiple_inputs(t_list **a, char **list);
void				sort_3(t_list **a);
void				sort_4(t_list **a, t_list **b);
void				sort_5(t_list **a, t_list **b);
void				radix(t_list **a, t_list **b);
int					find_min(t_list **a);
int					find_next_min(t_list **a, long long min);
int					find_distance(t_list **a, int min);
t_list				*find_min_list(t_list **a, long long min);
bool				is_number(long long num, char *str);
int					find_bits(t_list **a);
void				assign_indexes(t_list **a);
void				move_min_to_top(t_list **a, int min);
int					ft_strcmp(char *s1, char *s2);
void				ft_perror(void);
void				find_repeats(char **list);
int					check_sort(t_list **a);
void				swap(t_list **a);
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
void				push(t_list **src, t_list **dst);
void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				rotate(t_list **stack);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				reverse_rotate(t_list **stack);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
void				ft_free(t_list **a);
int					ft_atoi(char *str);
char				**ft_split(const char *s, char c);


#endif
