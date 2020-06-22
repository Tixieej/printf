# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rde-vrie <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/15 13:34:34 by rde-vrie      #+#    #+#                  #
#    Updated: 2020/02/02 11:44:54 by rde-vrie      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c integer.c integer2.c string.c char.c pointer.c hex.c uint.c \
	  conversion_router.c
OBJ_SRC = $(SRC:.c=.o)
LIBFT_FILES = ft_atoi.o ft_strlen.o ft_strjoin.o ft_itoa.o
OBJ_LIBFT = $(addprefix libft2/, $(LIBFT_FILES))
HEADER = libftprintf.h
FLAGS = -g -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_SRC)
	cd libft2 && make
	ar rc $(NAME) $(OBJ_SRC) $(OBJ_LIBFT)

%.o: %.c $(HEADER)
	gcc -c $(FLAGS) -I. -o $@ $<

clean:
	$(RM) $(OBJ_SRC)

fclean: clean
	$(RM) $(NAME)
	cd libft2 && make fclean

re: fclean all

test:
	gcc $(FLAGS) main.c -L. -lftprintf
	./a.out
