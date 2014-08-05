#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "split.h"

SplitObj split(char *superstr, char *substr) 
{
    int superlen = strlen(superstr), sublen = strlen(substr);
    SplitObj to_return = malloc(sizeof(*to_return));
    char *destroy_string = malloc(sizeof(char *) * superlen); //string that will be destroyed, same original contents as superstring though
    strcpy(destroy_string, superstr);
    if (superlen < sublen) {
        to_return -> len = 1;
        to_return -> splits = &destroy_string;
        return to_return;
    }
    int occurrences = countOccurrences(superstr, substr); 
    int next_index_start = 0; //where the next string to be made starts
    to_return -> len = occurrences+1;
    to_return -> splits = malloc(sizeof(char *) * to_return -> len);
    int i;
    int count = 0;
    for (i = 0; i < superlen - sublen + 1; i++) {
        //if the substring is found at offset i
        if (strncmp(destroy_string + i, substr, sublen) == 0) {
            to_return -> splits[count++] = destroy_string + next_index_start;
            destroy_string[i] = '\0';
            i += sublen - 1;
            next_index_start = i+1;
        }
    }
    if (count == (to_return -> len) - 1) {
        to_return -> splits[count++] = destroy_string + next_index_start;
    }
    return to_return;
}

//counts the number of times substr occurs in superstr
int countOccurrences(char *superstr, char *substr) 
{
    int i, count = 0;
    int superlen = strlen(superstr), sublen = strlen(substr);
    for (i = 0; i < superlen - sublen + 1; i++) {
        if (strncmp(superstr + i, substr, sublen) == 0) {
            count++;
            i += sublen;
            i -= 1; //offset the i++
        }
    }
    return count;
}

