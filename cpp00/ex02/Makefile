# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 13:53:11 by lemercie          #+#    #+#              #
#    Updated: 2025/01/14 11:06:57 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++98
DEBUGFLAGS 	= -g

SRCS		= tests.cpp Account.cpp
OBJS		= $(SRCS:.cpp=.o)
NAME		= test

all: $(NAME)

%.o: %.cpp Account.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

$(NAME): $(OBJS) Account.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
