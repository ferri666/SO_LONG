
NAME 			= so_long
LIBFT_DIR		= libft/
LIBFT			= libft.a
BONUS			= so_long_bonus

SRC_FILES		= game load images images2 main error maps maps2 maps3 \
				map_utils move move2 game_utils
B_FILES			= game_bonus load_bonus images_bonus images_bonus2 \
				main_bonus error_bonus maps_bonus maps2_bonus maps3_bonus \
				map_utils_bonus move_bonus move2_bonus game_utils_bonus
SRC_DIR			= srcs/
B_DIR			= bonus/
OBJ_DIR			= objs/
BO_DIR			= objs/
INCLUDE			= include/

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE)
MFLAGS			= -ldl -lm -lmlx -framework OpenGL -framework AppKit -lz
AR				= ar rcs 

SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
B_S 			= 	$(addprefix $(B_DIR), $(addsuffix .c, $(B_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
B_OBJ			=	$(addprefix $(BO_DIR), $(addsuffix .o, $(B_FILES)))

$(NAME)			:	$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $^ -o $@ $(MFLAGS)
					@echo "Program Created"

all:				$(NAME) $(BONUS)

bonus			: 	$(BONUS)

$(BONUS)		:	$(B_OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $^ -o $@ $(MFLAGS)
					@echo "Bonus Created"

$(LIBFT)		:	$(LIBFT_DIR)
					@make -C $(LIBFT_DIR)
					@cp $(LIBFT_DIR)/$(LIBFT) .

$(OBJ_DIR)%.o	: 	$(SRC_DIR)%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^
					
$(BO_DIR)%.o	: 	$(B_DIR)%.c
					@mkdir -p $(BO_DIR)
					@$(CC) $(CFLAGS) -o $@ -c $^

clean:
	@echo "Clean Boys!"
	@$(RM) ${OBJ} ${B_OBJ}
	@make -C $(LIBFT_DIR) clean
	@${RM} -r ${OBJ_DIR} 

fclean: clean
	@echo "Super Clean Boys!"
	@${RM} ${OBJS} ${NAME} ${LIBFT} ${BONUS}
	@make -C $(LIBFT_DIR) fclean

re: fclean all
re-bonus: fclean bonus
re-all: fclean all bonus

norm:          
		@norminette $(INCLUDE) $(LIBFT_DIR) $(SRC_DIR) $(B_DIR)| grep -v Norme -B1 || true

.PHONY: all clean fclean re norm bonus re-all re-bonus