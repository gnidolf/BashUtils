#define _GNU_SOURCE
#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGHT 100
#define MAX_CHAR_LENGHT 256

struct Flags {
  int b;
  int e;
  int E;
  int n;
  int s;
  int t;
  int T;
  int v;
  int i;
  int c;
  int l;
  char *pattern;
};

int parse_input(int argc, char **argv, struct Flags *flg,
                char str[][MAX_CHAR_LENGHT], int *size);