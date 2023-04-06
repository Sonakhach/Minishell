/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:47:18 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:47:21 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	char			*str;
	unsigned char	d;

	d = c;
	i = 0;
	str = (char *)s;
	while (i < n)
	{
		if ((char)str[i] == (char)d)
			return (str + i);
		i++;
	}
	return (NULL);
}
