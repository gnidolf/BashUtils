.SILENT:

CC = gcc -Wall -Wextra -Werror -std=c11
CAT_OBJ = s21_cat.o cat_core.o ../common/parse_input.o
CAT_TARGET = s21_cat

$(CAT_TARGET): $(CAT_OBJ)
	$(CC) $(CAT_OBJ) -o $(CAT_TARGET)

s21_cat.o: s21_cat.c
	$(CC) -c s21_cat.c -o s21_cat.o

cat_core.o: cat_core.c
	$(CC) -c cat_core.c -o cat_core.o

common/parse_input.o: ../common/parse_input.o
	$(CC) -c ../common/parse_input.o -o ../common/parse_input.o

clear:
	rm -f $(CAT_OBJ) $(CAT_TARGET)