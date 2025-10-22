CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = easyfind
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp easyfind.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all