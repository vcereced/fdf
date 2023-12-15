/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_data_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:45:26 by vcereced          #+#    #+#             */
/*   Updated: 2023/04/04 21:22:25 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	is_color(t_point	*p, char ***argv)
{
	int		fd;
	char	*line;
	int		n;

	n = 0;
	fd = open((*argv)[1], O_RDONLY);
	line = get_next_line(fd);
	while (line && n == 0)
	{
		if (ft_strchr(line, ','))
			n = 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	(*p).color = n;
}

static void	get_size(t_point *p, char ***argv)
{
	int		weigth;
	int		fd;
	char	**matriz;
	char	*control_read;

	fd = open((*argv)[1], O_RDONLY);
	weigth = 0;
	control_read = get_next_line(fd);
	matriz = ft_split(control_read, ' ');
	while (control_read != NULL)
	{
		if (control_read)
			weigth++;
		free(control_read);
		control_read = get_next_line(fd);
	}
	free(control_read);
	(*p).length = ft_matrizlen(matriz);
	(*p).weigth = weigth;
	ft_matrizcharfree(matriz, ft_matrizlen(matriz));
	close(fd);
}

void	get_data(t_point *p, char ***argv)
{
	int		fd;

	get_size(p, argv);
	is_color(p, argv);
	fd = open((*argv)[1], O_RDONLY);
	get_heigth_color(p, fd);
	close(fd);
}
