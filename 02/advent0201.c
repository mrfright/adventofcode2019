
//for getline
#define _GNU_SOURCE
#include <stdio.h>

#include <string.h>

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
    long ops[10000] = {};
    while((read = getline(&line, &len, fp)) != -1) {
        char *token = strtok(line, ",");
        int index = 0;
        while(token) {
            //got an op
            char *end;
            ops[index] = strtol(token, &end, 10);
            token = strtok(NULL, ",");
        }

        for(int current = 0; current < index;) {
            switch(ops[current]) {
                case 1: { //addition
                    ops[ops[current+3]] = ops[ops[current+1]] + ops[ops[current+2]];
                } break;
                case 2: { //multiplication
                    ops[ops[current+3]] = ops[ops[current+1]] * ops[ops[current+2]];
                } break;
                case 99: { //done
                    current = index;
                } break;
                default: { // error
                    current = index;
                } break;
            }
            current += 4;
        }
    }
    printf("%ld\n", sum);
}
        
