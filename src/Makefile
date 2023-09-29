.PHONY: all clean test s21_matrix_oop.a  gcov_report main
OS :=$(shell uname -s)
NAME :=$(shell whoami)
CC=gcc
FLAGS:=-lstdc++ -std=c++17 -Wall -Wextra -Werror -g
LIB:=s21_matrix_oop
PATH_TO_OBJ=ObjectFiles
TEST:=Tests/test
GCOV:=--coverage
SANI:=-fsanitize=address -g
#  цвета
BLUE:=\033[96m
RED:=\033[91m
END:=\033[0m

ifeq ($(OS), Darwin)
	FLAGS_PLATFORM =-lgtest --coverage
else
	FLAGS_PLATFORM =-lgtest -lrt -lm -lpthread --coverage
endif

all : main

clean :
	@echo "$(BLUE)------------------CLEAN------------------$(END)"
	@rm -rf report test.info gcov f test main *.a *.o *.g* */*.o */*.a */*/*.o *.g* */*.g* */*/*.g*
	
# *.{a,o,dSYM,out,g*} 
# ls -la *

test : clean $(LIB).a $(TEST).o
	@echo "$(BLUE)--------------RUNNING TESTS--------------$(END)"
	@$(CC) $(PATH_TO_OBJ)/$(TEST).o -L. $(PATH_TO_OBJ)/$(LIB).a -o test $(FLAGS_PLATFORM) $(FLAGS)
	@./test
	@echo "$(BLUE)-----------------------------------------$(END)"

$(TEST).o : $(TEST).cc
	@$(CC) $(FLAGS) -c $(TEST).cc -o $(PATH_TO_OBJ)/$@

# библиотека для теста
$(LIB).a : $(LIB).cc
	@echo "$(BLUE)--------------MATRIX LIBRARY-------------$(END)"
	@$(CC) -g -c $^ -o $(PATH_TO_OBJ)/$(LIB).o $(FLAGS_PLATFORM)
	@ar rc $(PATH_TO_OBJ)/$@ $(PATH_TO_OBJ)/$(LIB).o
	@ranlib $(PATH_TO_OBJ)/$@

#gcov
gcov_report : clean $(TEST).o $(LIB).a
	@echo "$(BLUE)---------------GCOV REPORT---------------$(END)"
	@echo $(FLAGS_PLATFORM)
	@$(CC) $(PATH_TO_OBJ)/$(TEST).o -L. $(PATH_TO_OBJ)/$(LIB).a -o gcov $(FLAGS_PLATFORM) $(FLAGS)
	@./gcov 
	@gcov $(LIB).c
	@lcov -t "test" -o test.info -c -d . 
	@genhtml -o report test.info 
	@open report/index.html 
	@echo "$(BLUE)-----------------------------------------$(END)"

# библиотека для отчета
g$(LIB).a : $(LIB).cc
	@echo "$(BLUE)--------------MATRIX LIBRARY-------------$(END)"
	@$(CC) -g -c $^ -o $(PATH_TO_OBJ)/$(LIB).o
	@ar rc $(PATH_TO_OBJ)/$@ $(PATH_TO_OBJ)/$(LIB).o
	@ranlib $(PATH_TO_OBJ)/$@

valgrind: clean test
	@echo "$(BLUE)----------------VALGRIND-----------------$(END)"
	@CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=valgrind.txt ./test
	@echo "$(BLUE)-----------------------------------------$(END)"

check: 
	@echo "$(BLUE)------------------CHECK------------------$(END)"
	@cp ../materials/linters/.clang-format .clang-format && cp ../materials/linters/.clang-format ../tests/.clang-format
#	@clang-format -style=Google -i *.h *.c ../tests/*.c
	@clang-format -style=Google -n *.h *.c ../tests/*.c
	@rm .clang-format && rm ../tests/.clang-format
	@echo "$(BLUE)-----------------------------------------$(END)"

main: clean main.o $(LIB).a
	@$(CC) $(PATH_TO_OBJ)/main.o -L. $(PATH_TO_OBJ)/$(LIB).a -o main $(FLAGS) $(FLAGS_PLATFORM) 
	@./main
main.o: main.cc
	@$(CC) -c $^ -o $(PATH_TO_OBJ)/$@ $(FLAGS) $(FLAGS_PLATFORM) 

