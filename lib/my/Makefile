##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## build library
##

NAME = libmy.a
SRC = my_putchar.c \
	my_putstr.c \
	my_revstr.c \
	my_strlen.c \
	my_intlen.c \
	my_itoa.c \
	my_getnbr.c \
	my_strcat.c \
	my_strcmp.c \
	my_strchr.c \
	my_strtok.c \
	my_strstr.c \
	my_strdup.c \
	my_atoi.c \
	my_tablen.c \
	fs_utils.c \
	my_put_nbr.c \
	my_pow.c \

OBJ = $(SRC:.c=.o)
LIBFLAG = -Wall -Wextra -I ./include
CFLAGS = $(LIBFLAG)

all: $(NAME)

.SILENT:
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../$(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OBJ)
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all
