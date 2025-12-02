#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void substring(char *buffer, char *out, int start, int end) {
  for (int i = start; i <= end; i++) {
    out[i - start] = buffer[i];
  }
}

void printl_int(long *list, int len) {
  for (int i = 0; i < len; i++) {
    printf("%ld\n", list[i]);
  }
}


int invalid1(long num) {
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

int invalid2(long num) {
  if (num < 10)
    return 0;

  static char s[20];
  static int len;
  sprintf(s, "%ld", num);
  len = strlen(s);

  // just return faster if 2 digit num
  if (len == 2 && s[0] == s[1]) return 1;

  if (len % 2 == 1 && len < 8) {
      char f = s[0];
      for (int i = 1; i < len; i++) {
          if (f != s[i]) return 0;
      }
      return 1;
  }

  int mid = (int)len / 2;

  char sub[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};

  // w for width of check
  for (int w=1; w < mid; w++) {
    if (len % (w+1) != 0) continue;
    substring(s, sub, 0, w);

    int eq = 1;
    char com[12] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
    for (int i = w+1; i < len; i+=w+1) {
        substring(s, com, i, w+i);
        if (strcmp(com, "") == 0 || strlen(com) < w+1) break;

        if (strcmp(sub, com) == 0) {
            continue;
        }

        eq = 0;
        break;
    }

    if (eq) return 1;
  }


  return 0;
}

int main(int argc, char *argv[]) {
  printf("-------------\n");

  FILE *file = fopen(argv[1], "r");

  if (file == NULL) {
    fprintf(stderr, "\n🚨 Can't open input file\n\n");

    return 1;
  }

  long l, r;

  long invalid[10000];
  int cn_idx = 0;

  // initialize array because I was getting random numbers!
  for(int i=0; i<1000; i++) invalid[i] = 0;

  while (fscanf(file, "%ld-%ld\n", &l, &r) != EOF) {
    for (long i = l; i <= r; i++) {
      if (invalid2(i) == 1) {
        invalid[cn_idx] = i;
        cn_idx++;
      }
    }
  }

  // printl_int(invalid, cn_idx);

  long long sum = 0;
  for (int i = 0; i < cn_idx; i++) {
    sum += invalid[i];
  }

  printf("Answer: %lld\n", sum);

  return 0;
}

// tried 6039066582
// 46503113174 - too high
//
// Part 1 Answer: 40398804950
// Part 2 Answer: 65794984339
