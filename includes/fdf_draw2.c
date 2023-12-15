/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 22:45:23 by vcereced          #+#    #+#             */
/*   Updated: 2023/12/15 18:43:09 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_bresenham(t_point *p)
{
	p->dx = p->x2 - p->x1;
	p->dy = p->y2 - p->y1;
	if ((abs)((int)p->dx) >= (abs)((int)p->dy))
		p->steps = p->dx;
	else
		p->steps = (abs)((int)p->dy);
	p->dx = p->dx / p->steps;
	p->dy = p->dy / p->steps;
}

static void	set_heigth(t_point *p, char c)
{
	p->z1 = p->data->arr_heigth[p->row][p->column];
	if (c == 'l')
		p->z2 = p->data->arr_heigth[p->row][(p->column) + 1];
	if (c == 'c')
		p->z2 = p->data->arr_heigth[(p->row) + 1][p->column];
	p->x1 -= (p->z1);
	p->y1 -= (p->z1);
	p->x2 -= (p->z2);
	p->y2 -= (p->z2);
}

void	isomeric(t_point *p)
{
		p->isox = (p->x1 - p->y1) * cos(0.8);
		p->isoy = (p->x1 + p->y1) * sin(0.8);
}

void	set_params(t_point *p, char c)
{
	set_heigth(p, c);
	my_bresenham(p);
}
