#include "grep_core.h"

void print_grep_file(FILE *file, struct Flags *flg) {
  char buf[MAX_CHAR_LENGHT];
  regex_t regex;

  regcomp(&regex, flg->pattern, 0);
  while (fgets(buf, sizeof(buf), file)) {
    if (!regexec(&regex, buf, 0, NULL, 0)) {
      printf("%s", buf);
      if (feof(file)) {
        printf("\n");
      }
    }
  }
  regfree(&regex);
}

void print_grep_file_e(FILE *file, struct Flags *flg) {
  char buf[MAX_CHAR_LENGHT];
  regex_t regex;

  regcomp(&regex, flg->pattern, REG_EXTENDED);
  while (fgets(buf, sizeof(buf), file)) {
    if (!regexec(&regex, buf, 0, NULL, 0)) {
      printf("%s", buf);
      if (feof(file)) {
        printf("\n");
      }
    }
  }
  regfree(&regex);
}

void print_grep_file_v(FILE *file, struct Flags *flg) {
  char buf[MAX_CHAR_LENGHT];
  regex_t regex;

  regcomp(&regex, flg->pattern, REG_EXTENDED);
  while (fgets(buf, sizeof(buf), file)) {
    if (regexec(&regex, buf, 0, NULL, 0)) {
      printf("%s", buf);
      if (feof(file)) {
        printf("\n");
      }
    }
  }
  regfree(&regex);
}

void print_grep_file_i(FILE *file, struct Flags *flg) {
  char buf[MAX_CHAR_LENGHT];
  regex_t regex;

  regcomp(&regex, flg->pattern, REG_ICASE);
  while (fgets(buf, sizeof(buf), file)) {
    if (!regexec(&regex, buf, 0, NULL, 0)) {
      printf("%s", buf);
      if (feof(file)) {
        printf("\n");
      }
    }
  }
  regfree(&regex);
}

void print_grep_file_c(FILE *file, struct Flags *flg) {
  char buf[MAX_CHAR_LENGHT];
  regex_t regex;
  int count = 0;

  regcomp(&regex, flg->pattern, REG_EXTENDED);
  while (fgets(buf, sizeof(buf), file)) {
    if (!regexec(&regex, buf, 0, NULL, 0)) {
      count++;
    }
  }
  printf("%d\n", count);
  regfree(&regex);
}

void print_grep_file_l(FILE *file, struct Flags *flg,
                       char str[][MAX_CHAR_LENGHT], int num) {
  char buf[MAX_CHAR_LENGHT];
  regex_t regex;
  int f = 0;

  regcomp(&regex, flg->pattern, REG_EXTENDED);
  while (fgets(buf, sizeof(buf), file)) {
    if (!regexec(&regex, buf, 0, NULL, 0)) {
      f = 1;
    }
  }
  if (f) {
    printf("%s\n", str[num]);
  }
  regfree(&regex);
}

void print_grep_file_n(FILE *file, struct Flags *flg) {
  char buf[MAX_CHAR_LENGHT];
  regex_t regex;
  int count = 1;

  regcomp(&regex, flg->pattern, REG_EXTENDED);
  while (fgets(buf, sizeof(buf), file)) {
    if (!regexec(&regex, buf, 0, NULL, 0)) {
      printf("%d:%s", count, buf);
      if (feof(file)) {
        printf("\n");
      }
    }
    count++;
  }
  regfree(&regex);
}