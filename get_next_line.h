/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:19:56 by nleoni            #+#    #+#             */
/*   Updated: 2024/01/07 21:08:58 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H
#  ifndef	BUFFER_SIZE
#	define	BUFFER_SIZE 42
# endif

# include	<fcntl.h>
# include	<stdlib.h>
#include	<unistd.h>


char	*get_next_line(int fd);
char	*set_line(char *line_dest);
char	*temp_dest(int fd, char *let_c, char *bf);


char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_empty_str(void);
size_t	ft_strlen(const char *s);

#endif
