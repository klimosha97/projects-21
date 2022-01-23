/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:51:14 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:51:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

int	score_brr(t_list *b)
{
	int	i;

	i = 0;
	if ((b->next == NULL) && b->prev != NULL)
		return (1);
	if (b->next == NULL)
		return (0);
	while (b->next != NULL)
	{
		i++;
		b = b->next;
	}
	return (i + 1);
}

int	score_ar(t_list **a, long long b)
{
	t_list	*p_start;
	t_list	*p_fin;
	int		i;

	p_start = *a;
	i = 0;
	p_fin = *a;
	while (p_fin->next != NULL)
		p_fin = p_fin->next;
	while (b > p_start->content || b < p_fin->content)
	{
		p_fin = p_start;
		p_start = p_start->next;
		i++;
	}
	return (i);
}

int	score_arr(t_list **a, long long b)
{
	t_list	*p_start;
	t_list	*p_fin;
	int		i;

	p_start = *a;
	i = 0;
	p_fin = *a;
	while (p_fin->next != NULL)
		p_fin = p_fin->next;
	while (b > p_start->content || b < p_fin->content)
	{
		p_start = p_fin;
		p_fin = p_fin->prev;
		i++;
	}
	return (i);
}

t_list	*scoring_steps(t_list **a, t_list **b)
{
	int		i;
	t_list	*min;
	t_list	*pb;

	pb = *b;
	min = pb;
	i = -1;
	while (pb != NULL)
	{
		i++;
		pb->s_br = i;
		pb->s_ar = score_ar(a, pb->content);
		pb->s_arr = score_arr(a, pb->content);
		pb->s_brr = score_brr(pb);
		make_allscore(pb);
		if (pb->all_score < min->all_score)
			min = pb;
		pb = pb->next;
	}
	return (min);
}

void	main_sort(t_list **a, t_list **b, int *array, int agc)
{
	if (agc > 2 && agc < 6)
	{
		sort3to5(a, b, agc);
		q_sort(array, 0, agc - 1);
		if (array[0] != (*a)->content)
			make_final_sort(a, array[0], agc);
		return ;
	}
	q_sort(array, 0, agc - 1);
	go_all_to_b(a, b, array, agc);
	triple_check(a);
	while (*b)
		make_decision(a, b, scoring_steps(a, b));
	if (array[0] != (*a)->content)
		make_final_sort(a, array[0], agc);
}
