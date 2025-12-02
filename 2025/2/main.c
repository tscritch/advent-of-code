#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(char *buffer, char *out, int start, int end) {
  for (int i = start; i <= end; i++) {
    out[i - start] = buffer[i];
  }
}

void printl_int(int *list, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d\n", list[i]);
  }
}
void printl_char(char *list) {
  for (int i = 0; i < 1000; i++) {
    printf("%d\n", list[i]);
  }
}

int int_comp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int is_cool(long num) {
  if (num < 10)
    return 0;

  static char s[20];
  static int len;
  sprintf(s, "%ld", num);
  len = strlen(s);

  if (len % 2 == 1)
    return 0;

  int mid = (int)len / 2;
  for (int i = 0; i < mid; i++) {
    if (s[i] != s[mid + i])
      return 0;
  }

  return 1;
}

int main(int argc, char *argv[]) {
  printf("-------------\n");

  FILE *file = fopen(argv[1], "r");

  if (file == NULL) {
    fprintf(stderr, "\n🚨 Can't open input file\n\n");

    return 1;
  }

  long l, r;

  int cool_num[1000];
  int cn_idx = 0;

  while (fscanf(file, "%ld-%ld\n", &l, &r) != EOF) {
    printf("Group: %ld-%ld\n", l, r);
    for (long i = l; i <= r; i++) {
      if (is_cool(i) == 1) {
        printf("%ld\n", i);
        cool_num[cn_idx] = i;
        cn_idx++;
      }
    }
  }

  printl_int(cool_num, cn_idx);

  long sum = 0;
  for (int i = 0; i <= cn_idx; i++) {
    sum += cool_num[i];
  }

  printf("Answer: %ld\n", sum);

  //   printf("Is cool: %d\n", is_cool(1010));
  //   printf("Is cool: %d\n", is_cool(123123));
  //   printf("Is cool: %d\n", is_cool(1188511885));
  //   printf("NOT cool: %d\n", is_cool(118851188));
  //   printf("NOT cool: %d\n", is_cool(1188511886));
  //   printf("NOT cool: %d\n", is_cool(12));

  return 0;
}

// tried 6039066582