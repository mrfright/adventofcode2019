#include <stdio.h>
int main(){
    FILE *fp = fopen("testfile", "r");
    if(fp == NULL) {
        printf("couldn't open testfile\n");
        exit(EXIT_FAILURE);
    }

    ssize_t read;
    char *line = NULL;
    size_t len = 0;
    while((read = getline(&line, &len, fp)) != -1) {
        
    }    
}
        
