# ===== Основные настройки =====
TARGET = lib_math
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
TEST_LIBS = -lcheck -lm -lpthread -lsubunit
LIB_DIR = -L/usr/local/lib
INC_DIR = -I/usr/local/include
COV_FLAGS = --coverage
RM = rm -rf
SRC_DIR = lib
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:.c=.o)
HEAD = lib_math.h

# ===== Цели сборки =====
.PHONY: all clean test rebuild gcov_report

all: $(TARGET).a

$(TARGET).a: $(OBJ)
	ar rcs $(TARGET).a $(OBJ)
	ranlib $(TARGET).a

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@

# ===== Тестирование =====
test: $(TARGET).a
	$(CC) $(CFLAGS) tests.c $(TARGET).a -o $(TARGET)_test $(LIB_DIR) $(INC_DIR) $(TEST_LIBS)
	./$(TARGET)_test

# ===== Покрытие кода =====
gcov_report: clean
	$(CC) $(CFLAGS) $(COV_FLAGS) $(SRC) tests.c -o $(TARGET)_gcov $(LIB_DIR) $(INC_DIR) $(TEST_LIBS)
	./$(TARGET)_gcov
	lcov -t "$(TARGET)" -o $(TARGET).info -c -d .
	genhtml -o report $(TARGET).info
	open report/index.html

# ===== Очистка =====
clean:
	$(RM) $(OBJ) $(TARGET).a $(TARGET)_test $(TARGET)_gcov
	$(RM) *.gcda *.gcno *.info *.gcov
	$(RM) -r report
	$(RM) -r *.dSYM

rebuild: clean all