NAME = lem-in
FLAG = -Wall -Werror -Wextra -g
SRC = *.c

SRC_PATH = src/

SRCF = $(addprefix SRC_PATH, SRC);

OBJ = $(SRCF:.c:.o) #SRC_PATH

all: $(NAME)

$(NAME):
	gcc $(FLAG) $(SRCF) 
