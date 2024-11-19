#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char *wnote = (char *)malloc(32);
    if (argc == 1)
        exit(1);
    printf("The input has size %ld\n", strlen(argv[1]));
    printf("wnote starts at %p and ends at %p\n", wnote, wnote + 31);
    sprintf(wnote, "Welcome to %s", argv[1]);
    printf("%s\n", wnote);
    free(wnote);
    exit(0);
}