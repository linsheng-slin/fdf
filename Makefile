#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/22 15:03:06 by slin              #+#    #+#              #
#    Updated: 2018/03/27 11:41:42 by slin             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fdf

SRC		= fdf.c key.c start.c draw.c

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		@norminette draw.c fdf.c key.c start.c fdf.h
		@$(CC) $(CFLAGS) -o fdf -I minilibx_macos/mlx.h $(SRC) -L. libft/libft.a -L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit
		@echo "fdf created"

%.o : %.c
		@$(CC) $(CFLAGS) -c $(SRC) -I minilibx_macos/
clean:
		@$(RM) *.o

fclean: clean
		@$(RM) $(NAME)

re: fclean all