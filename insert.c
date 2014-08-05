#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//inserts 'to_insert' into 'str', directly modifying it
//n = len(str)
//m = len(to_insert)
//Overall: O(n+m) time and O(m) space
char *insert(char *str, unsigned int i, const char *to_insert) {
  int full_len = strlen(str);
  int insert_len = strlen(to_insert);
  int new_len = full_len + insert_len;
  //TODO: check for out of bounds
  // abc <-- defg
  //idea:
  //    malloc at the end (O(m) time space)
  //    abc****
  str = realloc(str, new_len);
  int j;
  for (j=full_len; j < new_len; j++) {
    str[j] = '*';
  }
  //    move everything over (O(n) time)
  // abc**bc
  for (j=full_len-1; j>i-1; j--) {
    str[j+insert_len] = str[j];
  }
  //    copy to_insert directly (strcpy)
  char next = str[i+insert_len];
  strcpy(&str[i], to_insert);
  str[i+insert_len] = next;
  return str;
}
