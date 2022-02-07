/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:12:31 by mcorneli          #+#    #+#             */
/*   Updated: 2022/02/02 15:12:34 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dupnclose_pipes(int **pipes, int i, int size_pipe, int file[2])
{
	if (i == 0)
	{
		dup2(file[0], STDIN_FILENO);
		dup2(pipes[i][1], STDOUT_FILENO);
	}
	else if (i == size_pipe)
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		dup2(file[1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipes[i - 1][0], STDIN_FILENO);
		dup2(pipes[i][1], STDOUT_FILENO);
	}
	close(file[0]);
	close(file[1]);
	close_pipes(pipes, size_pipe);
}

void	start_exec(int file[2], char **argv, char **envp, int cmd)
{
	int	i;
	int	*fid;
	int	**pipes;

	i = 0;
	pipes = pipe_init(pipes, cmd - 1);
	fid = (int *) malloc(sizeof(int ) * cmd);
	if (!fid)
		ft_error("Error", 0);
	while (i < cmd)
	{
		fid[i] = fork();
		if (fid[i] < 0)
			ft_error("Error fork", 0);
		if (fid[i] == 0)
		{
			dupnclose_pipes(pipes, i, cmd - 1, file);
			clear_path_array_int(pipes, cmd - 1);
			exec_cmd(envp, argv[i + 2], fid);
		}
		i++;
	}
	close_pipes(pipes, cmd - 1);
	free(fid);
	clear_path_array_int(pipes, cmd - 1);
}

int	main(int argc, char **argv, char **envp)
{
	int			file[2];
	int			i;

	if (argc < 5)
		ft_error("Error: not enough arguments\n", 1);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		main_here_doc(argc, argv, envp);
	file[0] = open(argv[1], O_RDONLY);
	if (file[0] == -1)
		ft_error("Error file 1", 0);
	file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file[1] == -1)
		ft_error("Error file 2", 0);
	start_exec(file, argv, envp, argc - 3);
	i = 0;
	ft_close_all(NULL, file[0], file[1]);
	while (i++ < argc - 3)
		wait(NULL);
	return (0);
}
