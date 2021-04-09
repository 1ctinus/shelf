#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char t[32767];
    unsigned int val = 0;
    if( argc == 2){
	    memset(t, '\0', sizeof(t));
   strcpy(t, argv[1]);
    } else {
    read(STDIN_FILENO, t, 32767);
    }
    for(int i = 0; t[i]; i++){
  t[i] = tolower(t[i]);
}
 int i;
    for (i = 0; t[i] != '\0'; i++)
    {
	switch(t[i]){
		case 'a':case'e':case'i':case'o':case'u':case'l':case'n':case's':case't':case'r':
		val +=1;
		break; case 'd':case'g':
		val +=2;
		break; case 'b': case 'c': case 'm': case 'p':
		val +=3;
		break; case 'f':case 'h':case 'v': case 'w':case 'y':
		val +=4;
		break; case 'k':
		val +=5;
		break; case 'j':case 'x':
		val +=8;
		break; case 'q':case 'z':
		val += 10;
	}
        // if (t[i] == 'a' || t[i] == 'b')
        // {
            //  val += 1;
	//}
    }
    printf("%i\n", val);
    return 0;
}

