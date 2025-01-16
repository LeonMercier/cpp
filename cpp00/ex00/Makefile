# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 13:53:11 by lemercie          #+#    #+#              #
#    Updated: 2025/01/16 16:24:30 by leon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= c++
CXXFLAGS 	= -Wall -Wextra -Werror -std=c++11

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)
NAME		= megaphone

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
