#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "split.h"

char *replace(char *str, char *old, char *new)
{
    return join(split(str, old), new);
}

//we can just combine split and join, right?
