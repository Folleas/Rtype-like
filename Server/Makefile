CC      =       g++

NAME    =       server

SRC     =       server.cpp

OBJ     =       $(SRC:.cpp=.o)

all:            $(NAME)

$(NAME):        $(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lpthread

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)

re:             fclean all

.PHONY:         all clean fclean re
