#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "split.h"

char *join(SplitObj array, char *joinstr)
{
    int alen = array -> len;
    int endlen = 0; //total length of the return string
    int joinlen = strlen(joinstr);
    /* 12.34.45 */
    int i;
    for (i=0; i < alen; i++) {
        endlen += strlen((array -> splits)[i]);
    }
    endlen += (alen - 1) * joinlen;
    char *joined_str = malloc(endlen);
    int offset = 0;
    for (i=0; i < alen; i++) {
        strcpy(joined_str + offset, (array -> splits)[i]);
        offset += strlen((array -> splits)[i]);
        if ((i+1) != alen) {
            strcpy(joined_str + offset, joinstr);
            offset += joinlen;
        }
    }
    return joined_str;
}
