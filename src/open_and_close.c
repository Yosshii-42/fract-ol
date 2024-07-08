/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:25:42 by yotsurud          #+#    #+#             */
/*   Updated: 2024/05/31 15:25:48 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	check_commandline(char *command)
{
	if ((command[0] >= '1' && command[0] <= '7')
		&& (command[2] >= 'a' && command[2] <= 'd')
		&& (command[1] == '-') && (ft_strlen(command) == 3))
		return (TRUE);
	return (FALSE);
}

void	display_error(void)
{
	ft_printf("\n################  Error occured ! ###############\n");
	ft_printf("##                                             ##\n");
	ft_printf("##   Need paramaters                           ##\n");
	ft_printf("##   Please input FRACTAL TYPE & COLOR TYPE    ##\n");
	ft_printf("##   example : ./fractol \"1-a\"                 ##\n");
	ft_printf("##             ./fractol 1-a                   ##\n");
	ft_printf("##                                             ##\n");
	ft_printf("##    < FRACTRAL TYPE >     < COLOR TYPE >     ##\n");
	ft_printf("##    [1] Mandelbrot          [a] Blue         ##\n");
	ft_printf("##    [2] Julia - type 1      [b] Pink         ##\n");
	ft_printf("##    [3]       - type 2      [c] Orange       ##\n");
	ft_printf("##    [4]       - type 3      [d] Purple       ##\n");
	ft_printf("##    [5]       - type 4                       ##\n");
	ft_printf("##    [6]       - type 5                       ##\n");
	ft_printf("##    [7] Burningship                          ##\n");
	ft_printf("##                                             ##\n");
	ft_printf("#################################################\n\n");
}

t_vars	initialization(char *str)
{
	t_vars	env;

	env.command1 = str;
	env.zoom = 0.25;
	env.offset_x = 0.0;
	env.offset_y = 0.0;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIDTH, HEIGHT, "fract-ol");
	env.img.img = mlx_new_image(env.mlx, WIDTH, HEIGHT);
	env.img.addr = mlx_get_data_addr(env.img.img, &env.img.bits_per_pixel,
			&env.img.line_length, &env.img.endian);
	return (env);
}

void	close_window(t_vars *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}
