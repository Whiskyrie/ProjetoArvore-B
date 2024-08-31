#ifndef DESTROY_LIST_INFO_H
#define DESTROY_LIST_INFO_H
/* -------------------------------------*/
void destroyListInfo(pDLista pd, FuncaoLiberacao fl)
{

   pNoh atual, aux;
   atual = pd->primeiro;

   while (atual != NULL)
   {

      aux = atual->prox;
      fl(atual->info);
      free(atual);
      atual = aux;
   }

   pd->primeiro = NULL;
   pd->ultimo = NULL;
   pd->quantidade = 0;
}

#endif
