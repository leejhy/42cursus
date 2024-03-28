CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 
SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = megaphone

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o : %.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all