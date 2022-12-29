SRCS = megaphone.cpp

DEPSFLAGS = -MMD -MF $(@:.o=.d)

NAME = megaphone

CPP = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJS_DIR = ./objs/

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

DEPS = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.d))

all: $(NAME)
	@make $(NAME) -q && echo "All good here !"

$(OBJS_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CPP) $(FLAGS) -o $@ -c $< $(DEPSFLAGS)

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean
	all

-include $(DEPS)

.PHONY: all clean fclean re
	