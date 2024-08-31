#ifndef SPLIT_LIST_H
#define SPLIT_LIST_H

pDLista splitList(pDLista pListaOriginal, size_t pos)
{
   if (pListaOriginal == NULL || pos == 0 || pos > pListaOriginal->quantidade)
   {
      printf("Erro: Parâmetros inválidos para splitList.\n");
      return NULL;
   }

   pDLista pNovaLista = createList();
   if (pNovaLista == NULL)
   {
      printf("Erro: Falha na criação da nova lista.\n");
      return NULL;
   }

   pNoh atual = pListaOriginal->primeiro;
   for (size_t i = 1; i < pos && atual != NULL; i++)
   {
      atual = atual->prox;
   }

   if (atual == NULL || atual->prox == NULL)
   {
      free(pNovaLista);
      return NULL;
   }

   pNovaLista->primeiro = atual->prox;
   pNovaLista->ultimo = pListaOriginal->ultimo;
   pNovaLista->quantidade = pListaOriginal->quantidade - pos;

   pListaOriginal->ultimo = atual;
   pListaOriginal->quantidade = pos;

   atual->prox = NULL;
   pNovaLista->primeiro->ant = NULL;

   return pNovaLista;
}

#endif