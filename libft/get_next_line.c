/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:01:37 by hel-kame          #+#    #+#             */
/*   Updated: 2023/01/02 23:33:12 by hel-kame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(char *buffer, int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*str;
	int		to_read;

	if (buffer[0])
		str = ft_strdup_gnl(buffer);
	else
		str = NULL;
	while (!str || !ft_get_nl_gnl(str))
	{
		to_read = read(fd, tmp, BUFFER_SIZE);
		if (to_read < 0)
		{
			free(str);
			return (NULL);
		}
		if (!to_read)
			break ;
		tmp[to_read] = '\0';
		str = ft_strjoin_gnl(tmp, str);
	}
	return (str);
}

char	*get_line(char *buffer, char *line)
{
	int		i;
	char	*s;
	int		j;

	i = 0;
	if (!line || line[i] == '\0')
		return (NULL);
	s = malloc(sizeof(char) * (ft_strlen_gnl(line) + 1));
	if (!s)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
	{
		s[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		s[i++] = '\n';
	s[i] = '\0';
	j = 0;
	while (line[i])
		buffer[j++] = line[i++];
	buffer[j] = 0;
	free(line);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*s;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	s = read_file(buffer, fd);
	if (!s)
		return (NULL);
	s = get_line(buffer, s);
	return (s);
}
