/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrenzett <lrenzett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:13:18 by lrenzett          #+#    #+#             */
/*   Updated: 2023/10/11 00:06:46 by lrenzett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*strm;

	if (!str)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	strm = (char *)malloc(ft_strlen(str) + ft_strlen(buff) + 1);
	if (strm == NULL)
		return (NULL);
	i = -1;
	j = 0;
	while (str[++i] != '\0')
		strm[i] = str[i];
	while (buff[j] != '\0')
		strm[i++] = buff[j++];
	strm[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (strm);
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_join(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*strm;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	strm = (char *)malloc(i + 2);
	if (!strm)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		strm[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		strm[i] = str[i];
		i++;
	}
	strm[i] = '\0';
	return (strm);
}

char	*ft_new_str(char *str)
{
	int		i;
	int		j;
	char	*strm;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	strm = (char *)malloc(ft_strlen(str) - i + 1);
	if (!strm)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		strm[j++] = str[i++];
	strm[j] = '\0';
	free(str);
	return (strm);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_new_str (str);
	return (line);
}
