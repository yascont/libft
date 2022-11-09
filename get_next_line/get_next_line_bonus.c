/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabidi <yabidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:31:37 by yabidi            #+#    #+#             */
/*   Updated: 2022/10/30 04:50:50 by yabidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!str)
		return (NULL);
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

static	char	*read_till_line(int fd, char *whole_line)
{
	int		i;
	char	*buffer;
	char	*fre;

	i = 1;
	if (!whole_line)
		whole_line = ft_strdup("");
	while (!ft_strchr(whole_line, '\n') && i)
	{
		buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
			return (NULL);
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (free(whole_line), free(buffer), NULL);
		fre = whole_line;
		whole_line = ft_strjoin(whole_line, buffer);
		free(fre);
		free(buffer);
	}
	return (whole_line);
}

static	char	*just_line(char *whole_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!whole_line[i])
		return (NULL);
	while (whole_line[i] && whole_line[i] != '\n')
	i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (whole_line[i] && whole_line[i] != '\n')
	{
		str[i] = whole_line[i];
		i++;
	}
	if (whole_line[i] == '\n')
	{
		str[i] = whole_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static	char	*fix_line(char *whole_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (whole_line[i] && whole_line[i] != '\n')
		i++;
	if (!whole_line[i])
	{
		free(whole_line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(whole_line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (whole_line[i])
		str[j++] = whole_line[i++];
	str[j] = '\0';
	free(whole_line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*whole_line[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	whole_line[fd] = read_till_line(fd, whole_line[fd]);
	if (!whole_line[fd])
		return (NULL);
	line = just_line(whole_line[fd]);
	whole_line[fd] = fix_line(whole_line[fd]);
	return (line);
}
