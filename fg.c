#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void calc(float x)
{
    srand(time(NULL));   // Initialization, should only be called once.
    int rando = rand() % 100;
    float odds = 99 * exp(-1 * pow(((17.5 - x) / 50), 2)) - exp((1.65 * x - 78.875) / 8);
    /*char good[];*/
    printf("%f", odds);
    printf("\n");
        printf("%d", rando);
    if (rando < odds)
        printf("KICK IS GOOD!!\n");
    else
        printf("KICK IS NO GOOD!!\n");
};
int main()
{
    float inp;
    printf("DISTANCE: ");
    scanf("%f", &inp);
    if (inp > 17 && inp < 70)
    {
        calc(inp);
    }
    else
    {
        printf("DISTANCE IS INVALID.");
    };
    return 0;
}