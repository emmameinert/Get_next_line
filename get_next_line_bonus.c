/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emeinert <emeinert@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:04:15 by emeinert          #+#    #+#             */
/*   Updated: 2022/11/28 12:00:54 by emeinert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_search_stash(char *stash)
{
	char	*cpy;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	cpy = (char *) malloc (sizeof(char) * (i + 2));
	if (!cpy)
		return (NULL);
	j = 0;
	while (j <= i && stash)
	{
		cpy[j] = stash[j];
		j++;
	}
	cpy[j] = '\0';
	if (cpy[0] == '\0')
	{
		free (cpy);
		return (NULL);
	}
	return (cpy);
}

static char	*ft_empty_stash(char *stash)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*empty_stash;

	len = ft_strlen(stash);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	empty_stash = (char *)malloc (sizeof(char) * ((len - i) + 2));
	if (!empty_stash)
		return (NULL);
	j = 0;
	while (stash[i] != '\0')
		empty_stash[j++] = stash[i++];
	empty_stash[j] = '\0';
	free (stash);
	if (empty_stash[0] == '\0')
	{
		free (empty_stash);
		return (NULL);
	}
	return (empty_stash);
}

static char	*ft_read_input(int fd, char *stash)
{
	char	*buf;
	int		bytes;

	buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buf[bytes] = '\0';
		if (!stash)
			stash = ft_make_stash();
		stash = ft_call_join(stash, buf);
		if (!stash)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free (buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*return_line;
	static char	*stash[1000];

	if (BUFFER_SIZE < 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	stash[fd] = ft_read_input(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	return_line = ft_search_stash(stash[fd]);
	stash[fd] = ft_empty_stash(stash[fd]);
	return (return_line);
}
