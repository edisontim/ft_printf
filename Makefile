# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedison <tedison@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/16 10:19:48 by tedison           #+#    #+#              #
#    Updated: 2021/04/22 17:24:53 by tedison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	decimal_unsigned_hex_utils.c\
				decimal_utils.c\
				ft_bzero.c\
				ft_printf.c\
				ft_printf_utils.c\
				ft_putnbr_base_unsigned.c\
				ft_putnbr_base.c\
				ft_strlen.c\
				hex.c\
				param_utils_pourcent_type.c\
				string_char_pointer.c


OBJS		=	$(SRCS:.c=.o)



CC			= gcc
RM			= rm -f
CFLAGS		= -I.

NAME		= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re
