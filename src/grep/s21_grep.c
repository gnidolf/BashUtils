#include "grep_core.h"

int main(int argc, char **argv) {
  char str[MAX_STRING_LENGHT][MAX_CHAR_LENGHT];
  int size = 0;
  struct Flags flg = {0};

  if (!parse_input(argc, argv, &flg, str, &size)) {
    for (int i = 0; i < size; i++) {
      FILE *file = fopen(str[i], "r");
      if (file != NULL) {
        if (flg.e) {
          print_grep_file_e(file, &flg);
        } else if (flg.v) {
          print_grep_file_v(file, &flg);
        } else if (flg.i) {
          print_grep_file_i(file, &flg);
        } else if (flg.c) {
          print_grep_file_c(file, &flg);
        } else if (flg.l) {
          print_grep_file_l(file, &flg, str, i);
        } else if (flg.n) {
          print_grep_file_n(file, &flg);
        } else {
          print_grep_file(file, &flg);
        }
        fclose(file);
      }
    }
  }
  return 0;
}