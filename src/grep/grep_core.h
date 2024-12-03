#include "../common/common.h"

void print_grep_file(FILE *file, struct Flags *flg);

void print_grep_file_e(FILE *file, struct Flags *flg);

void print_grep_file_v(FILE *file, struct Flags *flg);

void print_grep_file_i(FILE *file, struct Flags *flg);

void print_grep_file_c(FILE *file, struct Flags *flg);

void print_grep_file_l(FILE *file, struct Flags *flg,
                       char str[][MAX_CHAR_LENGHT], int num);

void print_grep_file_n(FILE *file, struct Flags *flg);