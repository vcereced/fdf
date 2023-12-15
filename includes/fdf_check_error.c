/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:54:48 by vcereced          #+#    #+#             */
/*   Updated: 2023/04/05 13:56:13 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	msg_error(char *str)
{
	perror(str);
	exit(errno);
}

static int	check_arg(char *str)
{
	if (ft_strnstr(str, ".fdf", ft_strlen(str)))
		return (1);
	return (0);
}

void	free_all(t_point *p)
{
	ft_matrizintfree(p->data->arr_heigth, p->weigth);
	free(p->addr);
	if (p->color == 1)
		ft_matrizintfree(p->data->arr_color, p->weigth);
}

void	error_free_all(t_point *p, char *str)
{
	free_all(p);
	msg_error(str);
}

void	check_error(int argc, char ***argv)
{
	int	fd;

	if (argc != 2)
		msg_error("Nº arg wrong");
	if (!check_arg((*argv)[1]))
		msg_error("name of file wrong");
	fd = open((*argv)[1], R_OK);
	if (fd == -1)
		msg_error("");
	close(fd);
}
