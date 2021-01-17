##
## EPITECH PROJECT, 2020
## enemies
## File description:
## makefile
##

SRC     =	Enemies.cpp\
			../R-type/src/Bullet.cpp\
			../Encapsulation/src/Time.cpp\
			../GameObject/src/GameObject.cpp



OBJ     =	Enemies.o\
			Bullet.o\
			GameObject.o\
			Time.o\

NAME    =	enemies.so

INCLUDE = 	-I ../GameObject/include\
			-I ../Encapsulation/include\
			-I ../Miscellaneous/include\
			-I ../R-type/include

all:    $(NAME)

$(NAME):
	g++ $(INCLUDE) -c -fpic $(SRC)
	g++ -shared -o $(NAME) $(OBJ)
	mv $(NAME) ../

debog:  fclean

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re:     fclean all


.PHONY: all debog clean fclean re