NAME		= codexion
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -Iincludes -MMD -MP
MAKEFLAGS	= --no-print-directory

SRCS_DIR	= src
OBJDIR		= obj

SRCS		= \
				main.c

OBJS		= $(addprefix $(OBJDIR)/,$(SRCS:.c=.o))
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
