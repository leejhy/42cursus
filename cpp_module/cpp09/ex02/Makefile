CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror# -fsanitize=address -g3
SRCS =	PmergeMe.cpp\
		main.cpp
INC =	PmergeMe.hpp
OBJS = $(SRCS:.cpp=.o)
NAME = PmergeMe

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