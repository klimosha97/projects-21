/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:00:31 by mcorneli          #+#    #+#             */
/*   Updated: 2022/03/04 19:00:33 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractal(t_fract *f)
{
	if (f->name == 'j')
		julia(f);
	else if (f->name == 's')
		burning_ship(f);
	else if (f->name == 'm')
		mandelbrot(f);
}

void	init_name(t_fract *f, char *str)
{
	if (ft_strncmp(str, "julia", ft_strlen(str) + 1) == 0)
		f->name = 'j';
	else if (ft_strncmp(str, "mandelbrot", ft_strlen(str) + 1) == 0)
		f->name = 'm';
	else if (ft_strncmp(str, "ship", ft_strlen(str) + 1) == 0)
		f->name = 's';
	else
		ft_error("enter julia | mandelbrot | ship\n", 1);
}

void	init_mlx_and_img(t_fract *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, TITLE);
	f->img = image_init(f->mlx);
	if (f->mlx == 0 || f->win == 0 || f->img == 0)
		ft_error("Error with mlx and image\n", 1);
}

void	init_struct(t_fract *f)
{
	f->range[0] = WIDTH / 2 - 1;
	f->range[1] = HEIGHT / 2 - 1;
	f->scale[0] = f->range[0] / 2;
	f->scale[1] = f->range[1] / 2;
	f->view[0] = 0;
	f->view[1] = 0;
	f->r = 0;
	f->r = 0;
	f->max_iter = 100;
}

t_im	*image_init(void *mlx)
{
	t_im	*image;

	image = (t_im *) malloc(sizeof(t_im));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (image->img == NULL)
	{
		free(image);
		return (NULL);
	}
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return (image);
}
