/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_in_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokhacha <sokhacha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 15:56:58 by sokhacha          #+#    #+#             */
/*   Updated: 2023/04/06 15:57:01 by sokhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_one_cmd(t_data *data, t_pipe *pipe)
{
	if (data->pipe_count == 1)
	{
		if (pipe->fd_in != 0)
			dup2(pipe->fd_in, STDIN_FILENO);
		if (pipe->fd_out != 1)
			dup2(pipe->fd_out, STDOUT_FILENO);
		lsh_launch(data, pipe);
		exit(0);
	}
}

static void	dup_first_cmd(t_data *data, t_pipe *pipe)
{
	if (pipe->fd_in != 0)
		dup2(pipe->fd_in, STDIN_FILENO);
	if (pipe->fd_out != 1)
		dup2(pipe->fd_out, STDOUT_FILENO);
	else
		dup2(data->fd1[1], STDOUT_FILENO);
}

static void	dup_last_cmd(t_data *data, t_pipe *pipe)
{
	if (pipe->fd_out != 1)
		dup2(pipe->fd_out, STDOUT_FILENO);
	if (pipe->fd_in != 0)
		dup2(pipe->fd_in, STDIN_FILENO);
	else
		dup2(data->pipe_fd, STDIN_FILENO);
}

static void	dup_middle_cmd(t_data *data, t_pipe *pipe)
{
	if (pipe->fd_in != 0)
		dup2(pipe->fd_in, STDIN_FILENO);
	else
		dup2(data->pipe_fd, STDIN_FILENO);
	if (pipe->fd_out != 1)
		dup2(pipe->fd_out, STDOUT_FILENO);
	else
		dup2(data->fd1[1], STDOUT_FILENO);
}

void	pipe_in_out(int i, t_data *data, t_pipe *pipe)
{
	execute_one_cmd(data, pipe);
	if (i == 0)
		dup_first_cmd(data, pipe);
	else if (i == data->pipe_count - 1)
		dup_last_cmd(data, pipe);
	else
		dup_middle_cmd(data, pipe);
	close(data->fd1[0]);
	close(data->fd1[1]);
	close(data->pipe_fd);
	lsh_launch(data, pipe);
	exit(0);
}
