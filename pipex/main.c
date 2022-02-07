/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:12:13 by mcorneli          #+#    #+#             */
/*   Updated: 2022/02/02 15:12:18 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	helper(int fd[2], int file, int cmd)
{
	if (cmd == 1)
	{
		close(fd[0]);
		dup2(file, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(file, STDOUT_FILENO);
		close(fd[0]);
	}
}

int	first_cmd(int fd1[2], int file1, char **envp, char *pname)
{
	char	**programm_args;
	char	*path;
	int		pid1;

	pid1 = fork();
	if (pid1 < 0)
		ft_error("pid1 fork error", 0);
	if (pid1 == 0)
	{
		helper(fd1, file1, 1);
		programm_args = ft_split(pname, ' ');
		if (programm_args == NULL)
			ft_error("Error: ft_split error\n", 1);
		path = find_path(envp, programm_args[0]);
		if (path == NULL)
		{
			clear_path_array(programm_args);
			ft_error("Error cmd1", 0);
		}
		execve(path, programm_args, envp);
		free(path);
		clear_path_array(programm_args);
		ft_error("Execve error", 0);
	}
	return (pid1);
}

int	second_cmd(int fd1[2], int file2, char **envp, char *pname)
{
	char	**programm_args;
	char	*path;
	int		pid2;

	pid2 = fork();
	if (pid2 < 0)
		ft_error("pid2 fork error", 0);
	if (pid2 == 0)
	{
		helper(fd1, file2, 2);
		programm_args = ft_split(pname, ' ');
		if (programm_args == NULL)
			ft_error("Error: ft_split error\n", 1);
		path = find_path(envp, programm_args[0]);
		if (path == NULL)
		{
			clear_path_array(programm_args);
			ft_error("Error cmd2", 0);
		}
		execve(path, programm_args, envp);
		free(path);
		clear_path_array(programm_args);
		ft_error("Execve error", 0);
	}
	return (pid2);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd1[2];
	int	pid1;
	int	pid2;
	int	file1;
	int	file2;

	if (argc != 5)
		ft_error("Error: problem with arguments\n", 1);
	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		ft_error("Error file 1", 0);
	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file2 == -1)
		ft_error("Error file 2", 0);
	if (pipe(fd1) == -1)
		ft_error("Pipe error", 0);
	pid1 = first_cmd(fd1, file1, envp, argv[2]);
	pid2 = second_cmd(fd1, file2, envp, argv[3]);
	ft_close_all(fd1, file1, file2);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
