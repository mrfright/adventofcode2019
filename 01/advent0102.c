
//for getline
#define _GNU_SOURCE
#include <stdio.h>

#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[]){
    if(argc <= 1) {
        printf("need filename to open\n");
        exit(EXIT_FAILURE);
    }
    
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("couldn't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    ssize_t read;
    char *line = NULL;
    size_t len = 0;
    long sum = 0;
    while((read = getline(&line, &len, fp)) != -1) {
        char *end;
        long i = strtol(line, &end, 10) /3 - 2;

        while(i > 0) {
            sum += i;
            i = i / 3 -2;
        } 
    }
    printf("%ld\n", sum);
}
        
