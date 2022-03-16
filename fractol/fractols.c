/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:59:48 by mcorneli          #+#    #+#             */
/*   Updated: 2022/03/04 18:59:51 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fract *f)
{
	f->max_iter = 100;
	f->y = f->range[1] * (-1) + f->view[1];
	while (f->y++ < f->range[1] + f->view[1])
	{
		f->x = f->range[0] * (-1) + f->view[0];
		while (f->x++ < f->range[0] + f->view[0])
		{
			f->iter = 0;
			f->c = cmplx_init((double )f->x / f->scale[0],
					(double )f->y / f->scale[1]);
			f->z = cmplx_init(0, 0);
			while (f->iter++ < f->max_iter)
			{
				f->z = multi_cmlx(f->z, f->z);
				f->z = plus_cmlx(f->z, f->c);
				if (abs_cmlx(f->z) > 2)
				{
					put_color(f);
					break ;
				}
			}
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}

void	burning_ship(t_fract *f)
{
	f->y = f->range[1] * (-1) + f->view[1];
	while (f->y++ < f->range[1] + f->view[1])
	{
		f->x = f->range[0] * (-1) + f->view[0];
		while (f->x++ < f->range[0] + f->view[0])
		{
			f->iter = 0;
			f->c = cmplx_init((double )f->x / f->scale[0],
					(double )f->y / f->scale[1]);
			f->z = cmplx_init(0, 0);
			while (f->iter++ < f->max_iter)
			{
				f->z.re = fabs(f->z.re);
				f->z.im = fabs(f->z.im);
				f->z = plus_cmlx(multi_cmlx(f->z, f->z), f->c);
				if (abs_cmlx(f->z) > 2)
				{
					put_color(f);
					break ;
				}
			}
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}

void	julia(t_fract *f)
{
	f->y = f->range[1] * (-1) + f->view[1];
	while (f->y++ < f->range[1] + f->view[1])
	{
		f->x = f->range[0] * (-1) + f->view[0];
		while (f->x++ < f->range[0] + f->view[0])
		{
			f->iter = 0;
			f->z = cmplx_init((double )f->x / f->scale[0],
					(double )f->y / f->scale[1]);
			while (f->iter++ < f->max_iter)
			{
				f->z = multi_cmlx(f->z, f->z);
				f->z = plus_cmlx(f->z, f->c);
				if (abs_cmlx(f->z) > 2)
				{
					put_color(f);
					break ;
				}
			}
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img->img, 0, 0);
}
