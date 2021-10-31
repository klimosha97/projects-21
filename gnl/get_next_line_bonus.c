/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:07:28 by                   #+#    #+#             */
/*   Updated: 2021/10/31 13:07:45 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*read_fd(int fd, char **remain_str)
{
	char	*buf;
	ssize_t	count;

	buf = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	count = 1;
	while (!ft_strchr(remain_str[fd], '\n') && count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[count] = '\0';
		remain_str[fd] = ft_strjoin(remain_str[fd], buf);
	}
	free(buf);
	return (remain_str[fd]);
}

char	*get_remain(char **str, int fd)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[fd][i] != '\n' && str[fd][i] != '\0')
		i++;
	if (str[fd][i] == '\0')
	{
		free(str[fd]);
		return (NULL);
	}
	res = (char *) malloc(sizeof(char) * ft_strlen(&str[fd][i]));
	if (!res)
	{
		free(str[fd]);
		return (NULL);
	}
	while (str[fd][++i] != '\0')
		res[j++] = str[fd][i];
	res[j] = '\0';
	free(str[fd]);
	return (res);
}

char	*get_string(char **remain_str, int fd)
{
	int		i;
	char	*res;

	i = 0;
	if (remain_str[fd][i] == '\0')
		return (NULL);
	while (remain_str[fd][i] != '\n' && remain_str[fd][i] != '\0')
		i++;
	if (remain_str[fd][i] == '\n')
		res = (char *) malloc(sizeof(char) * i + 2);
	else
		res = (char *) malloc(sizeof(char) * i + 1);
	i = 0;
	while (remain_str[fd][i] != '\n' && remain_str[fd][i] != '\0')
	{
		res[i] = remain_str[fd][i];
		i++;
	}
	if (remain_str[fd][i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*remain_str[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remain_str[fd] = read_fd(fd, remain_str);
	if (!remain_str[fd])
		return (NULL);
	str = get_string(remain_str, fd);
	remain_str[fd] = get_remain(remain_str, fd);
	return (str);
}
