NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ft_printf.c \
      ft_putchar.c \
      ft_putstr.c \
      ft_putnbr.c \
      print_hex.c \
      ft_print_unsigned.c\

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $^

%.o: %.c $(HEADER)
	$(CC) $(LAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


