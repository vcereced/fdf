/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:35:56 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/27 22:07:02 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*clean_bufferstatic(char *bufferstatic)
{
	char	*bufferstatic_cleaned;
	int		i;

	i = 0;
	if (bufferstatic[i] == '\0')
	{
		free(bufferstatic);
		return (NULL);
	}
	while (bufferstatic[i] && bufferstatic[i] != '\n')
		i++;
	if (bufferstatic[i] == '\n')
		i++;
	bufferstatic_cleaned = (char *)malloc(1 + get_strlen(bufferstatic) - i);
	if (!bufferstatic_cleaned)
		return (NULL);
	bufferstatic_cleaned = get_clean(bufferstatic, bufferstatic_cleaned, i);
	return (bufferstatic_cleaned);
}

static char	*extract_line(char *bufferstatic)
{
	size_t	i;
	char	*line_extracted;

	if (!bufferstatic || !bufferstatic[0])
		return (NULL);
	i = 0;
	while (bufferstatic[i] && bufferstatic[i] != '\n')
		i++;
	if (bufferstatic[i] == '\n')
		i++;
	line_extracted = (char *)malloc(i + 1 * sizeof(char));
	if (!line_extracted)
		return (NULL);
	i = 0;
	while (bufferstatic[i] && bufferstatic[i] != '\n')
	{
		line_extracted[i] = bufferstatic[i];
		i++;
	}
	if (bufferstatic[i] == '\n')
		line_extracted[i++] = '\n';
	line_extracted[i] = '\0';
	return (line_extracted);
}

static char	*joint_to_bufferstatic(const char *buffer, char *bufferstatic)
{
	char	*str_jointed;

	if (!bufferstatic)
	{
		bufferstatic = (char *)malloc(1 * sizeof(char));
		bufferstatic[0] = '\0';
	}
	if (!bufferstatic || !buffer)
		return (NULL);
	str_jointed = (char *) malloc((get_strlen(buffer) +\
	get_strlen(bufferstatic) + 1) * sizeof(char));
	if (!str_jointed)
		return (NULL);
	str_jointed = get_joint(buffer, bufferstatic, str_jointed);
	return (str_jointed);
}

static char	*read_joint_bufferstatic(int fd, char *buffer, char *bufferstatic)
{
	int	control_read;

	control_read = 1;
	while (!(get_strrchr(bufferstatic, '\n')) && control_read != 0)
	{
		control_read = read(fd, buffer, BUFFER_SIZE);
		buffer[control_read] = '\0';
		bufferstatic = joint_to_bufferstatic(buffer, bufferstatic);
	}	
	free(buffer);
	return (bufferstatic);
}
/*LINE = PROTECT FROM INCORRECT FD, BUFFER_SIZE OR NOT WRITE PERMISION.
LINE = FREE BUFFER OF OLD LINES (BUFFER > LINE_EXTRACTED)
LINE = MAKE READ AND CONCAT IN BUFFERSTATIC TILL FIND \n OR EOF 
(BUFFERSTATIC > STR_JOINTED) AFTER SECOND CALL OF GET_NEXT_LINE 
(BUFFERSTATIC > BUFFERSTATIC_CLEANED) | FREE OLD BUFFERSTATIC
LINE = EXTRACT LINE FROM BUFFERSTATIC (BUFFERSTATIC > STR_JOINTED)
LINE = REMOVE LINE OF BUFFERSTATIC (BUFFERSTATIC > BUFFERSTATIC_CLEANED) 
FREE OLD(BUFFERSTATIC)*/

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*bufferstatic[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(bufferstatic[fd]);
		bufferstatic[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bufferstatic[fd] = read_joint_bufferstatic(fd, buffer, bufferstatic[fd]);
	buffer = extract_line(bufferstatic[fd]);
	bufferstatic[fd] = clean_bufferstatic(bufferstatic[fd]);
	return (buffer);
}
