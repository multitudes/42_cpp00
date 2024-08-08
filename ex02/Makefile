CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -Wshadow -pedantic -Wconversion -Wunreachable-code

# -O0: Disables optimization to make debugging easier..
CXXFLAGS += -g3 -O0

# Uncomment this line to turn off debug flags
CXXFLAGS += -DNDEBUG

CXX = c++

NAME = theJobOfYourDreams
ARGS =
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run:
	@echo
	@PATH=".$${PATH:+:$${PATH}}" && $(NAME)

tests:
	make -C tests

.PHONY: all clean fclean re $(NAME) tests