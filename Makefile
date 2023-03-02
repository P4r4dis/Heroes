G++						=	g++
###############################################
PART0_PATH 				= 	./part0_Peasant
PART0_SRC_PATH			=	./part0_Peasant/src
PART0_TST_PATH			=	./part0_Peasant/tests
PART0_INC_PATH			=	./part0_Peasant/include
NAME_PEASANT			=	Peasant
PART0_SRC				=	$(PART0_SRC_PATH)/Peasant.cpp

PART0_SRC_TEST			=	$(PART0_TST_PATH)/$(NAME_PEASANT)_test.cpp
TEST_NAME_PEASANT 		= 	test_$(NAME_PEASANT)

###############################################
# PART1_PATH 				= 	./part1_koalaBot
# PART1_SRC_PATH			=	./part1_koalaBot/src
# PART1_TST_PATH			=	./part1_koalaBot/tests
# PART1_INC_PATH			=	./part1_koalaBot/include
# NAME_KOALABOT			=	KoalaBot
# PART1_SRC				=	$(PART1_SRC_PATH)/KoalaBot.cpp 
# 							$(PART1_SRC_PATH)/Parts.cpp
# PART1_SRC_TEST			=	$(PART1_TST_PATH)/$(NAME_KOALABOT)_test.cpp
# TEST_NAME_KOALABOT 		= 	test_$(NAME_KOALABOT)

###############################################
# PART2_PATH 				= 	./part2_kreogCom
# PART2_SRC_PATH			=	./part2_kreogCom/src
# PART2_TST_PATH			=	./part2_kreogCom/tests
# PART2_INC_PATH			=	./part2_kreogCom/include
# NAME_KREOGCOM			=	KreogCom
# PART2_SRC				=	$(PART2_SRC_PATH)/KreogCom.cpp

# PART2_SRC_TEST			=	$(PART2_TST_PATH)/$(NAME_KREOGCOM)_test.cpp
# TEST_NAME_KREOGCOM 		= 	test_$(NAME_KREOGCOM)

###############################################
# PART3_PATH 				= 	./part3_phaser
# PART3_SRC_PATH			=	./part3_phaser/src
# PART3_TST_PATH			=	./part3_phaser/tests
# PART3_INC_PATH			=	./part3_phaser/include
# NAME_PHASER				=	Phaser
# PART3_SRC				=	$(PART3_SRC_PATH)/Phaser.cpp

# PART3_SRC_TEST			=	$(PART3_TST_PATH)/$(NAME_PHASER)_test.cpp
# TEST_NAME_PHASER 		= 	test_$(NAME_PHASER)

###############################################
# PART4_PATH 				= 	./part4_g-squad
# PART4_SRC_PATH			=	./part4_g-squad/src
# PART4_TST_PATH			=	./part4_g-squad/tests
# PART4_INC_PATH			=	./part4_g-squad/include
# NAME_GSQUAD				=	G-Squad
# PART4_SRC				=	$(PART4_SRC_PATH)/Squad.cpp

# PART4_SRC_TEST			=	$(PART4_TST_PATH)/$(NAME_GSQUAD)_test.cpp
# TEST_NAME_GSQUAD		= 	test_$(NAME_GSQUAD)

###############################################

BIN_PATH				=	./bin

NAME					=	Heroes
TEST_NAME 				= 	test_$(NAME)

INCFLAGS				+=	-I $(PART0_INC_PATH)

CPPFLAGS				+= 	-Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS 					= 	$(PART0_SRC) \
							$(BIN_PATH)/main.cpp
# $(PART4_SRC)
							

OBJS					=	$(SRCS:.cpp=.o)
CLEAN					=	clean
FCLEAN					=	fclean

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							$(G++) $(OBJS) $(CPPFLAGS) -o $(NAME)

RM						=	rm -rf

clean					:
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(PART0_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART1_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART2_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART3_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART4_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART5_TST_PATH)


fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART0_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART1_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART2_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART2_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART3_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART3_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART4_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART4_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART5_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART5_PATH)

re						: 	fclean all

part0 					: 	fclean
							@$(MAKE) -C $(PART0_PATH)
							$(PART0_PATH)/$(NAME_PEASANT)

# part1 					: 	fclean
# 							@$(MAKE) -C $(PART1_PATH)
# 							$(PART1_PATH)/$(NAME_KOALABOT)

# part2 					: 	fclean
# 							@$(MAKE) -C $(PART2_PATH)
# 							$(PART2_PATH)/$(NAME_KREOGCOM)

# part3 					: 	fclean
# 							@$(MAKE) -C $(PART3_PATH)
# 							$(PART3_PATH)/$(NAME_PHASER)

# part4 					: 	fclean
# 							@$(MAKE) -C $(PART4_PATH)
# 							$(PART4_PATH)/$(NAME_GSQUAD)

tests_run_part0			:	fclean
							@$(MAKE) -C $(PART0_TST_PATH)
							$(PART0_TST_PATH)/$(TEST_NAME_PEASANT)

# tests_run_part1			:	fclean
# 							@$(MAKE) -C $(PART1_TST_PATH)
# 							$(PART1_TST_PATH)/$(TEST_NAME_KOALABOT)

# tests_run_part2			:	fclean
# 							@$(MAKE) -C $(PART2_TST_PATH)
# 							$(PART2_TST_PATH)/$(TEST_NAME_KREOGCOM)

# tests_run_part3			:	fclean
# 							@$(MAKE) -C $(PART3_TST_PATH)
# 							$(PART3_TST_PATH)/$(TEST_NAME_PHASER)

# tests_run_part4			:	fclean
# 							@$(MAKE) -C $(PART4_TST_PATH)
# 							$(PART4_TST_PATH)/$(TEST_NAME_GSQUAD)

tests_run				:	fclean
							@$(MAKE) tests_run_part0
# @$(MAKE) tests_run_part1
# @$(MAKE) tests_run_part2
# @$(MAKE) tests_run_part3
# @$(MAKE) tests_run_part4


.PHONY					: 	all clean fclean re part0 tests_run_part0 tests_run
