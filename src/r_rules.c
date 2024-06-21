/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:46:14 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/21 18:21:55 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_r(t_list **a)
{
	t_list	*tmp ;
	int		nb;
	int		index;

	if (!a)
		return ;
	tmp = *a;
	nb = tmp->content;
	index = tmp->p;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
		if (tmp->next == NULL)
			tmp->content = nb;
	}
	tmp = *a;
	while (tmp->next)
	{
		tmp->p = tmp->next->p;
		tmp = tmp->next;
		if (tmp->next == NULL)
			tmp->p = index;
	}
}

void	ra(t_list **a)
{
	if (!a)
		return ;
	swap_r(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **b)
{
	if (!b)
		return ;
	swap_r(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **b, t_list **a)
{
	if (!a || !b)
		return ;
	swap_r(b);
	swap_r(a);
	ft_putstr_fd("rr\n", 1);
}

int	lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
