NAME = jeu
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
INCLUDES_MAC = -Imlx_mac
INCLUDES_LINUX = -Imlx_linux
LIBS_LINUX = -Lmlx_linux -lmlx_linux
LIBS_MAC = -Lmlx_mac -lmlx -framework OpenGL -framework AppKit
SRC = main.c src/init/game.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBS_LINUX) -o $(NAME)

mac: $(OBJ)
	$(CC) $(OBJ) $(LIBS_MAC) -o $(NAME)

linux: $(OBJ)
	$(CC) $(OBJ) $(LIBS_LINUX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_MAC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: mac
	./$(NAME)
	make fclean

.PHONY: all clean fclean re run
