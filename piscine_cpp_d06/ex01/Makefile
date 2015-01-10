NAME=	my_convert_temp

SRC=	main.cpp \

OBJ=	$(SRC:.cpp=.o)

CC=	g++ -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:	fclean all
