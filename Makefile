# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rde-vrie <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/15 13:34:34 by rde-vrie      #+#    #+#                  #
#    Updated: 2020/01/22 15:27:20 by rde-vrie      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c ft_int2.c ft_string.c ft_char.c ft_pointer.c ft_hex.c ft_uint.c
OBJ_SRC = $(SRC:.c=.o)
BONUS =
OBJ_BONUS = $(BONUS:.c=.o)
LIBFT_FILES = ft_atoi.o ft_strlen.o ft_strjoin.o ft_itoa.o
OBJ_LIBFT = $(addprefix libft/, $(LIBFT_FILES))
HEADER = libftprintf.h
FLAGS = -g -Wall -Werror -Wextra

ifdef WITH_BONUS
OFILES = $(OBJ_SRC) $(OBJ_BONUS)
else
OFILES = $(OBJ_SRC)
endif

all: $(NAME)

$(NAME): $(OFILES)
	cd libft && make
	ar rc $(NAME) $(OFILES) $(OBJ_LIBFT)

%.o: %.c $(HEADER)
	gcc -c $(FLAGS) -I. -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	$(RM) $(OBJ_SRC) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME)
	cd libft && make fclean

re: fclean all

test:
	gcc $(FLAGS) main.c -L. -lftprintf
	./a.out
