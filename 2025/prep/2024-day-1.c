#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void substring(char *buffer, char *out, int start, int end) {
    for(int i=start; i<=end; i++) {
        out[i-start] = buffer[i];
    }
}

void printl_int(int *list) {
    for(int i=0; i<1000; i++) {
        printf("%d\n", list[i]);
    }
}
void printl_char(char *list) {
    for(int i=0; i<1000; i++) {
        printf("%d\n", list[i]);
    }
}

int int_comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) {
    printf("-------------\n");


    FILE* file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "\n🚨 Can't open input file\n\n");

        return 1;
    }

    int distance = 0;

    char lb[16];
    char numb[5];

    int llist[1000];
    int rlist[1000];
    int line = 0;

    while(fgets(lb, 16, file) != NULL) {
        // printf("%s", lb);
        // get substring
        //
        substring(lb, numb, 0, 4);
        llist[line] = atoi(numb);
        substring(lb, numb, 8, 12);
        rlist[line] = atoi(numb);

        line++;
    }

    qsort(llist, 1000, sizeof(int), int_comp);
    qsort(rlist, 1000, sizeof(int), int_comp);

    for (int i=0; i<1000; i++) {
        distance += abs(llist[i] - rlist[i]);
    }

    printf("Distance: %d\n", distance);

    return 0;
}
