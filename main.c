#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *fp = fopen("arreglo.in", "r");
    time_t t;
    int n,i;

    srand((unsigned) time(&t));

    fscanf(fp,"%d", &n);

    int arreglo[n];

    for(i = 0; i < n; i++)
    {
        arreglo[i] = rand() % 100;
    }

    return 0;
}
