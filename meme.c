/* Demonstrate toupper and tolower for 
   standard C strings.
   This does not work for multibyte character sets. */
#include <ctype.h>
#include <stdio.h>

void mock(char *s){

    while(*s){
        *s=toupper(*s);
        s = s + 2;
    }
}

int main(int argc, char *argv[]){
    char t[255];
    scanf("%[^\t\n]",t);
    mock(t);
    printf("%s\n", t);
    return 0;
}