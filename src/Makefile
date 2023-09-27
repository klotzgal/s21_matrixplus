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
	FLAGS_PLATFORM =-lgtest
else
	FLAGS_PLATFORM =-lgtest -lrt -lm -lpthread
endif

all : main

clean :
	@echo "$(BLUE)------------------CLEAN------------------$(END)"
	@rm -rf report test.info gcov f test main *.a *.o  */*.o */*.a */*/*.o # *.{a,o,dSYM,out,g*} 
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
	@$(CC) -g -c $^ -o $(PATH_TO_OBJ)/$(LIB).o
	@ar rc $(PATH_TO_OBJ)/$@ $(PATH_TO_OBJ)/$(LIB).o
	@ranlib $(PATH_TO_OBJ)/$@

#gcov
gcov_report : clean lcov $(TEST).o gs21_matrix_oop.a
	@echo "$(BLUE)---------------GCOV REPORT---------------$(END)"
	@$(CC) $(FLAGS) $(GCOV) $(TEST).o -l check -L. s21_matrix_oop.a $(FLAGS_PLATFORM) -o gcov
	@./gcov gs21_matrix_oop.a 
	@gcov gs21_matrix_oop.a
# ~/goinfre/homebrew/bin/
	@lcov -t "test" -o test.info -c -d . 
	@genhtml -o report test.info 
	@open report/index.html 
	@echo "$(BLUE)-----------------------------------------$(END)"

# библиотека для отчета
gs21_matrix_oop.a : libs/list_lib.c libs/calc.c
	@echo "$(BLUE)--------------MATRIX LIBRARY-------------$(END)"
	@$(CC) $(GCOV) -g -c libs/list_lib.c libs/calc.c
	@ar rc s21_matrix_oop.a list_lib.o calc.o
	@ranlib s21_matrix_oop.a

# проверки lcov и brew
lcov:
ifeq ("", "$(wildcard ~/goinfre/homebrew/bin/lcov)")
	$(error Need to install lcov: make lcov_install)
endif

lcov_install :  brew
	@brew install lcov

brew:
ifeq ("", "$(wildcard ~/goinfre/homebrew)")
	@git clone https://github.com/Homebrew/brew ~/goinfre/homebrew
	@echo "$(RED)Выполните eval \"\$$(/opt/goinfre/*/homebrew/bin/brew shellenv)\"$(END)"
#   curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
endif

valgrind: clean f
	@echo "$(BLUE)----------------VALGRIND-----------------$(END)"
	@CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=valgrind.txt ./f
	@echo "$(BLUE)-----------------------------------------$(END)"

check: 
	@echo "$(BLUE)------------------CHECK------------------$(END)"
	@cp ../materials/linters/.clang-format .clang-format && cp ../materials/linters/.clang-format ../tests/.clang-format
#	@clang-format -style=Google -i *.h *.c ../tests/*.c
	@clang-format -style=Google -n *.h *.c ../tests/*.c
	@rm .clang-format && rm ../tests/.clang-format
	@echo "$(BLUE)-----------------------------------------$(END)"

main: main.o $(LIB).a
	@$(CC) $(PATH_TO_OBJ)/main.o -L. $(PATH_TO_OBJ)/$(LIB).a -o main $(FLAGS) 
	@./main
main.o: main.cc
	@$(CC) -c $^ -o $(PATH_TO_OBJ)/$@ $(FLAGS)

