/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:12:30 by vcereced          #+#    #+#             */
/*   Updated: 2023/10/24 18:11:39 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_point(t_point *p)
{
	(*p).scale = 20;
	(*p).flag = 0;
	p->start_x = 650;
	p->start_y = -650;
}

int	main(int argc, char **argv)
{
	t_point	p;
	t_data	data;

	p.data = &data;
	check_error(argc, &argv);
	get_data(&p, &argv);  
	init_point(&p);
	p.mlx_ptr = mlx_init();
	p.win_ptr = mlx_new_window(p.mlx_ptr, 1920, 1080, "My Window");
	p.img_ptr = mlx_new_image(p.mlx_ptr, 1920, 1080);
	p.addr = mlx_get_data_addr(p.img_ptr, &p.bits_per_pixel, \
	&p.line_length, &p.endian);
	draw_lines(p);
	draw_columns(p);
	mlx_put_image_to_window(p.mlx_ptr, p.win_ptr, p.img_ptr, 0, 0);
	mlx_key_hook(p.win_ptr, key_deal, &p);
	mlx_hook(p.win_ptr, 17, 0, finish_program, &p);
	mlx_loop(p.mlx_ptr);
	return (0);
}
