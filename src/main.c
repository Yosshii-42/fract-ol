/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:57:12 by yotsurud          #+#    #+#             */
/*   Updated: 2024/05/29 21:48:40 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_next_frame(void *params)
{
	t_vars	*env;

	env = (t_vars *)params;
	if (env->command1[0] == '1' || env->command1[0] == '7')
		make_mandel_ship(*env);
	else if (env->command1[0] >= '2' && env->command1[0] <= '6')
		make_julia(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->img.img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	env;

	if (argc != 2 || !(check_commandline(argv[1])))
	{
		display_error();
		return (1);
	}
	env = initialization(argv[1]);
	mlx_mouse_hook(env.win, mouse_handler, &env);
	mlx_key_hook(env.win, key_handler, &env);
	mlx_loop_hook(env.mlx, render_next_frame, &env);
	mlx_hook(env.win, ON_DESTROY, 0, (int (*)())close_window, &env);
	mlx_loop(env.mlx);
	return (0);
}
