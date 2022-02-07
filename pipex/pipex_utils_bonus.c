/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:13:25 by mcorneli          #+#    #+#             */
/*   Updated: 2022/02/02 15:13:26 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**pipe_init(int **pipes, int size)
{
	int	i;

	pipes = NULL;
	pipes = (int **) malloc(sizeof(int *) * size);
	if (!pipes)
		ft_error("Error malloc **pipe", 0);
	i = 0;
	while (i < size)
	{
		pipes[i] = (int *)malloc(sizeof(int ) * 2);
		if (!pipes[i])
		{
			clear_path_array_int(pipes, size);
			ft_error("Error malloc pipe", 0);
		}
		if (pipe(pipes[i]) == -1)
		{
			clear_path_array_int(pipes, size);
			ft_error("Error pipe", 0);
		}
		i++;
	}
	return (pipes);
}

void	clear_path_array_int(int **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(array[i++]);
	free(array);
}

void	close_pipes(int **pipes, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
}

void	exec_cmd(char **envp, char *cmd, int *fid)
{
	char	**programm_args;
	char	*path;

	free(fid);
	fid = NULL;
	programm_args = ft_split(cmd, ' ');
	if (programm_args == NULL)
		ft_error("Error: ft_split error\n", 1);
	path = find_path(envp, programm_args[0]);
	if (path == NULL)
	{
		write(2, "Error: did not find path: ",
			ft_strlen("Error: did not find path: "));
		write(2, programm_args[0], ft_strlen(programm_args[0]));
		clear_path_array(programm_args);
		ft_error("\n", 1);
	}
	execve(path, programm_args, envp);
	free(path);
	clear_path_array(programm_args);
	ft_error("Execve error", 0);
}
