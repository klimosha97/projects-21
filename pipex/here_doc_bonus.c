/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:11:39 by mcorneli          #+#    #+#             */
/*   Updated: 2022/02/02 15:11:44 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_here_doc_last_cmd(char *cmd, char **envp, t_pid_fd fd)
{
	dup2(fd.pids[fd.size_pid - 1][0], 0);
	dup2(fd.file, 1);
	close_pipes(fd.pids, fd.size_pid);
	close(fd.file);
	exec_cmd(envp, cmd, fd.fid);
}

static void	ft_here_doc_cmds(char *cmd, char **envp, t_pid_fd f, int i)
{
	dup2(f.pids[i - 1][0], 0);
	dup2(f.pids[i][1], 1);
	close_pipes(f.pids, f.size_pid);
	close(f.file);
	exec_cmd(envp, cmd, f.fid);
}

static void	ft_here_doc(char **argv, char **envp, t_pid_fd pid)
{
	int		i;

	pid.fid = (int *) malloc(sizeof(int ) * (pid.size_pid + 1));
	if (!pid.fid)
		ft_error("Error malloc\n", 0);
	i = 0;
	while (i < pid.size_pid + 1)
	{
		pid.fid[i] = fork();
		if (pid.fid[i] < 0)
			ft_error("Error fork", 0);
		if (pid.fid[i] == 0)
		{
			if (i == 0)
				ft_gnl_read(argv, pid);
			else if (i == pid.size_pid)
				ft_here_doc_last_cmd(argv[i + 2], envp, pid);
			else
				ft_here_doc_cmds(argv[i + 2], envp, pid, i);
		}
		i++;
	}
}

void	main_here_doc(int argc, char **argv, char **envp)
{
	t_pid_fd	f;
	int			i;

	f.fid = NULL;
	f.file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (f.file == -1)
		ft_error("Error open file", 0);
	f.size_pid = argc - 4;
	f.pids = NULL;
	f.pids = pipe_init(f.pids, f.size_pid);
	ft_here_doc(argv, envp, f);
	close(f.file);
	close_pipes(f.pids, f.size_pid);
	i = 0;
	while (i++ < f.size_pid + 1)
		wait(NULL);
	exit(EXIT_SUCCESS);
}
