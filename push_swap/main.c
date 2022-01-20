/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:51:12 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:51:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

void	create_stack_a(t_list **a, int agc, char **agv)
{
	int			i;
	t_list		*start;
	long long	num;

	i = agc;
	while (i > 0)
	{
		ft_lstadd_front(a, ft_lstnew(ft_atoi(agv[i])));
		start = (*a)->next;
		num = (*a)->content;
		while (start != NULL)
		{
			if (num == start->content)
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			start = start->next;
		}
		i--;
	}
}

void	create_array(int **array, int agc, char **agv)
{
	int	i;

	i = 0;
	*array = (int *) malloc(sizeof(int) * agc);
	if (!(*array))
		exit(1);
	while (i < agc)
	{
		(*array)[i] = (int)ft_atoi(agv[i + 1]);
		i++;
	}
}

int	main(int argc, char	**argv)
{
	t_list		*a;
	t_list		*b;
	int			*array;
	int			check_sort;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	argc = argc - 1;
	create_stack_a(&a, argc, argv);
	check_sort = check_sorted(a);
	if (check_sort == 1)
	{
		create_array(&array, argc, argv);
		q_sort(array, 0, argc - 1);
		make_final_sort(&a, array[0], argc);
	}
	else if (check_sort == -1)
	{
		create_array(&array, argc, argv);
		main_sort(&a, &b, array, argc);
	}
	ft_clean_all(&a, &b, &array);
	return (0);
}
