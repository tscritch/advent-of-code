#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// this does not work. Closest I got was 6 off (see below).
// used @jollyjer's solution to find correct answer.
// Last run output:
// Start - Dial = 50
// 1 - Lands on 0: 1191
// 2 - Rot: 5661, Password: 6852

int main(int argc, char *argv[]) {
    printf("-------------\n");


    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "\n🚨 Can't open input file\n\n");

        return 1;
    }

    int zero_count = 0;
    int pt2 = 0;

    int dial = 50;
    char dir;
    int a, b;
    int times_around = 0;

    printf("Start - Dial = 50\n");

    while(fscanf(file, "%c%d\n", &dir, &a) != EOF) {
        times_around = a > 99 ? ((int) (a - dial) / 100) : 0;
        b = a % 100;

        dial += dir == 'R' ? b : -b;

        if (dial < 0) {
            dial += 100;
            if (times_around < 1) pt2++;
        };
        if (dial > 99) {
            dial -= 100;
            if (dial != 0 && times_around < 1) pt2++;
        }

        if (dial == 0) zero_count++;

        pt2 += times_around;
    }

    printf("1 - Lands on 0: %d\n", zero_count);
    printf("2 - Rot: %d, Password: %d\n", pt2, pt2 + zero_count);

    return 0;
}

// correct: 6858
//   zeros = 1191
//   pass  = 5667
//
// tried:
// 7513
// 7285
// 6903
// 7131
// 6852
