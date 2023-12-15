/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_deal_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 21:21:50 by vcereced          #+#    #+#             */
/*   Updated: 2023/04/05 13:55:17 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
/*
static void check_leaks(void)
{
	system("leaks fdfbonus");
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

void	proyection(int key, t_point *p)
{
	if (key == 19)
		p->mode = 1;
	else if (key == 20)
		p->mode = 2;
	else if (key == 67)
		p->scale -= 2;
	else if (key == 75)
		p->scale += 2;
	else if (key == 78)
		p->zoom -= 0.1;
	if (key == 69)
		p->zoom += 0.1;
}

void	up_down(int key, t_point *p)
{
	if (key == 126)
		up_down_matrix_heigth(p, 5);
	if (key == 125)
		up_down_matrix_heigth(p, -5);
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
	proyection(key, p);
	up_down(key, p);
	draw_lines(*p);
	draw_columns(*p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img_ptr, 0, 0);
	return (0);
}
