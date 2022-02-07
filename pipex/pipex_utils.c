/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorneli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:13:05 by mcorneli          #+#    #+#             */
/*   Updated: 2022/02/02 15:13:07 by mcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, int is_my_error)
{
	if (is_my_error)
		ft_putstr_fd(str, 2);
	else
		perror(str);
	exit(EXIT_FAILURE);
}

void	clear_path_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_close_all(int fd1[2], int file1, int file2)
{
	if (fd1)
	{
		close(fd1[0]);
		close(fd1[1]);
	}
	close(file1);
	close(file2);
}

static char	*find_path_helper(char **path_arr, char *name)
{
	int		j;
	char	*path;

	j = 0;
	while (path_arr[j])
	{
		path_arr[j] = ft_strjoin(path_arr[j], name, 1);
		if (access(path_arr[j], F_OK) == 0)
		{
			path = ft_strdup(path_arr[j]);
			clear_path_array(path_arr);
			return (path);
		}
		j++;
	}
	clear_path_array(path_arr);
	return (NULL);
}

char	*find_path(char **env, char *name)
{
	int		j;
	char	*path;
	char	**path_arr;

	j = 0;
	while (env[j] && ft_strncmp(env[j], "PATH", 4) != 0)
		j++;
	if (!env[j])
		ft_error("Error: did not find PATH in env\n", 1);
	path = ft_substr(env[j], 5, ft_strlen(&env[j][5]));
	path_arr = ft_split(path, ':');
	free(path);
	path = NULL;
	path = find_path_helper(path_arr, name);
	if (path)
		return (path);
	return (NULL);
}
