#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arreglo[], int ini, int fin);
int particion(int arreglo[], int ini, int fin);
void intercambio(int *a, int *b);

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
    for(i = 0; i < n; i++)
    {
        printf("%d ", arreglo[i]);
    }

    quickSort(arreglo, 0, n-1);

    printf("\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arreglo[i]);
    }


    return 0;
}

void quickSort(int arreglo[], int ini, int fin)
{
    int pivote;
    if(ini < fin)
    {
        pivote = particion(arreglo, ini, fin);
        quickSort(arreglo, ini, pivote - 1);
        quickSort(arreglo, pivote + 1, fin);
    }
}

int particion(int arreglo[], int ini, int fin)
{
    int pivote, i, indice;

    pivote = (ini + fin) / 2;
    intercambio(&arreglo[pivote], &arreglo[fin]);
    indice = ini;
    for(i = ini; i < fin; i++)
    {
        if(arreglo[i] < arreglo[fin])
        {
            intercambio(&arreglo[i], &arreglo[indice]);
            indice++;
        }
    }
    intercambio(&arreglo[indice],&arreglo[fin]);

    return(indice);

}

void intercambio(int *a, int *b)
{
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
