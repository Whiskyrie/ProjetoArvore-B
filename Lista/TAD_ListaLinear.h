#ifndef LISTA_TAD_H
#define LISTA_TAD_H

/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct Noh
{
    void *info;
    struct Noh *prox;
    struct Noh *ant;
} Noh, *pNoh;

typedef struct DLista
{
    size_t quantidade;
    struct Noh *primeiro;
    struct Noh *ultimo;
} DLista, *pDLista;

/*------------------------------------------*/
/* 3 tipos que representam ponteiros para funcao */
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef void (*FuncaoImpressaoDupla)(void *, void *);
typedef void *(*FuncaoAlocacao)(void *);
typedef void (*FuncaoLiberacao)(void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista createList();

void addInfo(pDLista pd, void *info);

void addInfoAtBeginning(pDLista pd, void *info);

int addInfoPos(pDLista lista, size_t pos, void *info);

void addInfoInMiddle(pDLista pd, void *info, size_t pos);

int addInfoOrdered(pDLista pd, void *info, FuncaoComparacao pfc);

int removeInfo(pDLista pd, void *info, FuncaoComparacao pfc);

void *removeInfoPos(pDLista pd, int pos);

int containsInfo(pDLista pd, void *info, FuncaoComparacao pfc);

void printList(pDLista pd, FuncaoImpressao pfi);

void destroyListRecursive(pNoh atual);

void destroyListInfo(pDLista pd, FuncaoLiberacao fl);

pDLista duplicateList(pDLista pd, FuncaoAlocacao fa);

pDLista splitList(pDLista pListaOriginal, size_t pos);

pDLista mergeLists(pDLista lista1, pDLista lista2, FuncaoComparacao fc);

void reverseList(pDLista pd);

void *searchNodeInfo(pDLista lista, void *info, FuncaoComparacao fc);

void *searchInfoPosition(pDLista lista, int pos);

void *getInfoPos(pDLista lista, size_t pos);

int getSizeList(pDLista lista);

#endif
