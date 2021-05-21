#ifndef MUL
#define MUL

/* Other Header files */
#include <stdlib.h>

/* Functions */
int _putchar(char c);
char *_calloc(size_t size);
void reset(char **num, size_t size);
void print_error(void);
size_t _strlen(char *str);
void sum(char **a, char *b, size_t size);
char *mul(char *a, char *b);
int main(int argc, char *argv[]);

#endif
