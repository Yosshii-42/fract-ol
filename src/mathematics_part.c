/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathematics_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 21:52:54 by yotsurud          #+#    #+#             */
/*   Updated: 2024/05/29 21:57:48 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	make_mandel_ship(t_vars vars)
{
	t_cal_vars	m;

	m.j = 0;
	while (m.j < HEIGHT)
	{
		m.i = 0;
		m.b = (m.j - HEIGHT / 2) / (HEIGHT * vars.zoom) + vars.offset_y;
		while (m.i < WIDTH)
		{
			m.a = (m.i - WIDTH / 2) / (WIDTH * vars.zoom) + vars.offset_x;
			m.x = 0;
			m.y = 0;
			m.value = 0;
			m.count = 0;
			while (m.count < MAX_COUNT && m.value <= 4)
			{
				m = calculator(m, vars.command1);
				if (m.value > 4 || m.count == MAX_COUNT)
					put_color(vars, m);
			}
			m.i++;
		}
		m.j++;
	}
}

void	make_julia(t_vars vars)
{
	t_cal_vars	j;

	julia_set(&vars);
	j.a = vars.set.num_a;
	j.b = vars.set.num_b;
	j.j = 0;
	while (j.j < HEIGHT)
	{
		j.i = 0;
		while (j.i < WIDTH)
		{
			j.value = 0;
			j.count = 0;
			j.x = (j.i - WIDTH / 2) / (WIDTH * vars.zoom) + vars.offset_x;
			j.y = (j.j - HEIGHT / 2) / (HEIGHT * vars.zoom) + vars.offset_y;
			while (j.value <= 4.0 && j.count < MAX_COUNT)
				j = calculator(j, vars.command1);
			put_color(vars, j);
			j.i++;
		}
		j.j++;
	}
}

t_cal_vars	calculator(t_cal_vars params, char *command1)
{
	if (command1[0] == '7')
	{
			params.xn = fabs(params.x);
			params.yn = fabs(params.y);
	}
	else
	{
		params.xn = params.x;
		params.yn = params.y;
	}
	params.x = params.xn * params.xn - params.yn * params.yn + params.a;
	params.y = 2 * params.xn * params.yn + params.b;
	params.value = params.x * params.x + params.y * params.y;
	params.count++;
	return (params);
}

void	put_color(t_vars vars, t_cal_vars mj)
{
	if (mj.count == MAX_COUNT)
		my_mlx_pixel_put(&vars.img, mj.i, mj.j, 0x00FFFFFFU);
	else
		my_mlx_pixel_put(&vars.img, mj.i, mj.j,
			color(vars.command1, mj.count));
}
