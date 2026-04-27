NAME		= codexion
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -Iincludes -MMD -MP
MAKEFLAGS	= --no-print-directory

SRCS_DIR	= src
OBJS_DIR	= obj

GREEN		= \033[1;32m
BLUE		= \033[1;34m
RED			= \033[1;31m
RESET		= \033[0m

SRCS		= \
				main.c \
				parsing/parse_args.c \
				init/init_data.c \
				init/init_coders.c \
				init/init_dongles.c \
				threads/coder_routine.c \
				threads/monitor.c \
				dongles/acquire_dongle.c \
				dongles/dongle_order.c \
				dongles/release_dongle.c \
				queue/queue.c \
				queue/scheduler.c \
				utils/log.c \
				utils/error.c \
				utils/atoui.c \
				utils/atosch.c \
				utils/strcmp.c \
				utils/strlen.c \
				utils/isnumber.c \
				utils/cleanup.c \
				utils/time.c

OBJS		= $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))
DEPS		= $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	@printf "  $(GREEN)LD$(RESET)  %s\n" $@
	@$(CC) $(OBJS) -o $(NAME) -pthread

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	@printf "  $(BLUE)CC$(RESET)  %s\n" $<
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf "  $(RED)RM$(RESET)  %s\n" $(OBJS_DIR)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@printf "  $(RED)RM$(RESET)  %s\n" $(NAME)
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
