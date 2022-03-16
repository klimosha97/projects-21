/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:01:27 by mcorneli          #+#    #+#             */
/*   Updated: 2022/03/04 19:01:29 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mlx_rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_im *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_error(char *str, int is_my_error)
{
	if (is_my_error)
		ft_putstr_fd(str, 2);
	else
		perror(str);
	exit(EXIT_FAILURE);
}

void	put_color(t_fract *f)
{
	int	r;
	int	g;
	int	b;

	r = (f->iter % 2) * 32 + f->r + 10;
	g = (f->iter % 4) * 64;
	b = (f->iter % 2) * 16 + f->b + 30;
	my_mlx_pixel_put(f->img, f->x + f->range[0] - f->view[0],
		f->y + f->range[1] - f->view[1],
		mlx_rgb_to_int(20, r, g, b));
}
