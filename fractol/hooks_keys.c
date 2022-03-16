/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:00:10 by mcorneli          #+#    #+#             */
/*   Updated: 2022/03/04 19:00:11 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	control_arrows(int keycode, t_fract *f)
{
	if (keycode == UP)
		f->view[1] -= 10;
	else if (keycode == DOWN)
		f->view[1] += 10;
	else if (keycode == LEFT)
		f->view[0] -= 10;
	else if (keycode == RIGHT)
		f->view[0] += 10;
}

int	key_press(int keycode, t_fract *f)
{
	ft_bzero(f->img->addr, WIDTH * HEIGHT * 4);
	if (keycode == EXIT)
	{
		mlx_destroy_image(f->mlx, f->img->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == PLUS)
		f->max_iter += 1;
	else if (keycode == MINUS)
		f->max_iter -= 1;
	else if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
		control_arrows(keycode, f);
	else if (keycode == C)
	{
		f->r += 15;
		f->b += 35;
	}
	else if (keycode == R)
		init_struct(f);
	choose_fractal(f);
	return (0);
}

int	mouse_press(int keycode, int x, int y, t_fract *f)
{
	if (keycode == 4)
	{
		ft_bzero(f->img->addr, WIDTH * HEIGHT * 4);
		f->scale[0] *= 1.08;
		f->scale[1] *= 1.08;
		f->view[0] = x - f->range[0];
		f->view[1] = y - f->range[1];
		choose_fractal(f);
	}
	if (keycode == 5)
	{
		ft_bzero(f->img->addr, WIDTH * HEIGHT * 4);
		f->scale[0] /= 1.08;
		f->scale[1] /= 1.08;
		f->view[0] = x - f->range[0];
		f->view[1] = y - f->range[1];
		choose_fractal(f);
	}
	return (0);
}

int	red_cross(t_fract *f)
{
	mlx_destroy_image(f->mlx, f->img->img);
	mlx_destroy_window(f->mlx, f->win);
	exit(EXIT_SUCCESS);
}
