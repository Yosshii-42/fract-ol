/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsurud <yotsurud@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:21:56 by yotsurud          #+#    #+#             */
/*   Updated: 2024/04/20 20:14:31 by yotsurud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_cp;
	char	*s2_cp;
	char	*tmp;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	s1_cp = (char *)s1;
	s2_cp = (char *)s2;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tmp)
		return (NULL);
	result = tmp;
	while (*s1_cp)
		*(tmp++) = *(s1_cp++);
	while (*s2_cp)
		*(tmp++) = *(s2_cp++);
	*tmp = '\0';
	return (result);
}
