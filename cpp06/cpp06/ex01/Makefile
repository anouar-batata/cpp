CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = prog
SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp Serializer.hpp Data.hpp
	$(CPP) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

