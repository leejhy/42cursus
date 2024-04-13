CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror# -g3 -fsanitize=address
SRCS =	ClapTrap.cpp\
		main.cpp
INC =	ClapTrap.hpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex00

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp $(INC)
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all