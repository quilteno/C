#include <stdio.h>
#include <string.h>

int main(int argc, const char **argv)
{
    unsigned char c = 0xAA;
    unsigned char b = 0xBB;
    printf("%hhx\n", b^c);

    return 0;
}