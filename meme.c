#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char t[32767];
    read(STDIN_FILENO, t, 32767);
    int i;
    for (i = 0; t[i] != '\0'; i = i + 2)
    {
        if (t[i] >= 'a' && t[i] <= 'z' && t[(i-1)] != '\\')
        {
            t[i] = t[i] - 32;
        }
    }
    printf("%s\n", t);
    return 0;
}