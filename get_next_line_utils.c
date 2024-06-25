/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeper   				    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:08:37 by ezeper            #+#    #+#             */
/*   Updated: 2024/06/25 02:53:16 by ezeper	      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s = (const char *)src;
	const char	*lasts = s + (len - 1);
	char		*lastd;

	d = (char *)dst;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		r;
	int		src;
	char	*res;

	r = 0;
	src = 0;
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == 0)
		return (NULL);
	while (s1[src] != '\0')
		res[r++] = s1[src++];
	src = 0;
	while (s2[src] != '\0')
		res[r++] = s2[src++];
	res[r] = '\0';
	return (res);
}

char	*ft_strdup(char *s1)
{
	char	*dst;
	size_t	s;

	s = ft_strlen(s1) + 1;
	dst = malloc(s);
	if (dst == NULL)
	{
		return (NULL);
	}
	if (s1 != NULL)
	{
		ft_memmove(dst, s1, s);
	}
	return (dst);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(start + s);
	sub = (char *)malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	i = -1;
	while (++i < len)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}
