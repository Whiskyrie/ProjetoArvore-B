#ifndef SEARCH_NODE_INFO_H
#define SEARCH_NODE_INFO_H

/* --------------------------------- */
void *searchNodeInfo(pDLista lista, void *info, FuncaoComparacao fc)
{

   pNoh atual = lista->primeiro;

   while (atual != NULL)
   {
      if (fc(atual->info, info) == 0)
         return atual->info;

      atual = atual->prox;
   }

   return NULL;
}

#endif
