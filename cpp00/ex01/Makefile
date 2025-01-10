# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 13:53:11 by lemercie          #+#    #+#              #
#    Updated: 2025/01/10 16:53:49 by lemercie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror
DEBUGFLAGS 	= -g

SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)
NAME		= phonebook

all: $(NAME)

%.o: %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: 
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
