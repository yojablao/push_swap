/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 04:42:46 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/21 18:17:51 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	int				p;
	int				content;
	struct s_list	*next;
}					t_list;
void	ft_free(char **str);
char	**spliter(char **arg, int c);
void	put_error(char *str, int i);
int		set_index(t_list **a);
int		stack_set(t_list **a, char **nb, int size);
int		ft_isnum(char **num);
void	tl_free(t_list **t);
void	push_back_a(t_list **a, t_list **b);
int		e_atoi(char *str);
int		sort_deja(t_list *a);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
int		small(t_list **a, int *p);
int		lstsize(t_list *lst);
t_list	*lstnew(int content);
int		pars_check(char **argv, int argc, t_list **a);
void	ss(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **b, t_list **a);
void	rrr(t_list **b, t_list **a);
void	rra(t_list **a);
void	rrb(t_list **b);
void	sort(t_list **a, t_list **b, int size);
int		biger(t_list **a, int *p);
#endif