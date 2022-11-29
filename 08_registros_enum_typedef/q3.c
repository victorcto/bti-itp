#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 300

typedef struct {
    int signal;
    int exp;
    int integer;
    int fractional;
} BigFloat;

typedef struct {
    int integer;
    int fractional;
} array;



int main(){
    char line[MAX_LINE];
    readline(line);
    BigFloat bf = strToBigFloat(line);
    printBigFloat(bf);
    printf("%i %u %u %u\n",
        bf.signal,
        bf.exp,
        bf.integer.array[bf.integer.size - 1],
        bf.fractional.array[bf.fractional.size - 1]
    );

    return 0;
}