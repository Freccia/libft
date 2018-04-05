# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 15:18:12 by lfabbro           #+#    #+#              #
#    Updated: 2018/04/05 18:18:57 by lfabbro          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binaries
PROJECT		?= libft

# Sources ft_printf
SRC_PRINTF	= \
	printf/ft_printf.c  printf/ftpf_lenght.c  printf/ftpf_parse.c  \
	printf/ftpf_conversions.c  printf/ftpf_handle_wchar.c  \
	printf/ftpf_formats_00.c   printf/ftpf_formats_01.c  \
	printf/ftpf_set.c   printf/ftpf_padding.c  \
	printf/ftpf_int.c   printf/ftpf_octal.c  \
	printf/ftpf_char.c  printf/ftpf_hex.c  \
	printf/ftpf_ptr.c   printf/ftpf_str.c  \
	printf/ftpf_uint.c  printf/ftpf_wstr.c  printf/ftpf_wchar.c

#  Sources
SRC_NAME		=  \
	$(SRC_PRINTF)  \
	ctrl/ch_ctrl1.c  ctrl/ch_ctrl2.c  ctrl/file_ctrl.c  ctrl/nbr_ctrl.c  \
	ctrl/str_ctrl.c  ctrl/quote_ctrl.c  \
	str/ft_strcat.c  str/ft_strchr.c  str/ft_strclr.c  str/ft_strcmp.c  \
	str/ft_strcpy.c  str/ft_strdel.c  str/ft_strdup.c  str/ft_strequ.c  \
	str/ft_striter.c  str/ft_striteri.c  str/ft_strjoin.c  str/ft_strlcat.c  \
	str/ft_strlen.c  str/ft_strmap.c  str/ft_strmapi.c  str/ft_strncat.c  \
	str/ft_strncmp.c  str/ft_strncpy.c  str/ft_strndup.c  str/ft_strnequ.c  \
	str/ft_strnew.c  str/ft_strnstr.c  str/ft_strrchr.c  str/ft_strsplit.c  \
	str/ft_strsplit_quote.c  str/ft_strsplit_quote_bs.c  \
	str/ft_strsplit_wo_quote.c  str/ft_strsplit_wo_quote_bs.c  \
	str/ft_strstr.c  str/ft_strsub.c  str/ft_strtrim.c  str/ft_strxchr.c  \
	str/ft_strxtrim.c  str/ft_strxtrim_quote.c  str/ft_xword.c  \
	str/ft_toupper.c  str/ft_tolower.c  str/ft_wchar_size.c  str/ft_wstrlen.c  \
	io/getch.c  io/print_memory.c  io/putch.c  io/putnbr.c  io/putstr.c\
	tab/tab_mem.c  tab/tab_mov.c  \
	mem/ft_memalloc.c  mem/ft_memccpy.c  mem/ft_memchr.c  mem/ft_memcmp.c  \
	mem/ft_memcpy.c  mem/ft_memdel.c  mem/ft_memmove.c  mem/ft_mem_realloc.c  \
	mem/ft_memset.c  mem/ft_bzero.c  mem/ft_swap.c  \
	lst/lst_mem.c  lst/lst_mov.c  \
	math/ft_abs.c  math/ft_pow.c  \
	conv/ft_atoi.c  conv/ft_atol.c  conv/ft_atoll.c  conv/ft_itoa_base.c  \
	conv/ft_itoa.c  conv/ft_lltoa_base.c  conv/ft_nbrlen.c  \
	conv/ft_ulltoa_base.c  \
	get_next_line.c

# Directories
SRC_PATH	= src
INC_PATH	= include
TEST_PATH	= test

# Compilation flags
CFLAGS		+= -g    #-O3

OBJ_DIR		?= obj
OBJ_PATH	?= $(OBJ_DIR)/rel
OBJ			= $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
DEP			= $(OBJ:%.o=%.d)
# Includes
INC			= $(addprefix -I./,$(INC_PATH))

# Compilation/Linking Flags for the differents public rules
WFLAGS = -Wextra -Wall #-Werror
RCFLAGS = $(WFLAGS) -Werror -O2 -march=native  # release
DCFLAGS = $(WFLAGS) -g3 -DDEBUG  # debug
SCFLAGS = $(DCFLAGS) -fsanitize=address,undefined -ferror-limit=5  # sanitize
WWFLAGS = $(WFLAGS) -Wpedantic -Wshadow -Wconversion -Wcast-align \
  -Wstrict-prototypes -Wmissing-prototypes -Wunreachable-code -Winit-self \
  -Wmissing-declarations -Wfloat-equal -Wbad-function-cast -Wundef \
  -Waggregate-return -Wstrict-overflow=5 -Wold-style-definition -Wpadded \
  -Wredundant-decls  # moar warnings

