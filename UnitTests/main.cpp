#include <stdio.h>

int main(int argc, char *argv[])
{
    puts("main");
    for (int x = 0; x < 10; x++)
	    printf("%d\n", x);
    puts("main fin");
    return 0;
}
