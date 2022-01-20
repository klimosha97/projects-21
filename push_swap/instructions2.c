/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:51:09 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:51:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	rotate_a(t_list **a, int flag)
{
	t_list	*tmp;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*a)->prev = tmp;
	tmp->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->next->next = NULL;
	tmp = NULL;
	if (flag)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **b, int flag)
{
	t_list	*tmp;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*b)->prev = tmp;
	tmp->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->next->next = NULL;
	tmp = NULL;
	if (flag)
		write(1, "rb\n", 3);
}

void	rotate_ab(t_list **a, t_list **b, int flag)
{
	t_list	*tmp;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*a)->prev = tmp;
	tmp->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->next->next = NULL;
	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	(*b)->prev = tmp;
	tmp->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->next->next = NULL;
	tmp = NULL;
	if (flag)
		write(1, "rr\n", 3);
}

void	rev_rotate_a(t_list **a, int flag)
{
	t_list	*tmp;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	(*a)->prev = tmp->next;
	tmp->next->prev = NULL;
	tmp->next->next = *a;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = NULL;
	if (flag)
		write(1, "rra\n", 4);
}

void	rev_rotate_b(t_list **b, int flag)
{
	t_list	*tmp;

	if (b == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	if ((*b) == NULL && (*b)->next == NULL)
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	(*b)->prev = tmp->next;
	tmp->next->prev = NULL;
	tmp->next->next = *b;
	*b = tmp->next;
	tmp->next = NULL;
	tmp = NULL;
	if (flag)
		write(1, "rrb\n", 4);
}
