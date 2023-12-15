# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcereced <vcereced@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 20:58:09 by vcereced          #+#    #+#              #
#    Updated: 2023/03/27 22:01:36 by vcereced         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

NAMEBONUS = fdfbonus

SRC = $(wildcard includes/*c)

SRCBONUS = $(wildcard bonus/*c)

CFLAGS = -Wall -Werror -Wextra

OBJT = $(SRC:.c=.o)

OBJTBONUS = $(SRCBONUS:.c=.o)

CC = gcc

LIBFT = ./libft/libft.a

MINILIBX = ./minilibx_macos/libmlx.a 

FRAME = -framework Appkit

FRAME2 = -framework OpenGl

all: $(NAME)

$(NAME): $(OBJT) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJT) $(LIBFT) $(MINILIBX) $(FRAME) $(FRAME2) -o $(NAME)

$(MINILIBX):
	make -C ./minilibx_macos

$(LIBFT):
	make -C ./libft

bonus: $(OBJTBONUS) $(MINILIBX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJTBONUS) $(LIBFT) $(MINILIBX) $(FRAME) $(FRAME2) -o $(NAMEBONUS)
		
clean:
	rm -f $(OBJT)

fclean: clean
	rm -f $(NAMEBONUS)
	rm -f $(NAME)
	rm -f $(OBJTNAME)
	rm -f $(OBJTBONUS)
	make fclean -C ./libft
	make clean -C ./minilibx_macos

re: fclean all

run: all
	./fdf ./test_maps/42.fdf
	
runbonus: bonus
	./fdfbonus ./test_maps/42.fdf

.PHONY: all clean fclean re
