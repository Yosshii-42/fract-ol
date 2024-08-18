/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_and_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:37:43 by yotsurud          #+#    #+#             */
/*   Updated: 2024/05/10 11:53:18 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_put_s(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}

int	ft_put_p(void *ptr)
{
	int				count;
	unsigned long	nbr;

	nbr = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	count = 2;
	ft_putnbr_base_fd(nbr, HEX_LOW, 1, &count);
	return (count);
}

int	ft_put_di(int nbr)
{
	int		count;
	long	num;

	count = 0;
	num = (long)nbr;
	if (num < 0)
	{
		ft_putchar_fd('-', 1);
		num = -num;
		count++;
	}
	ft_putnbr_base_fd((unsigned int)num, DECIMAL, 1, &count);
	return (count);
}

int	ft_put_uxx(unsigned int nbr, char character)
{
	int	count;

	count = 0;
	if (character == 'u')
		ft_putnbr_base_fd(nbr, DECIMAL, 1, &count);
	if (character == 'x')
		ft_putnbr_base_fd(nbr, HEX_LOW, 1, &count);
	if (character == 'X')
		ft_putnbr_base_fd(nbr, HEX_UP, 1, &count);
	return (count);
}
