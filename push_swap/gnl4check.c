/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl4check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:51:01 by                   #+#    #+#             */
/*   Updated: 2022/01/20 13:51:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pushswap.h"

char	*ft_strjoin1(char *line, char c)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
		i++;
	tmp = (char *)malloc(sizeof (char) * (i + 2));
	if (!tmp)
		exit(1);
	while (j < i)
	{
		tmp[j] = line[j];
		j++;
	}
	tmp[j] = c;
	tmp[j + 1] = 0;
	free(line);
	return (tmp);
}

int	get_next_line(char **line)
{
	char	*tmp;
	char	c;

	tmp = NULL;
	tmp = (char *)malloc(sizeof (char ));
	if (!tmp)
		exit(1);
	tmp[0] = '\0';
	while (read(0, &c, 1) != 0 && c != '\n')
		tmp = ft_strjoin1(tmp, c);
	*line = tmp;
	free(tmp);
	return (c == '\n');
}

void	ft_write_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}
