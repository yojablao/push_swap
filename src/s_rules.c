/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:07:43 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/20 18:34:44 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a)
{
	int		tmp;
	int		i;
	t_list	*stack;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	stack = *a;
	tmp = stack->content;
	i = stack->p;
	stack->content = stack->next->content;
	stack->p = stack->next->p;
	stack->next->content = tmp;
	stack->next->p = i;
}

void	sb(t_list **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	sa(t_list **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
