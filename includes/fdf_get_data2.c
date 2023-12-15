/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 00:07:52 by vcereced          #+#    #+#             */
/*   Updated: 2023/03/26 20:28:38 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*fill_nums(int *row, char ***matriz)
{
	int	length;
	int	i;

	length = ft_matrizlen(*matriz);
	i = 0;
	while (i < length)
	{
		row[i] = ft_atoi((*matriz)[i]);
		i++;
	}
	return (row);
}

static int	*fill_colors(int *row, char ***matriz)
{
	int	length;
	int	i;

	length = ft_matrizlen(*matriz);
	i = 0;
	while (i < length)
	{
		if (ft_strchr((*matriz)[i], ',') == NULL)
			row[i] = 0xC0C0C0;
		else
			row[i] = ft_atoi_base((ft_strchr((*matriz)[i], ',') + 1), 16);
		i++;
	}
	return (row);
}

static void	fill_with_numbers(char ***arr, t_point *p, int row)
{
	p->data->arr_heigth[row] = (int *)malloc(sizeof(int) * (*p).length);
	if (!p->data->arr_heigth)
		error_free_all(p, "error alocation memory");
	p->data->arr_heigth[row] = fill_nums(p->data->arr_heigth[row], arr);
}

static void	fill_with_colors(char ***arr, t_point *p, int row)
{
	p->data->arr_color[row] = (int *)malloc(sizeof(int) * (*p).length);
	if (!p->data->arr_color)
		error_free_all(p, "error alocation memory");
	p->data->arr_color[row] = fill_colors(p->data->arr_color[row], arr);
}

void	get_heigth_color(t_point *p, int fd)
{
	char	**matriz;
	char	*line;

	p->data->arr_color = NULL;
	p->data->arr_heigth = (int **)malloc(sizeof(int *) * (*p).weigth);
	if (!p->data->arr_heigth)
		error_free_all(p, "error alocation memory");
	if ((*p).color == 1)
	{
		p->data->arr_color = (int **)malloc(sizeof(int *) * (*p).weigth);
		if (!p->data->arr_color)
			error_free_all(p, "error alocation memory");
	}
	p->row = 0;
	while (p->row < (*p).weigth)
	{
		line = get_next_line(fd);
		matriz = ft_split(line, ' ');
		fill_with_numbers(&matriz, p, p->row);
		if ((*p).color == 1)
			fill_with_colors(&matriz, p, p->row);
		free(line);
		ft_matrizcharfree(matriz, ft_matrizlen(matriz));
		p->row++;
	}
}
