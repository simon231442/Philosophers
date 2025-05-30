################################################################################
#                               DIRECTORIES                                    #
################################################################################
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

################################################################################
#                                target                                        #
################################################################################
NAME = philo
SRC += $(SRC_DIR)/philo_action_eat.c
SRC += $(SRC_DIR)/philo_action_is_simulation_running.c
SRC += $(SRC_DIR)/philo_action_leave_forks.c
SRC += $(SRC_DIR)/philo_action_print.c
SRC += $(SRC_DIR)/philo_action_routine.c
SRC += $(SRC_DIR)/philo_action_sleep.c
SRC += $(SRC_DIR)/philo_action_take_a_fork.c
SRC += $(SRC_DIR)/philo_action_think.c
SRC += $(SRC_DIR)/philo_core_exit.c
SRC += $(SRC_DIR)/philo_core_init_data.c
SRC += $(SRC_DIR)/philo_core_init_philo.c
SRC += $(SRC_DIR)/philo_core_init_print.c
SRC += $(SRC_DIR)/philo_core_thread_create_and_join.c
SRC += $(SRC_DIR)/philo_core_main.c
SRC += $(SRC_DIR)/philo_inputs_are_valid.c
SRC += $(SRC_DIR)/philo_utils_calloc.c 
SRC += $(SRC_DIR)/philo_utils_atol.c
SRC += $(SRC_DIR)/philo_utils_is_digit.c
SRC += $(SRC_DIR)/philo_utils_get_time.c
SRC += $(SRC_DIR)/philo_utils_memcpy.c
SRC += $(SRC_DIR)/philo_utils_memset.c
SRC += $(SRC_DIR)/philo_utils_ritoa.c
SRC += $(SRC_DIR)/philo_utils_strlen.c
OBJ = $(SRC:src/%.c=obj/%.o)
################################################################################
#                             COMPILER OPTIONS                                 #
################################################################################
CC = cc
CPPFLAG = -I$(INC_DIR)
CFLAG = -Wall -Wextra -Werror -g

################################################################################
#                              TARGETS & RULES                                 #
################################################################################
all: init $(NAME)

init:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@echo "project structure initialized"

$(NAME): $(OBJ)
	@$(CC) $(CFLAG) $(CPPFLAG) $(OBJ) -o $(BIN_DIR)/$(NAME)
	@echo "binary created"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "object files removed"

fclean: clean
	@rm -rf $(BIN_DIR)
	@echo "binary removed"

re: clean all

color: fclean init
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(BIN_DIR)
	@$(MAKE) --no-print-directory $(NAME) CFLAG="$(CFLAG) -DCOLOR"
	@echo "color mode activated"

################################################################################
#                               OBJS & RULES                                   #
################################################################################

obj/%.o: src/%.c
	@$(CC) $(CFLAG) $(CPPFLAG) -c $< -o $@

