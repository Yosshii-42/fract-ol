/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:40:57 by yotsurud          #+#    #+#             */
/*   Updated: 2024/05/30 14:40:59 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_handler(int keycode, t_vars *env)
{
	if (keycode == ON_KEYRIGHT)
		env->offset_x += MOVE_STEP / env->zoom;
	else if (keycode == ON_KEYLEFT)
		env->offset_x -= MOVE_STEP / env->zoom;
	else if (keycode == ON_KEYDOWN)
		env->offset_y += MOVE_STEP / env->zoom;
	else if (keycode == ON_KEYUP)
		env->offset_y -= MOVE_STEP / env->zoom;
	else if (keycode == ON_ESC)
		close_window(env);
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_vars *env)
{
	if (mousecode == ON_MOUSEUP)
	{
		env->zoom *= 1.2;
		env->offset_x += ((x - WIDTH / 2) / (WIDTH * env->zoom)) * 0.2;
		env->offset_y += ((y - HEIGHT / 2) / (HEIGHT * env->zoom)) * 0.2;
	}
	else if (mousecode == ON_MOUSEDOWN)
	{
		env->zoom *= 0.8;
		env->offset_x -= ((x - WIDTH / 2) / (WIDTH * env->zoom)) * 0.2;
		env->offset_y -= ((y - HEIGHT / 2) / (HEIGHT * env->zoom)) * 0.2;
	}
	return (0);
}
