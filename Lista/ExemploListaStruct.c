#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "Lista.h"

int main()
{
    pDLista pListaData = createList();

    /* teste de inclusao */
    addInfo(pListaData, allocateDate(05, 03, 2007));
    addInfo(pListaData, allocateDate(12, 05, 2012));
    addInfo(pListaData, allocateDate(10, 8, 2006));
    addInfo(pListaData, allocateDate(01, 12, 2015));
    addInfo(pListaData, allocateDate(23, 9, 2020));
    addInfo(pListaData, allocateDate(18, 04, 2003));
    printf("\nResultado da inclusao \n");
    printList(pListaData, printDate);

    /* teste de exclusao */
    removeInfo(pListaData, allocateDate(18, 04, 2003), compareDate);
    printf("\nResultado da exclusao \n");
    printList(pListaData, printDate);

    /* teste de busca */
    int result = containsInfo(pListaData, allocateDate(18, 04, 2003), compareDate);
    printf("\nResultado da busca: 0-[Nao encontrou], 1-[ok] -> %d\n", result);

    /* teste de duplicacao de lista */
    pDLista copia = duplicateList(pListaData, allocateDateInfo);
    printf("\nResultado da duplicacao \n");
    printList(copia, printDate);

    /* teste de divisao de lista */
    pDLista novaLista = splitList(pListaData, 2);
    printf("\nResultado da divisao \n");
    printf("Lista Original:");
    printList(pListaData, printDate);
    printf("\nNova Lista:");
    printList(novaLista, printDate);

    /* teste de destruicao da lista */
    destroyList(pListaData);
    printf("\nResultado da destruicao da lista \n");
    printList(pListaData, printDate);
}
