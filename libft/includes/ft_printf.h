/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 18:11:06 by yotsurud          #+#    #+#             */
/*   Updated: 2024/04/28 16:36:43 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define HEX_UP		"0123456789ABCDEF"
# define HEX_LOW	"0123456789abcdef"
# define DECIMAL    "0123456789"

int		ft_printf(const char *fmt, ...);
int		ft_select_conversion(va_list ap, const char character);
int		ft_put_c(int c);
int		ft_put_s(char *str);
int		ft_put_p(void *ptr);
int		ft_put_di(int nbr);
int		ft_put_uxx(unsigned int nbr, char character);
void	ft_putnbr_base_fd(unsigned long nbr, char *base, int fd, int *count);

#endif
