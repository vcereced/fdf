/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_up_matrix_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:00:52 by vcereced          #+#    #+#             */
/*   Updated: 2023/04/04 21:23:02 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	get_max_matrix(t_point *p)
{
	int	i;
	int	j;
	int	max_min;

	max_min = 0;
	i = 0;
	while (i < p->weigth)
	{
		j = 0;
		while (j < p->length)
		{
			if (max_min < p->data->arr_heigth[i][j] && p->flag == 0)
				max_min = p->data->arr_heigth[i][j];
			if (max_min > p->data->arr_heigth[i][j] && p->flag == 1)
				max_min = p->data->arr_heigth[i][j];
			j++;
		}
		i++;
	}
	return (max_min);
}

static int	c(int p, int n)
{
	if (p <= 6 && p >= -6)
	{
		if (n > 0)
		{
			p = 7;
		}
		else
		{
			p = -7;
		}
	}
	else
		p += n;
	return (p);
}

static void	condition(t_point *p, int max, int *i, int n)
{
	if (p->data->arr_heigth[i[0]][i[1]] == max)
	{
		p->data->arr_heigth[i[0]][i[1]] = \
		c(p->data->arr_heigth[i[0]][i[1]], n);
		if (p->data->arr_heigth[i[0]][i[1]] > 0)
			p->flag = 0;
		else
			p->flag = 1;
	}
}

static void	change_matrix(t_point *p, int max, int n)
{
	int	i[2];

	i[0] = 0;
	while (i[0] < p->weigth)
	{
		i[1] = 0;
		while (i[1] < p->length)
		{
			condition(p, max, i, n);
			(i[1])++;
		}
		(i[0])++;
	}
}

void	up_down_matrix_heigth(t_point *p, int n)
{
	int	max;

	max = get_max_matrix(p);
	change_matrix(p, max, n);
}
