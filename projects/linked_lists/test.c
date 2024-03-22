#include <stdio.h>

int main()
{
    char name[20];
    char *test = "Q";


    int rtn = strcmp(name, test);

    printf("The return value was: %d\n", rtn);

    printf("%d\n", strlen(name));
    return 0;
}