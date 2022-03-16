/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:00:50 by mcorneli          #+#    #+#             */
/*   Updated: 2022/03/04 19:00:53 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help(void)
{
	ft_putstr_fd("------------------------------------\n", 1);
	ft_putstr_fd("-*-*-  KEYS FOR USING PROGRAM  -*-*-\n", 1);
	ft_putstr_fd("------------------------------------\n", 1);
	ft_putstr_fd("-*- Moves          [←][↑][↓][→]  -*-\n", 1);
	ft_putstr_fd("-*- Iterations     [-][+]        -*-\n", 1);
	ft_putstr_fd("-*- Color          [C]           -*-\n", 1);
	ft_putstr_fd("-*- Reset          [R]           -*-\n", 1);
	ft_putstr_fd("-*- Exit           [esc]         -*-\n", 1);
	ft_putstr_fd("------------------------------------\n", 1);
}

int	main(int argc, char **argv)
{
	t_fract	p;

	if (argc > 4 || argc == 3 || argc < 2)
		ft_error("enter julia | mandelbrot | ship\n", 1);
	init_name(&p, argv[1]);
	init_mlx_and_img(&p);
	if (p.name == 'j' && argc == 4)
		p.c = cmplx_init(ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		p.c = cmplx_init(0.36, 0.36);
	init_struct(&p);
	choose_fractal(&p);
	mlx_mouse_hook(p.win, mouse_press, &p);
	mlx_hook(p.win, 2, 0, key_press, &p);
	mlx_hook(p.win, 17, 0, red_cross, &p);
	help();
	mlx_loop(p.mlx);
	return (0);
}
