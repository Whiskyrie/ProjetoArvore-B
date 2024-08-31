#ifndef UTILS_H
#define UTILS_H

#include "BTree.h"
#include <stdio.h>

/* ---------------------------------------- */
/* tipo de dado INT */
/* ---------------------------------------- */
int compareInt(void *a, void *b)
{
   return *(int *)a - *(int *)b;
}
/* ---------------------------------------- */
void printInt(void *info)
{
   int *pi = (int *)info;
   printf("%d - ", *pi);
}
/* ---------------------------------------- */
void *allocateIntInfo(void *info)
{
   int *pi = (int *)malloc(sizeof(int));
   *pi = *((int *)info);
   return pi;
}
/* ---------------------------------------- */
void *allocateInt(void *a)
{
   int *new_int = (int *)malloc(sizeof(int));
   *new_int = *(int *)a;
   return new_int;
}

void freeInt(void *info)
{
   int *pi = (int *)info;
   free(pi);
}

int mapInt(void *xxx)
{

   return *((int *)xxx);
}

/* ---------------------------------------- */
/* tipo de dado STRUCT Data */
/* ---------------------------------------- */
struct Data
{
   int dia, mes, ano;
};
/* ---------------------------------------- */
int compareDate(void *info1, void *info2)
{
   struct Data *p1 = (struct Data *)info1;
   struct Data *p2 = (struct Data *)info2;
   return ((p2->ano - p1->ano) * 365) +
          ((p2->mes - p1->mes) * 30) +
          (p2->dia - p1->dia);
}
/* ---------------------------------------- */
void printDate(void *info)
{
   struct Data *pd = (struct Data *)info;
   printf("%d/%d/%d - ", pd->dia, pd->mes, pd->ano);
}
/* ---------------------------------------- */
void *allocateDateInfo(void *info)
{
   struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
   pd->dia = ((struct Data *)info)->dia;
   pd->mes = ((struct Data *)info)->mes;
   pd->ano = ((struct Data *)info)->ano;
   return pd;
}
/* ---------------------------------------- */
struct Data *alocaData(int dia, int mes, int ano)
{
   struct Data *pd = (struct Data *)malloc(sizeof(struct Data));
   pd->dia = dia;
   pd->mes = mes;
   pd->ano = ano;
   return pd;
}
/* ---------------------------------------- */

// // Função de comparação de chave de produto
// int compareProductKey(void *info1, void *info2)
// {
//    if (info1 == NULL || info2 == NULL)
//    {
//       fprintf(stderr, "Erro: Ponteiro nulo passado para compareProductKey.\n");
//       return 0; // ou outro valor que indique erro
//    }

//    pChaveValor p1 = (pChaveValor)info1;
//    int *chave1 = (int *)(p1->chave);
//    int *chave2 = (int *)info2;

//    if (chave1 == NULL || chave2 == NULL)
//    {
//       fprintf(stderr, "Erro: Chave nula encontrada em compareProductKey.\n");
//       return 0; // ou outro valor que indique erro
//    }

//    return *chave2 - *chave1;
// }

// // Função para alocar memória e inicializar um Produto
// struct Produto *allocateProduct(int cod, const char nome[], float preco)
// {
//    if (nome == NULL)
//    {
//       fprintf(stderr, "Erro: Nome do produto é nulo.\n");
//       return NULL;
//    }

//    struct Produto *pp = malloc(sizeof(struct Produto));
//    if (pp == NULL)
//    {
//       fprintf(stderr, "Erro ao alocar memória para Produto.\n");
//       return NULL;
//    }

//    pp->codigo = cod;
//    strncpy(pp->nome, nome, sizeof(pp->nome) - 1);
//    pp->nome[sizeof(pp->nome) - 1] = '\0'; // Garantir terminação nula
//    pp->preco = preco;

//    return pp;
// }
// // Função auxiliar para criar a chave
// int *createProductKey(int cod)
// {
//    int *key = malloc(sizeof(int));
//    if (key == NULL)
//    {
//       fprintf(stderr, "Erro ao alocar memória para a chave do produto.\n");
//       return NULL;
//    }
//    *key = cod;
//    return key;
// }

// // Função para usar ao adicionar um produto na árvore
// int addProductToTree(pDBTree arvore, int cod, const char nome[], float preco)
// {
//    struct Produto *produto = allocateProduct(cod, nome, preco);
//    if (produto == NULL)
//    {
//       return 0; // Falha ao alocar produto
//    }

//    int *chave = createProductKey(cod);
//    if (chave == NULL)
//    {
//       free(produto);
//       return 0; // Falha ao criar chave
//    }

//    int resultado = addInfoTree(arvore, chave, produto, compareProductKey);
//    if (resultado == 0)
//    {
//       free(chave);
//       free(produto);
//    }
//    return resultado;
// }

#endif /* UTILS_H */
