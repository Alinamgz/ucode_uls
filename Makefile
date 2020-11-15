# ---------------- variables ----------------
NAME := uls
LIB := libmx

# -- files and dirs --
INC_DIR := inc
SRC_DIR := src
OBJ_DIR := obj
LIB_DIR := ./$(LIB)
LIB_INC_DIR := $(LIB_DIR)/$(INC_DIR)

INC_FILES := $(wildcard $(INC_DIR)/*.h)
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))
LIB_FILE := $(addprefix $(LIB_DIR)/, $(addsuffix .a, $(LIB)))

# -- commands --
RM := rm -rdf
MKDIR := mkdir -p

CC := clang
CFLAGS := -std=c11 -Wall -Werror -Wextra -Wpedantic

# ---------------- body ----------------

all: $(LIB_FILE) $(NAME)

$(LIB_FILE): $(LIB_DIR)
	@$(MAKE) -sC $(LIB_DIR)

$(NAME): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $(OBJ_FILES) -L$(LIB_DIR) -lmx -o $@

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -I $(LIB_INC_DIR) -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C $(LIB_DIR)

uninstall: clean
	@$(RM) $(NAME)
	@$(MAKE) uninstall -C $(LIB_DIR)

reinstall: uninstall all

.PHONY: all uninstall clean reinstall libmx

