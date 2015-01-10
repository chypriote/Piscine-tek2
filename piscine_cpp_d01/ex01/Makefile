
NAME=	menger

SRC=	menger.c \
	main.c \

OBJ=	$(SRC:.c=.o)

CC=	gcc -Wall -Wextra -Werror -std=gnu99

RM=	rm -rf

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
