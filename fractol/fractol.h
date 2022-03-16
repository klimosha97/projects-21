/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:59:13 by mcorneli          #+#    #+#             */
/*   Updated: 2022/03/04 18:59:16 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define TITLE		"Fractol"
# define HEIGHT		801
# define WIDTH		801
# define EXIT 53
# define PLUS 24
# define MINUS 27
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define C 8
# define R 15
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct s_complx
{
	double	im;
	double	re;
}				t_complx;

typedef struct s_rgba
{
	uint8_t				b;
	uint8_t				g;
	uint8_t				r;
	uint8_t				a;
}				t_rgba;

typedef struct s_im {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_im;

typedef struct s_fract
{
	void		*mlx;
	void		*win;
	t_im		*img;
	t_complx	z;
	t_complx	c;
	int			iter;
	int			max_iter;
	int			y;
	int			x;
	int			range[2];
	double		scale[2];
	int			view[2];
	char		name;
	int			r;
	int			b;
}				t_fract;

t_complx	cmplx_init(double re, double im);
t_complx	multi_cmlx(t_complx x, t_complx y);
t_complx	plus_cmlx(t_complx x, t_complx y);
double		abs_cmlx(t_complx x);
void		my_mlx_pixel_put(t_im *data, int x, int y, int color);
int			red_cross(t_fract *f);
void		julia(t_fract *f);
void		mandelbrot(t_fract *f);
void		burning_ship(t_fract *f);
t_im		*image_init(void *mlx);
void		put_color(t_fract *f);
void		ft_error(char *str, int is_my_error);
void		init_name(t_fract *f, char *str);
void		init_struct(t_fract *f);
void		choose_fractal(t_fract *f);
int			key_press(int keycode, t_fract *f);
int			mouse_press(int keycode, int x, int y, t_fract *f);
void		init_mlx_and_img(t_fract *f);

#endif
