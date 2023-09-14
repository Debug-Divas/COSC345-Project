#include <stdio.h>

int another(int param)
{
puts("Something");
if (param == 0)
	puts("Zero");
else
	puts("non Zero");

return 0;
}

int main(int argc, char *argv[])
{
    puts("main");
    for (int x = 0; x < 10; x++)
	    printf("%d\n", x);
    another(0);
    puts("main fin");
    return 0;
}
