NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c \
	utils/ft_print_char.c \
	utils/ft_print_hex.c \
	utils/ft_print_number.c \
	utils/ft_print_pointer.c \
	utils/ft_print_string.c \
	utils/ft_print_unsigned.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re