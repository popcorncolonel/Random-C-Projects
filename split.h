typedef struct {
    int len;
    char **splits;
} *SplitObj;

SplitObj split(char *superstr, char *substr);
int countOccurrences(char *superstr, char *substr);

char *join(SplitObj array, char *joinstr);

char *replace(char *str, char *old, char *new);

