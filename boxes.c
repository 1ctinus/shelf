#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  int inp = strtol(argv[1], NULL, 0);
  for (int i = 0; i < (inp); i++){
    if(2*i < inp){
      for (int j = 0; j < i; j++){
        printf("│ ");
      }
      printf("┌");
      for (int j = 2*(-inp+2); j < -4*i; j++){
        printf("─");
      }
      printf("┐");
      for (int j = 0; j < i; j++){
        printf(" │");
      }
      putchar('\n');
    } else {
      for (int j = i - inp+1; j < 0; j++){
        printf("│ ");
      }
      printf("└");
      for (int j = 0; j < 2*(2*i-inp);j++){
        printf("─");
      }
      printf("┘");
      for (int j = i - inp+1; j < 0; j++){
        printf(" │");
      }
      putchar('\n');
    }
  }
  //return 0;
}
