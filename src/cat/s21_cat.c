#include "cat_core.h"

int main(int argc, char **argv) {
  char str[MAX_STRING_LENGHT][MAX_CHAR_LENGHT];
  int size = 0;
  struct Flags flg = {0};

  if (!parse_input(argc, argv, &flg, str, &size)) {
    for (int i = 0; i < size; i++) {
      FILE *file = fopen(str[i], "r");
      if (file != NULL) {
        if (flg.e) {
          read_print_ev(file);
        } else if (flg.t) {
          read_print_tv(file);
        } else if (flg.n) {
          read_print_n(file);
        } else if (flg.b) {
          read_print_b(file);
        } else if (flg.E) {
          read_print_e(file);
        } else if (flg.T) {
          read_print_t(file);
        } else if (flg.s) {
          read_print_s(file);
        } else {
          print_file(file);
        }
        fclose(file);
      }
    }
  }
  return 0;
}