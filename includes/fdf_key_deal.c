/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_deal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:33:35 by vcereced          #+#    #+#             */
/*   Updated: 2023/04/05 13:55:22 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void check_leaks(void)
{
	system("leaks fdf");
}
*/
static void	moves(int key, t_point *p)
{
	if (key == 86)
		p->start_x -= 50;
	else if (key == 88)
		p->start_x += 50;
	else if (key == 91)
		p->start_y -= 50;
	if (key == 84)
		p->start_y += 50;
}

int	finish_program(t_point *p)
{
	mlx_destroy_window(p->mlx_ptr, p->win_ptr);
	free_all(p);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_deal(int key, t_point *p)
{
	ft_printf("%d\n", key);
	if (key == 53)
		finish_program(p);
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	mlx_destroy_image(p->mlx_ptr, p->img_ptr);
	p->img_ptr = mlx_new_image(p->mlx_ptr, 1920, 1080);
	moves(key, p);
	draw_lines(*p);
	draw_columns(*p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	return (0);
}
