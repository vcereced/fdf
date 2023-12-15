/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_set_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:49:40 by vcereced          #+#    #+#             */
/*   Updated: 2023/04/04 21:22:55 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	range_down(float start)
{
	if (start <= -90)
		return (0xC71585);
	else if (start <= -75)
		return (0xFF00FF);
	else if (start <= -60)
		return (0xDA70D6);
	else if (start <= -45)
		return (0x7B68EE);
	else if (start <= -30)
		return (0x1E90FF);
	else if (start <= -15)
		return (0x6495ED);
	else
		return (0x00BFFF);
}

static int	range_up(float start)
{
	if (start >= 90)
		return (0x8A2BE2);
	else if (start >= 75)
		return (0xBA55D3);
	else if (start >= 60)
		return (0xFFA500);
	else if (start >= 45)
		return (0xDAA520);
	else if (start >= 30)
		return (0xFFD700);
	else if (start >= 15)
		return (0xDEB887);
	else if (start >= 1)
		return (0xDCDCDC);
	else
		return (0x778899);
}

int	set_color(t_point	*p)
{
	float	start;
	float	way;

	if (p->color == 1)
		return (p->data->arr_color[p->row][p->column]);
	start = p->z1;
	way = (float)((float)p->step / (float)p->steps);
	start = start + ((p->z2 - p->z1) * way);
	if (start >= 0)
		return (range_up(start));
	else
		return (range_down(start));
}
