/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:43:52 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 17:46:38 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(int fd, const char *str, ...);
int				ft_convert(va_list arg, const char form, int fd);
int				ft_print_percent(int fd);
int				ft_s(char *str, int fd);
int				ft_c(char c, int fd);
int				ft_xl(unsigned int n, int fd);
int				ft_xu(unsigned int n, int fd);
int				ft_u(unsigned int n, int fd);
int				ft_p(unsigned long int n, int fd);
int				ft_d(int n, int fd);
int				ft_nbr_count(long long int n, const char *base, int fd);
unsigned int	ft_strlen_ft(char const *str);

#endif
