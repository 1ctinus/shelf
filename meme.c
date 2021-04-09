#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char t[32767];
        if( argc == 2){
	    memset(t, '\0', sizeof(t));
   strcpy(t, argv[1]);
    } else {
    read(STDIN_FILENO, t, 32767);
    }
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
