# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfranco- <vfranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/30 20:47:17 by vfranco-          #+#    #+#              #
#    Updated: 2022/07/04 15:30:39 by vfranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

FILES		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_bzero.c \
				ft_atoi.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strncmp.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memcmp.c \
				ft_memchr.c \
				ft_memmove.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strtrimc.c \
				ft_itoa.c \
				ft_putstr_fd.c \
				ft_putnbr_fd.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_split.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_min.c \
				ft_abs.c

FILES_BONUS =	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c

FLAGS		=	-Wall -Wextra -Werror
OBJ			=	$(FILES:.c=.o)
OBJ_BONUS	=	$(FILES_BONUS:.c=.o)

###################################################################

all:	$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

%.o:	%.c
			clang -c $(FLAGS) $<

bonus:		$(OBJ_BONUS)
			ar rcs $(NAME) $(OBJ_BONUS)

clean:
			rm -f $(OBJ) $(OBJ_BONUS)

fclean:	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
