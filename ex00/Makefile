# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/09 11:52:37 by shurtado          #+#    #+#              #
#    Updated: 2025/03/11 16:37:55 by shurtado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Bureaucrat
CC			=	c++
CPPFLAGS	=	-g -Wall -Werror -Wextra -std=c++98 -MMD -MP -fsanitize=address -pedantic

LDFLAGS		=	-L$(CUTE_DIR) -lcute
INCLUDES	=	-I$(CUTE_DIR)/inc

CUTE_DIR	=	../shared/lib
CUTE		=	$(CUTE_DIR)/libcute.a

CLASSES		=	Bureaucrat
SRC			=	$(addprefix src/, $(foreach class, $(CLASSES), $(class)/$(class).cpp) main.cpp)

OBJS		=	$(SRC:%.cpp=obj/%.o)
DEPS		=	$(OBJS:.o=.d)

all: $(CUTE) $(NAME)

$(CUTE):
	git submodule update --init --recursive
	$(MAKE) -C $(CUTE_DIR)

$(NAME): $(OBJS) $(CUTE)
	$(CC) $(INCLUDES) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

obj/%.o: %.cpp Makefile
	@mkdir -p $(dir $@)
	$(CC) $(INCLUDES) $(CPPFLAGS) -c $< -o $@


clean:
	rm -rf obj
	@$(MAKE) clean -C $(CUTE_DIR)


fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(CUTE_DIR)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
