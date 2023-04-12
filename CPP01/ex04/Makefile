SRCS = main.cpp 

CPPFLAGS = -MMD -MF $(@:.o=.d)

INC = -I ./include/

NAME = sed

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

OBJS_DIR = ./objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

DEPS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.d))

all: $(NAME)
	@make $(NAME) -q && echo "All good here !"

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(CPPFLAGS) $(INC)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS_DIR)
	rm *.replace

fclean: clean
	rm -rf $(NAME)

re: fclean
	@make all

-include $(DEPS)

.PHONY: all clean fclean re
	