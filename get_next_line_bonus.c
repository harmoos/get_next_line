/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:24:04 by nleoni            #+#    #+#             */
/*   Updated: 2024/01/26 17:15:58 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*set_line(char *line_dest)
{
	char	*let_c;
	ssize_t	i;

	i = 0;
	while (line_dest[i] != '\n' && line_dest[i] != '\0')
		i++;
	if (line_dest[i] == 0 || line_dest[1] == 0)
		return (NULL);
	let_c = ft_substr(line_dest, i + 1, ft_strlen(line_dest) - i);
	if (*let_c == 0)
	{
		free(let_c);
		let_c = NULL;
	}
	line_dest[i + 1] = 0;
	return (let_c);
}

char	*temp_dest(int fd, char **let_c, char *bf)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, bf, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(*let_c);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		bf[b_read] = '\0';
		if (!*let_c)
			*let_c = ft_strdup("");
		tmp = *let_c;
		*let_c = ft_strjoin(tmp, bf);
		free(tmp);
		if (*let_c == NULL)
			return (NULL);
		tmp = NULL;
		if (ft_strchr(bf, '\n'))
			break ;
	}
	return (*let_c);
}

char	*get_next_line(int fd)
{
	static char		*let_c[MAX_FD + 1];
	char			*line;
	char			*bf;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	bf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (bf == NULL)
		return (NULL);
	line = temp_dest(fd, &let_c[fd], bf);
	free(bf);
	bf = NULL;
	if (!line || *line == '\0')
	{
		return (NULL);
	}
	let_c[fd] = set_line(line);
	return (line);
}
