NAME=miniRT

CC=cc
CFLAGS=-Wall -Werror -Wextra
RM=rm -f

LIBFT_FOLDER=./libft
LIBFT=$(LIBFT_FOLDER)/libft.a
INCLUDE_LIBFT=-L$(LIBFT_FOLDER) -lft

GNL_FOLDER=./gnl
GNL=$(GNL_FOLDER)/libgnl.a
INCLUDE_GNL=-L$(GNL_FOLDER) -lgnl

MLX_FOLDER=./mlx
MLX=$(MLX_FOLDER)/libmlx.a
INCLUDE_MLX=-L$(MLX_FOLDER) -lmlx

SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/
INC_DIR = include/
C_SUFFIX = .c
C_BONUS_SUFFIX = _bonus.c
H_SUFFIX = .h

INCLUDE = -I$(INC_DIR) -I$(LIBFT_FOLDER) -I$(GNL_FOLDER) -I$(MLX_FOLDER)
INCLUDE_BONUS = -I$(subst include,include_bonus,$(INC_DIR)) -I$(LIBFT_FOLDER) -I$(GNL_FOLDER) -I$(MLX_FOLDER)

HEADERS = 					$(addprefix $(INC_DIR), $(addsuffix $(H_SUFFIX), \
								miniRT \
								structure \
								vec_utils))

BONUS_HEADERS =				$(subst include,include_bonus,$(subst .h,_bonus.h,$(HEADERS)))

INIT =						$(addprefix init/, $(addsuffix $(C_SUFFIX), \
								init_info \
								init_util1 \
								init_util2 \
								init_util3 \
								init_pl \
								init_sp \
								init_cy \
								init_mlx))

INIT_BONUS =				$(addprefix init/, $(addsuffix $(C_BONUS_SUFFIX), \
								init_util4 \
								init_pb)) \
								$(subst .c,_bonus.c,$(INIT))

CREATE =					$(addprefix create/, $(addsuffix $(C_SUFFIX), \
								camera \
								light \
								ray \
								rec \
								object_create))

CREATE_BONUS =				$(subst .c,_bonus.c,$(CREATE))

RAY =						$(addprefix ray/, $(addsuffix $(C_SUFFIX), \
								ray))

RAY_BONUS = 				$(subst .c,_bonus.c,$(RAY))

MLX_C =						$(addprefix mlx/, $(addsuffix $(C_SUFFIX), \
								miniRT_loop \
								mlx_event))

MLX_BONUS =					$(subst .c,_bonus.c,$(MLX_C))

HIT =						$(addprefix hit/, $(addsuffix $(C_SUFFIX), \
								hit \
								sphere \
								plane \
								cylinder ))

HIT_BONUS =					$(addprefix hit/, $(addsuffix $(C_BONUS_SUFFIX), \
								paraboloid)) \
								$(subst .c,_bonus.c,$(HIT))

PHONG =						$(addprefix phong/, $(addsuffix $(C_SUFFIX), \
								phong_lighting \
								is_in_shadow \
								sphere \
								plane \
								cylinder))

PHONG_BONUS = 				$(addprefix phong/, $(addsuffix $(C_BONUS_SUFFIX), \
								paraboloid)) \
								$(subst .c,_bonus.c,$(PHONG))

VECTOR_UTILITY =			$(addprefix vector_utils/, $(addsuffix $(C_SUFFIX), \
								vector_utils \
								vector_utils2 \
								vector_utils3 ))

VECTOR_UTILITY_BONUS =		$(subst .c,_bonus.c,$(VECTOR_UTILITY))

BONUS_UTILS = 				$(addprefix bonus_utils/, $(addsuffix $(C_BONUS_SUFFIX), \
								check_xpm_file \
								get_rec_color \
								parse_color_obj \
								pthread \
								put_bumpmap \
								str_exit))

SRCS = 						$(addprefix $(SRC_DIR), $(addsuffix $(C_SUFFIX), \
								main) \
								$(INIT) \
								$(CREATE) \
								$(MLX_C) \
								$(RAY) \
								$(HIT) \
								$(PHONG) \
								$(VECTOR_UTILITY))

SRC_BONUS =					$(addprefix $(SRC_BONUS_DIR), $(addsuffix $(C_BONUS_SUFFIX), \
								main) \
								$(INIT_BONUS) \
								$(CREATE_BONUS) \
								$(MLX_BONUS) \
								$(RAY_BONUS) \
								$(HIT_BONUS) \
								$(PHONG_BONUS) \
								$(VECTOR_UTILITY_BONUS) \
								$(BONUS_UTILS))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

LIBRARY = $(INCLUDE_LIBFT) $(INCLUDE_GNL) $(INCLUDE_MLX)

TEMP_FILES = LAST_ALL LAST_BONUS

all: LAST_ALL
$(NAME): LAST_ALL
LAST_ALL: $(OBJS) $(LIBFT) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -framework OpenGL -framework AppKit $(LIBRARY) -o $(NAME)
	$(RM) $(TEMP_FILES)
	touch LAST_ALL

%_bonus.o: %_bonus.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE_BONUS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

$(LIBFT):
	make -C $(LIBFT_FOLDER) bonus

$(GNL_DIR)$(GNL) :
	make -C $(GNL_FOLDER) all

$(MLX_DIR)$(MLX) :
	make -C $(MLX_FOLDER) all

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	$(RM) $(TEMP_FILES)
	make -C $(LIBFT_FOLDER) clean
	make -C $(GNL_FOLDER) clean
	make -C $(MLX_FOLDER) clean

fclean:
	make clean
	$(RM) $(NAME)
	make -C $(LIBFT_FOLDER) fclean
	make -C $(GNL_FOLDER) fclean

re:
	make fclean
	make all

bonus: LAST_BONUS
LAST_BONUS: $(OBJS_BONUS) $(LIBFT) $(GNL) $(MLX)
	$(CC) $(CFLAGS) $(INCLUDE_BONUS) $(OBJS_BONUS) -framework OpenGL -framework AppKit $(LIBRARY) -o $(NAME)
	$(RM) $(TEMP_FILES)
	touch LAST_BONUS

.PHONY: all clean fclean re bonus