# Compilation
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	CC			= clang
	CCFLAGS		+= -D LINUX
endif
ifeq ($(UNAME_S),Darwin)
	CC			= clang
	CCFLAGS += -D OSX
endif

# Commands
MAKE		?= make -j$(shell nproc 2>/dev/null || echo 4)
SUB_MAKE	= make -C
MKDIR		= mkdir -p
RMDIR		= rm -rf
RM			= rm -f

# default to "pretty" Makefile, but you can run ´VERBOSE=t make´
ifndef VERBOSE
 ifndef TRAVIS
.SILENT:
 endif
endif
PRINTF		= test $(VERBOSE)$(TRAVIS) || printf

# Colors
RED			= \033[31m
GREEN		= \033[32m
YELLOW		= \033[33m
BLUE		= \033[34m
WHITE		= \033[37m
TODO1		= \033[0K  #TODO
TODO2		= \033[17C #TODO
ENDC		= \033[0m
CR			= \r


##
## PUBLIC RULES
##

# Builds
all:
	@$(PRINTF) "%-20s"    "$(PROJECT).a: lib"
	+$(MAKE) $(PROJECT).a   "CFLAGS = $(RCFLAGS)"  "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "$(CR)$(GREEN)✔$(ENDC)\n"

dev:
	@$(PRINTF) "%-20s"    "$(PROJECT).dev: bin"
	+$(MAKE) $(PROJECT).dev.a "PROJECT = $(PROJECT).dev" "CFLAGS = $(DCFLAGS)" \
		"OBJ_PATH = $(OBJ_DIR)/dev"
	@$(PRINTF) "$(CR)$(GREEN)✔$(ENDC)\n"

san:
	@$(PRINTF) "%-20s"    "$(PROJECT).san: bin"
	+$(MAKE) $(PROJECT).san.a "PROJECT = $(PROJECT).san" "CFLAGS = $(SCFLAGS)" \
		"OBJ_PATH = $(OBJ_DIR)/san"
	@$(PRINTF) "$(CR)$(GREEN)✔$(ENDC)\n"

mecry:
	@$(PRINTF) "%-20s"    "$(PROJECT).a: omg"
	+$(MAKE) $(PROJECT).a  "CFLAGS = $(WWFLAGS)"  "OBJ_PATH = $(OBJ_DIR)/rel"
	@$(PRINTF) "$(CR)$(GREEN)✔$(ENDC)\n"

# Other rules
test:
	@$(PRINTF) "%-20s"    "No tests yet."

clean:
	@$(RMDIR) $(OBJ_DIR) $(PROJECT).dSYM
	@$(PRINTF) "%-20s$(GREEN)✔$(ENDC)\n"    "$(PROJECT): $@"

fclean: clean
	@$(RM) $(PROJECT).a $(PROJECT).dev.a $(PROJECT).san.a
	@$(PRINTF) "%-20s$(GREEN)✔$(ENDC)\n"    "$(PROJECT): $@"

re: fclean all

norme:
	@$(PRINTF) "$(WHITE) Norminette $(ENDC)\n"
	norminette $(SRC_PATH) $(INC_PATH)


##
## PRIVATE RULES
##

# (link) project
$(PROJECT).a: $(OBJ)
	@$(PRINTF) "$(CR)$(TODO1)$(TODO2)$(WHITE)  $@  $(ENDC)"
	ar -rc $(PROJECT).a $(OBJ)
	ranlib $(PROJECT).a

# (compile) objects
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | dirs #$(OBJ_PATH)
	@$(PRINTF) "$(CR)$(TODO1)$(TODO2)$(WHITE)  $<  $(ENDC)"
	$(CC) $(CFLAGS) $(INC)  -c $< -o $@

# create directory for compilation sub-products
#$(OBJ_PATH):
dirs:
	$(MKDIR) $(dir $(OBJ))

# read dependencies list generated by -MMD flag
-include $(DEP)

# avoid conflicts between rules and files/folders names
.PHONY:	all dev san mecry clean fclean re norme $(PROJECT).a
