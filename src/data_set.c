/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:34:04 by yotsurud          #+#    #+#             */
/*   Updated: 2024/05/30 14:34:47 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia_set(t_vars *vars)
{
	if (vars->command1[0] == '2')
	{
		vars->set.num_a = -0.6701;
		vars->set.num_b = 0.4539;
	}
	else if (vars->command1[0] == '3')
	{
		vars->set.num_a = 0.3;
		vars->set.num_b = 0.5;
	}
	else if (vars->command1[0] == '4')
	{
		vars->set.num_a = -0.8;
		vars->set.num_b = 0.15;
	}
	else if (vars->command1[0] == '5')
	{
		vars->set.num_a = -0.439165;
		vars->set.num_b = 0.574507;
	}
	else if (vars->command1[0] == '6')
	{
		vars->set.num_a = 0.27334;
		vars->set.num_b = 0.00742;
	}
}

unsigned int	color(char *command, int count)
{
	if (command[2] == 'a')
		return (0x00000000U + count * 1000);
	if (command[2] == 'b')
		return (0x00FF00FFU - count * 10000);
	if (command[2] == 'c')
		return (0x00FF0000U + count * 10000);
	if (command[2] == 'd')
		return (0x004b0082U + count * 10000);
	return (-1);
}
