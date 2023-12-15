/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:45:47 by vcereced          #+#    #+#             */
/*   Updated: 2023/10/24 18:11:50 by vcereced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "errno.h"

typedef struct s_data
{
	int		**arr_heigth;
	int		**arr_color;
}				t_data;

typedef struct s_point
{
	float	dx;
	float	dy;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	z1;
	float	z2;
	int		isox;
	int		isoy;
	int		start_x;
	int		start_y;
	int		start_z;
	int		scale;
	int		heigth;
	int		flag;
	int		color;
	int		row;
	int		column;
	int		step;
	int		steps;
	int		length;
	int		weigth;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_data	*data;
}				t_point;

void	get_data(t_point *p, char ***argv);
void	draw_lines(t_point p);
void	draw_columns(t_point p);
int		set_color(t_point	*p);
void	up_down_matrix_heigth(t_point *p, int n);
int		key_deal(int key, t_point *p);
void	get_heigth_color(t_point *p, int fd);
void	check_error(int argc, char ***argv);
void	free_all(t_point *p);
void	error_free_all(t_point *p, char *str);
void	set_params(t_point *p, char c);
void	isomeric(t_point *p);
void	msg_error(char *str);
int		finish_program(t_point *p);

#endif