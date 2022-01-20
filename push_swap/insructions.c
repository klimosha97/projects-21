/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insructions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:51:04 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:51:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	swap_a(t_list **a, int flag)
{
	long long	tmp;

	if (a == NULL || *a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **b, int flag)
{
	long long	tmp;

	if (b == NULL || *b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	swap_ab(t_list **a, t_list **b, int flag)
{
	long long	tmp;

	if (a == NULL || *a == NULL)
		return ;
	if ((*a)->next == NULL)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (b == NULL || *b == NULL)
		return ;
	if ((*b)->next == NULL)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
	if (flag)
		write(1, "ss\n", 3);
}

void	push_a(t_list **a, t_list **b, int flag)
{
	t_list	*tmp;

	if ((*b) == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	tmp = NULL;
	if (flag)
		write(1, "pa\n", 3);
}

void	push_b(t_list **a, t_list **b, int flag)
{
	t_list	*tmp;

	if (*a == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	tmp = NULL;
	if (flag)
		write(1, "pb\n", 3);
}
