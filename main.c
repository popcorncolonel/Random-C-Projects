#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "split.h"

int main(int argc, char *argv[]) 
{
    SplitObj array;
    if (argc == 3) {
        char *str = argv[1];
        array = split(str, argv[2]);
    }
    else {
        fprintf(stderr, "Usage: split <superstring> <substring>\n");
        return 1;
    }
    int i;
    for (i=0; i < array -> len; i++) {
        printf("split[%d] = \"%s\"\n", i, array -> splits[i]);
    }
    printf("%s\n", join(array, ":-)"));
    printf("%s\n", replace(argv[1], argv[2], "__"));
    printf("%s\n", insert(strcpy(malloc(strlen(argv[1])), argv[1]), 1, "_hello_"));
    if (array -> len != 1) {
        free(array -> splits[0]);
    }
    free(array -> splits);
    free(array);
    return 0;
}


