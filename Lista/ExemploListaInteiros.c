#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "Utils.h"
#include "Lista.h"

int main()
{
    pDLista pListaInt = createList();

    int *pi = allocateInt(5);

    /* teste de inclusao */
    addInfoOrdered(pListaInt, pi, compareInt);
    addInfoOrdered(pListaInt, allocateInt(3), compareInt);
    addInfoOrdered(pListaInt, allocateInt(9), compareInt);
    addInfoOrdered(pListaInt, allocateInt(1), compareInt);
    addInfoOrdered(pListaInt, allocateInt(2), compareInt);
    printf("\nResultado da inclusao \n");
    printList(pListaInt, printInt);
}
