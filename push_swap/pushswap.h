#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int		main(int argc, char **argv);
void	swap_a(t_list **a, int flag);
void	swap_b(t_list **b, int flag);
void	swap_ab(t_list **a, t_list **b, int flag);
void	push_a(t_list **a, t_list **b, int flag);
void	push_b(t_list **a, t_list **b, int flag);
void	rotate_a(t_list **a, int flag);
void	rotate_b(t_list **b, int flag);
void	rotate_ab(t_list **a, t_list **b, int flag);
void	rev_rotate_a(t_list **a, int flag);
void	rev_rotate_b(t_list **b, int flag);
void	rev_rotate_ab(t_list **a, t_list **b, int flag);
void	lst_clear(t_list **a);
void	swap_elem(int *arr, int p1, int p2);
void	q_sort(int *array, int start, int end);
int		check_sorted(t_list *a);
void	main_sort(t_list **a, t_list **b, int *array, int agc);
void	triple_check(t_list **a);
void	make_allscore(t_list *b);
void	make_decision(t_list **a, t_list **b, t_list *elem);
void	go_all_to_B(t_list **a, t_list **b, int *array, int size);
void	make_final_sort(t_list **a, int min, int len);
void	sort3to5(t_list **a, t_list **b, int agc);
void	triple_sort(t_list **a);
int		get_next_line(char **line);
void	ft_write_ERROR(void);
void	make_rr(t_list **a, t_list **b, t_list *elem);
void	make_rr_pa(t_list **a, t_list **b, t_list *elem);
void	ft_clean_all(t_list **a, t_list **b, int **array);

#endif
