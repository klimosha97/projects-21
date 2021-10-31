/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:07:21 by                   #+#    #+#             */
/*   Updated: 2021/10/31 13:07:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_fd(int fd, char *remain_str)
{
	char	*buf;
	ssize_t	count;

	buf = (char *) malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buf)
		return (NULL);
	count = 1;
	while (!ft_strchr(remain_str, '\n') && count != 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[count] = '\0';
		remain_str = ft_strjoin(remain_str, buf);
	}
	free(buf);
	return (remain_str);
}

char	*get_remain(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	res = (char *) malloc(sizeof(char) * ft_strlen(&str[i]));
	if (!res)
	{
		free(str);
		return (NULL);
	}
	while (str[++i] != '\0')
		res[j++] = str[i];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*get_string(char *remain_str)
{
	int		i;
	char	*res;

	i = 0;
	if (remain_str[i] == '\0')
		return (NULL);
	while (remain_str[i] != '\n' && remain_str[i] != '\0')
		i++;
	if (remain_str[i] == '\n')
		res = (char *) malloc(sizeof(char) * i + 2);
	else
		res = (char *) malloc(sizeof(char) * i + 1);
	i = 0;
	while (remain_str[i] != '\n' && remain_str[i] != '\0')
	{
		res[i] = remain_str[i];
		i++;
	}
	if (remain_str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*remain_str;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	remain_str = read_fd(fd, remain_str);
	if (!remain_str)
		return (NULL);
	str = get_string(remain_str);
	remain_str = get_remain(remain_str);
	return (str);
}
