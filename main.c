#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args(char * line) {
    char ** res = malloc(sizeof(char *) * 5);
    char *curr = line;
    int counter = 0;

    while(curr) {
        res[counter] = strsep(&curr, " ");
        counter++;
    }

    return res;
}


int main() {
    char line[200] = "ls -a -l";
    printf("testing: %s\n", line);
    char ** args = parse_args(line);
    execvp(args[0], args);
    return 0;
}