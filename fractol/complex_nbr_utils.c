/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_nbr_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:58:44 by mcorneli          #+#    #+#             */
/*   Updated: 2022/03/04 18:58:47 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complx	cmplx_init(double re, double im)
{
	t_complx	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_complx	multi_cmlx(t_complx x, t_complx y)
{
	t_complx	t;

	t.re = x.re * y.re - x.im * y.im;
	t.im = x.re * y.im + x.im * y.re;
	return (t);
}

t_complx	plus_cmlx(t_complx x, t_complx y)
{
	t_complx	t;

	t.re = x.re + y.re;
	t.im = x.im + y.im;
	return (t);
}

double	abs_cmlx(t_complx x)
{
	return (sqrt(x.re * x.re + x.im * x.im));
}
