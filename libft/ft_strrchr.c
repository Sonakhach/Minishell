/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:51:42 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:51:45 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char	*s, int c)
{
	int		i;
	int		j;
	char	l;

	l = c;
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j++;
		i++;
	}
	while (j >= 0)
	{
		if (s[j] == l)
			return ((char *)&s[j]);
		j--;
	}
	return (NULL);
}
