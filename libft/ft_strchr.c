/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:48:56 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:48:59 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char	*s, int c)
{
	int		i;
	char	l;

	i = 0;
	l = c;
	while (s[i] && s[i] != l)
		i++;
	if (s[i] == l)
		return ((char *)&s[i]);
	return (NULL);
}
