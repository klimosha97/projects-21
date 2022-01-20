/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:50:37 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:50:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	swap_elem(int *arr, int p1, int p2)
{
	int	tmp;

	tmp = arr[p1];
	arr[p1] = arr[p2];
	arr[p2] = tmp;
}

int	partition(int *array, int start, int end)
{
	int	pos;
	int	i;

	i = start;
	pos = start;
	while (i < end)
	{
		if (array[i] <= array[end])
		{
			swap_elem(array, i, pos);
			pos++;
		}
		i++;
	}
	swap_elem(array, pos, end);
	return (pos);
}

void	q_sort(int *array, int start, int end)
{
	int	pivot;

	if (start >= end)
		return ;
	pivot = partition(array, start, end);
	q_sort(array, start, pivot - 1);
	q_sort(array, pivot + 1, end);
}

int	check_sorted(t_list *a)
{
	long long	start;

	start = a->content;
	while (a->next != NULL && (a->content < a->next->content))
		a = a->next;
	if (a->next == NULL)
		return (2);
	a = a->next;
	while (a->next != NULL)
	{
		if ((a->content > a->next->content) || (a->content > start))
			return (-1);
		a = a->next;
	}
	if (a->content > start)
		return (-1);
	return (1);
}

void	make_final_sort(t_list **a, int min, int len)
{
	int		i;
	t_list	*start;

	i = 0;
	start = *a;
	while (min != start->content)
	{
		i++;
		start = start->next;
	}
	if (i <= len / 2)
	{
		while (i-- > 0)
			rotate_a(a, 1);
	}
	else
	{
		i = len - i;
		while (i-- > 0)
			rev_rotate_a(a, 1);
	}
}
