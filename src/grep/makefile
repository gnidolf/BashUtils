.SILENT:

CC = gcc -Wall -Wextra -Werror -std=c11
GREP_OBJ = s21_grep.o grep_core.o ../common/parse_input.o
GREP_TARGET = s21_grep

$(GREP_TARGET): $(GREP_OBJ)
	$(CC) $(GREP_OBJ) -o $(GREP_TARGET)

s21_grep.o: s21_grep.c
	$(CC) -c s21_grep.c -o s21_grep.o

grep_core.o: grep_core.c
	$(CC) -c grep_core.c -o grep_core.o

common/parse_input.o: ../common/parse_input.c
	$(CC) -c ../common/parse_input.c -o ../common/parse_input.o

clear:
	rm -f $(GREP_OBJ) $(GREP_TARGET)