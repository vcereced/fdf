/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:33:47 by vcereced          #+#    #+#             */
/*   Updated: 2023/04/04 21:22:15 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_point *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
	{
		dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	draw_column(t_point p)
{
	set_params(&p, 'c');
	p.step = 0;
	while ((int)(p.x2 - p.x1) || (int)(p.y2 - p.y1))
	{
		isomeric(&p);
		my_mlx_pixel_put(&p, p.isox, p.isoy, set_color(&p));
		p.x1 += p.dx;
		p.y1 += p.dy;
		p.step++;
	}
}

static void	draw_line(t_point p)
{
	set_params(&p, 'l');
	p.step = 0;
	while ((int)(p.x2 - p.x1) || (int)(p.y2 - p.y1))
	{
		isomeric(&p);
		my_mlx_pixel_put(&p, p.isox, p.isoy, set_color(&p));
		p.x1 += p.dx;
		p.y1 += p.dy;
		p.step++;
	}
}

void	draw_lines(t_point p)
{
	p.y1 = p.start_y;
	p.y2 = p.start_y;
	p.row = 0;
	while (p.row < p.weigth)
	{
		p.x1 = p.start_x;
		p.x2 = p.start_x + p.scale;
		p.column = 0;
		while (p.column < (p.length - 1))
		{
			draw_line(p);
			p.x1 += p.scale;
			p.x2 += p.scale;
			p.column++;
		}
		p.y1 += p.scale;
		p.y2 += p.scale;
		p.row++;
		ft_printf("loading line %d / %d\n", p.row, p.weigth);
	}
}

void	draw_columns(t_point p)
{
	p.y1 = p.start_y;
	p.y2 = p.start_y + p.scale;
	p.row = 0;
	while (p.row < (p.weigth - 1))
	{
		p.x1 = p.start_x;
		p.x2 = p.start_x;
		p.column = 0;
		while (p.column < p.length)
		{
			draw_column(p);
			p.x1 += p.scale;
			p.x2 += p.scale;
			p.column++;
		}
		p.y1 += p.scale;
		p.y2 += p.scale;
		p.row++;
		ft_printf("loading column %d / %d\n", p.row, p.weigth);
	}
}
