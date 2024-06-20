/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yojablao <yojablao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:12:35 by yojablao          #+#    #+#             */
/*   Updated: 2024/06/20 21:15:25 by yojablao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(char **v)
{
	int	i;
	int	j;

	if (!v)
		return (0);
	i = 0;
	while (v[i])
	{
		j = i + 1;
		while (v[j])
		{
			if (ft_atoi(v[i]) == ft_atoi(v[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isnum(char **num)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (num[i])
	{
		j = 0;
		while (num[i][j])
		{
			if (!ft_isdigit(num[i][j]) && num[i][0] != '-' && num[i][0] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_e(char **s, int c)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (s[i] && c > i)
	{
		j = 0;
		while (s[i][j] == ' ')
			j++;
		if (s[i][j] == '\0')
			return (0);
		if (s[i][j] != ' ')
			i++;
	}
	return (1);
}

char	**spliter(char **arg, int c)
{
	int		i;
	char	*s;
	char	**tab;

	if (c < 2)
		return (0);
	i = 1;
	s = ft_strdup("");
	if (!s)
		return (0);
	while (i < c)
	{
		s = ft_strjoin(s, arg[i]);
		if (!s)
			return (0);
		s = ft_strjoin(s, " ");
		if (!s)
			return (0);
		i++;
	}
	tab = ft_split(s, ' ');
	free(s);
	i = 0;
	return (tab);
}

// one nbr means its sorted just exit the program.
int	pars_check(char **v, int c, t_list **a)
{
	int		i;
	char	**args;

	i = 0;
	if (check_e(v, c) == 0)
		return (put_error("error", 0), 0);
	args = spliter(v, c);
	if (!args)
		exit(1);
	while (args[i])
	{
		if (e_atoi(args[i]) == 0)
			return (ft_free(args), put_error("error", 1), 0);
		i++;
	}
	if (ft_contains(args) == 0 || ft_isnum(args) == 0)
		return (ft_free(args), put_error("error", 1), 0);
	if (stack_set(a, args, i) == 0)
		return (free(args), put_error("error", 1), 0);
	return (1);
}
