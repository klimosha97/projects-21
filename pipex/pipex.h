/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:12:46 by mcorneli          #+#    #+#             */
/*   Updated: 2022/02/02 15:12:48 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_pid_fd
{
	int	**pids;
	int	file;
	int	size_pid;
	int	*fid;
}				t_pid_fd;
void	ft_error(char *str, int is_my_error);
void	ft_close_all(int fd1[2], int file1, int file2);
void	clear_path_array(char **array);
char	*find_path(char **env, char *name);
void	clear_path_array_int(int **array, int size);
void	ft_gnl_read(char **argv, t_pid_fd f);
int		**pipe_init(int **pipes, int size);
void	close_pipes(int **pipes, int size);
void	exec_cmd(char **envp, char *cmd, int *fid);
void	main_here_doc(int argc, char **argv, char **envp);

#endif
