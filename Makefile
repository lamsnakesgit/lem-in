NAME = lem-in

SRC =   alg.c       bft.c       aux.c       lem_in.c\
        suurballe.c traverse.c  val_map.c\
        valink.c    valprocess.c valroom.c  valroom1.c split.c valdi.c freefun.c

OBJ = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@gcc -o $(NAME)  $(SRC) -L ./libft -lft -Wall -Wextra -Werror

clean:
	@make -C ./libft fclean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
