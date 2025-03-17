
# ▗▄▄▖ ▗▄▖ ▗▄▄▗▄▄▄▗▄▄▄▗▄▄▖▗▄▄▄▖▗▄▖ 
# ▐▌ ▐▐▌ ▐▐▌    █ ▐▌  ▐▌ ▐▌ █ ▐▌ ▐▌
# ▐▛▀▚▐▛▀▜▐▌    █ ▐▛▀▀▐▛▀▚▖ █ ▐▛▀▜▌
# ▐▙▄▞▐▌ ▐▝▚▄▄▖ █ ▐▙▄▄▐▌ ▐▗▄█▄▐▌ ▐▌
                                 

NAME		= bacteria
CC			= clang
CFLAGS		= -Wall -Wextra -Werror

SRC			= $(NAME).c
TMP_DIR		= tmp

# ==========================
# ANSI Escape Codes
# ==========================

# ANSI escape codes for stylized output
RESET 		= \033[0m
GREEN		= \033[32m
YELLOW		= \033[33m
RED			= \033[31m

# Logs levels
INFO 		= $(YELLOW)[INFO]$(RESET)
ERROR		= $(RED)[ERROR]$(RESET)
DONE		= $(GREEN)[DONE]$(RESET)

.PHONY: all test clean fclean re

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo -n "$(DONE) Compilation complete.\n"

test: $(NAME)
	mkdir -p $(TMP_DIR)/
	cp $(NAME) $(TMP_DIR)/$(NAME)
	cd $(TMP_DIR) && ./$(NAME) \
	&& echo "\n\033[31m========== Runnning 1st test ==========\033[0m" \
	&& ls -al | grep $(NAME) | wc -l \
	&& echo "\n\033[31m========== Runnning 2nd test ==========\033[0m" \
	&& diff ../$(SRC) $(NAME)_5.c ; \
	diff ../$(SRC) $(NAME)_4.c ; \
	diff $(NAME)_5.c $(NAME)_0.c || true

# Produce a given quantity of quines of different file extensions 
collection:
	@if [ -z "$(ext)" ] || [ -z "$(i)" ] || [ "$(i)" -lt 1 ] ; then \
		echo "Usage: make collection n=<QUANTITY> ext=<EXTENSIONS>\n"; \
		echo "Argument 'i' must be superior to 1\n"; \
		exit 1; \
	fi
	@echo -n "$(INFO) Starting collection...\n\n"
	@for ext in $(ext); do \
		make -s run_one_quine n=$(i) ext=$$ext; \
	done
	@echo -n "\n$(DONE) Collection complete.\n"

run_one_quine:
	@echo -n "$(INFO) Reproducing bacteria x$$(($(i) + 1)) with .$(ext) extension...\n"
	@find -name "bacteria.c" -exec sed -i 's/i = [0-9]\+/i = $(i)/g; s/EXT ".*/EXT ".$(ext)"/g' {} \;
	@make -s 
	./$(NAME)

clean:
	rm -f $(NAME)_*
	rm -rf $(TMP_DIR)/

fclean: clean
	rm -f $(NAME)

re: fclean all
