/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:36:41 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/17 21:00:42 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_strrchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s == 0)
	{
		i = get_strlen((char *)s);
		return (&s[i]);
	}
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*get_clean(char *bufferstatic, char *bufferstatic_cleaned, int i)
{
	int	j;

	j = 0;
	while (bufferstatic[i + j])
	{
		bufferstatic_cleaned[j] = bufferstatic[i + j];
		j++;
	}
	bufferstatic_cleaned[j] = '\0';
	free(bufferstatic);
	return (bufferstatic_cleaned);
}

char	*get_joint(const char *buffer, char *bufferstatic, char *str_jointed)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (bufferstatic && bufferstatic[i])
	{
		str_jointed[i] = bufferstatic[i];
		i++;
	}
	while (buffer && buffer[j])
	{
		str_jointed[i + j] = buffer[j];
		j++;
	}
	str_jointed[i + j] = '\0';
	free(bufferstatic);
	return (str_jointed);
}
