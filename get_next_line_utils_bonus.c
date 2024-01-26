/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleoni <nleoni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:24:20 by nleoni            #+#    #+#             */
/*   Updated: 2024/01/26 13:02:10 by nleoni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_empty_str(void)
{
	char	*empty_str;

	empty_str = (char *)malloc(1);
	if (empty_str == NULL)
		return (NULL);
	empty_str[0] = '\0';
	return (empty_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	size_t			i;
	unsigned int	a;

	if (s == NULL)
		return (NULL);
	i = 0;
	a = ft_strlen((char *)s);
	if (start > (a - 1))
		return (ft_empty_str());
	if (len > a - start)
		len = a - start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL || ((a - start) < len))
		return (NULL);
	while (s[start] && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	int		b;
	char	*str;

	a = ft_strlen((char *)s1);
	b = ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (a + b + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		size;
	char	*ptr;
	int		i;

	size = ft_strlen(s);
	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
