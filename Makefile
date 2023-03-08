##
## EPITECH PROJECT, 2023
## navy
## File description:
## Makefile
##

NAME = navy
CC	= gcc
SRC	= src/main.c \
	src/navy.c \
	src/helpers/utils.c \
	src/helpers/binary.c \
	src/helpers/client/send_signals.c \
	src/helpers/server/receive_signals.c \
	src/helpers/server/handle_hits.c \
	src/helpers/map.c \
	src/helpers/coordinates.c \
	src/helpers/errors.c \
	src/helpers/game.c \
	src/helpers/placement.c \

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -Wall -Wextra -L lib/my -lmy -I ./include -I ../lib/my/include \
		-D _DEFAULT_SOURCE

all: $(NAME)
$(NAME):
	make -C lib/my/
	cp lib/my/include/my.h include
	$(CC) -o $(NAME) $(SRC) $(LIBFLAG) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my/

re: fclean all

cstyle:
	make fclean
	cstyle
