#include "cat_core.h"

void read_print_ev(FILE *file) {
  char c;
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n') {
      printf("$\n");
    } else if (c == '\t') {
      printf("\t");
    } else if (c == 127) {
      printf("^?");
    } else if (c == 32) {
      printf(" ");
    } else if (c >= 0 && c <= 31) {
      printf("^%c", c + 64);
    } else {
      printf("%c", c);
    }
  }
}

void read_print_e(FILE *file) {
  char c;
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n') {
      printf("$\n");
    } else {
      printf("%c", c);
    }
  }
}

void read_print_t(FILE *file) {
  char c;
  while ((c = fgetc(file)) != EOF) {
    if (c == '\t') {
      printf("^I");
    } else {
      printf("%c", c);
    }
  }
}

void read_print_tv(FILE *file) {
  char c;
  while ((c = fgetc(file)) != EOF) {
    if (c == '\t') {
      printf("^I");
    } else if (c == '\n') {
      printf("\n");
    } else if (c == 127) {
      printf("^?");
    } else if (c >= 0 && c <= 31) {
      printf("^%c", c + 64);
    } else {
      printf("%c", c);
    }
  }
}

void read_print_n(FILE *file) {
  char c;
  int i = 1;
  printf("%6d\t", i++);
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n') {
      printf("\n%6d\t", i++);
    } else {
      printf("%c", c);
    }
  }
}

void read_print_b(FILE *file) {
  char timed_buf[MAX_CHAR_LENGHT];
  int i = 1;
  while (fgets(timed_buf, sizeof(timed_buf), file)) {
    if (timed_buf[0] == '\n') {
      printf("\n");
    } else {
      printf("%6d\t%s", i++, timed_buf);
    }
  }
}

void read_print_s(FILE *file) {
  char timed_buf[MAX_CHAR_LENGHT];
  int is_empty = 0;

  while (fgets(timed_buf, sizeof(timed_buf), file)) {
    if (timed_buf[0] == '\n') {
      if (!is_empty) {
        printf("\n");
        is_empty = 1;
      }
    } else {
      printf("%s", timed_buf);
      is_empty = 0;
    }
  }
}

void print_file(FILE *file) {
  char c;
  while ((c = fgetc(file)) != EOF) {
    printf("%c", c);
  }
}