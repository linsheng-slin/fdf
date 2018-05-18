#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/03 22:32:34 by slin              #+#    #+#              #
#    Updated: 2018/03/22 14:58:21 by slin             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= 	libft.a

SRC		= 	ft_bzero.c ft_memccpy.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c \
			ft_strcpy.c ft_strdup.c ft_strnstr.c ft_strstr.c \
			ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c \
			ft_strncpy.c ft_strrchr.c \
			ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
			ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
			ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
			ft_strjoin.c ft_strtrim.c ft_strsplit.c \
			ft_strlen_char.c ft_strrev.c ft_print_bits.c \
			get_next_line.c

OBJ		= 	$(SRC:.c=.o)

CC		= 	gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
		@$(RM) $(OBJ)

fclean: clean
		@$(RM) $(NAME)

re: fclean all
