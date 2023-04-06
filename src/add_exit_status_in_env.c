/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_exit_status_in_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:53:20 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:53:23 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_exit_status_in_env(t_data *data, int status)
{
	char	*tmp;

	tmp = ft_itoa(status);
	ft_t_env_add_back(&data->head_env, new_t_env("?", tmp));
	free(tmp);
	return (1);
}
