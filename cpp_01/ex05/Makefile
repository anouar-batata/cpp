CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = 
SRC = main.cpp Harl.cpp
OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Harl.hpp
	$(CPP) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
