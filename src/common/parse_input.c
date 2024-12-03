#include "common.h"

int parse_input(int argc, char **argv, struct Flags *flg,
                char str[][MAX_CHAR_LENGHT], int *size) {
  int err = 0;
  static struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                         {"number", 0, 0, 'n'},
                                         {"squeeze-blank", 0, 0, 's'}};
  int result = 0;
  while ((result = getopt_long(argc, argv, "be::n::sti::v::c::l::TE",
                               long_options, NULL)) != -1) {
    switch (result) {
      case 'b':
        flg->b = 1;
        break;
      case 'e':
        flg->e = 1;
        flg->pattern = argv[optind];
        break;
      case 'n':
        flg->n = 1;
        flg->pattern = argv[optind];
        break;
      case 's':
        flg->s = 1;
        break;
      case 't':
        flg->t = 1;
        break;
      case 'v':
        flg->pattern = argv[optind];
        flg->v = 1;
        break;
      case 'c':
        flg->pattern = argv[optind];
        flg->c = 1;
        break;
      case 'i':
        flg->pattern = argv[optind];
        flg->i = 1;
        break;
      case 'l':
        flg->pattern = argv[optind];
        flg->l = 1;
        break;
      case 'T':
        flg->T = 1;
        break;
      case 'E':
        flg->E = 1;
        break;
      default:
        err = 1;
        break;
    }
  }
  if (!flg->pattern) {
    flg->pattern = argv[1];
  }
  if (optind != argc) {
    while (optind < argc) {
      strcpy(str[*size], argv[optind++]);
      *size += 1;
    }
  } else {
    err = 1;
  }
  return err;
}