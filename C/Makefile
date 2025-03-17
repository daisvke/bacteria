
# ▗▄▄▖ ▗▄▖ ▗▄▄▗▄▄▄▗▄▄▄▗▄▄▖▗▄▄▄▖▗▄▖ 
# ▐▌ ▐▐▌ ▐▐▌    █ ▐▌  ▐▌ ▐▌ █ ▐▌ ▐▌
# ▐▛▀▚▐▛▀▜▐▌    █ ▐▛▀▀▐▛▀▚▖ █ ▐▛▀▜▌
# ▐▙▄▞▐▌ ▐▝▚▄▄▖ █ ▐▙▄▄▐▌ ▐▗▄█▄▐▌ ▐▌
                                 

# ==========================
# Build Configuration
# ==========================

NAME			= bacteria
CC				= clang
CFLAGS			= -Wall -Wextra -Werror

SRC				= $(NAME).c
TMP_DIR			= tmp


# ==========================
# ANSI Escape Codes
# ==========================

# ANSI escape codes for stylized output
RESET 			= \033[0m
GREEN			= \033[32m
YELLOW			= \033[33m
RED				= \033[31m

# Logs levels
INFO 			= $(YELLOW)[INFO]$(RESET)
ERROR			= $(RED)[ERROR]$(RESET)
DONE			= $(GREEN)[DONE]$(RESET)


# ==========================
# Building
# ==========================

.PHONY: all

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo -n "$(DONE) Compilation complete.\n"


# ==========================
# Testing
# ==========================

.PHONY: test

test: $(NAME)
	@echo "$(INFO) Starting tests...\n"
	mkdir -p $(TMP_DIR)/
	cp $(NAME) $(TMP_DIR)/$(NAME)
	@cd $(TMP_DIR) && ./$(NAME) \
	&& echo "\n$(RED)========== Runnning 1st test ==========$(RESET)" \
	&& ls -al | grep $(NAME) | wc -l \
	&& echo "\n$(RED)========== Runnning 2nd test ==========$(RESET)" \
	&& diff ../$(SRC) $(NAME)_5.c ; \
	diff ../$(SRC) $(NAME)_4.c ; \
	diff $(NAME)_5.c $(NAME)_0.c || true
	@echo "\n$(DONE) Tests complete."

.PHONY: collection

i	?= 5
ext	?= txt vob pdf crt

# Produce a given quantity of quines of different file extensions 
collection:
	@if [ "$(i)" -lt 0 ] ; then \
		echo "Usage: make collection i=<QUANTITY> ext=<EXTENSIONS>\n"; \
		echo "Argument 'i' must be superior to 0\n"; \
		exit 1; \
	fi
	@echo "$(INFO) Starting collection...\n"
	@for ext in $(ext); do \
		make -s run_one_quine i=$(i) ext=$$ext; \
	done
	@echo "\n$(DONE) Collection complete."

.PHONY: run_one_quine

run_one_quine:
	@echo "$(INFO) Reproducing bacteria x$$(($(i) + 1)) with .$(ext) extension..."
	@find -name "bacteria.c" -exec sed -i 's/i = [0-9]\+/i = $(i)/g; s/EXT ".*/EXT ".$(ext)"/g' {} \;
	@make -s 
	./$(NAME)


# ==========================
# Cleaning
# ==========================

.PHONY: clean fclean re

clean:
	rm -f $(NAME)_*
	rm -rf $(TMP_DIR)/

fclean: clean
	rm -f $(NAME)

re: fclean all
