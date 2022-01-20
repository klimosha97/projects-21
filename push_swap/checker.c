/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:50:51 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:50:51 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"
#include "libft/libft.h"

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

void	do_instruct(t_list **a, t_list **b, char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		swap_a(a, 0);
	else if (ft_strncmp(line, "rra", 3) == 0)
		rev_rotate_a(a, 0);
	else if (ft_strncmp(line, "rrb", 3) == 0)
		rev_rotate_b(b, 0);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		rev_rotate_ab(a, b, 0);
	else if (ft_strncmp(line, "sb", 2) == 0)
		swap_b(b, 0);
	else if (ft_strncmp(line, "ss", 2) == 0)
		swap_ab(a, b, 0);
	else if (ft_strncmp(line, "pa", 2) == 0)
		push_a(a, b, 0);
	else if (ft_strncmp(line, "pb", 2) == 0)
		push_b(a, b, 0);
	else if (ft_strncmp(line, "ra", 2) == 0)
		rotate_a(a, 0);
	else if (ft_strncmp(line, "rb", 2) == 0)
		rotate_b(b, 0);
	else if (ft_strncmp(line, "rr", 2) == 0)
		rotate_ab(a, b, 0);
	else
		ft_write_ERROR();
}

void	ft_read_instructions(t_list **a, t_list **b)
{
	char	*line;

	line = NULL;
	while (get_next_line(&line))
	{
		do_instruct(a, b, line);
		line = NULL;
	}
}

int	main(int argc, char	**argv)
{
	t_list		*a;
	t_list		*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(1);
	argc = argc - 1;
	create_stack_a(&a, argc, argv);
	ft_read_instructions(&a, &b);
	if (check_sorted(a) == 2)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	lst_clear(&a);
	lst_clear(&b);
	return (0);
}
