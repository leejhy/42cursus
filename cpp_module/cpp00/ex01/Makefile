CXX = c++ 
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 
SRCS =	PhoneBook.cpp \
		Contact.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex01

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