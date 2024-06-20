/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:46:09 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/20 18:29:39 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_rr(t_list **a)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*second_last;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next != NULL)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	last = tmp;
	if (second_last)
	{
		second_last->next = NULL;
		last->next = *a;
		*a = last;
	}
}

void	rra(t_list **a)
{
	swap_rr(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list **b)
{
	swap_rr(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	swap_rr(a);
	swap_rr(b);
	ft_putstr_fd("rrr\n", 1);
}
