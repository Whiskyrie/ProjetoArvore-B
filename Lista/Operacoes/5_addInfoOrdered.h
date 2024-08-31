#ifndef ADD_INFO_ORDERED_H
#define ADD_INFO_ORDERED_H

int addInfoOrdered(pDLista pd, void *info, FuncaoComparacao pfc)
{
   if (pd == NULL)
   {
      fprintf(stderr, "Lista não existe ainda, não é possível incluir!\n");
      return 0;
   }

   pNoh novo = malloc(sizeof(Noh));
   if (novo == NULL)
   {
      fprintf(stderr, "Erro: Falha na alocação de memória para novo nó.\n");
      return 0;
   }
   novo->info = info;
   novo->prox = NULL;
   novo->ant = NULL;

   if (pd->primeiro == NULL)
   {
      pd->primeiro = novo;
      pd->ultimo = novo;
   }
   else
   {
      pNoh atual = pd->primeiro;
      pNoh anterior = NULL;

      while (atual != NULL && pfc(info, atual->info) > 0)
      {
         anterior = atual;
         atual = atual->prox;
      }

      if (anterior == NULL)
      {
         novo->prox = pd->primeiro;
         pd->primeiro->ant = novo;
         pd->primeiro = novo;
      }
      else if (atual == NULL)
      {
         pd->ultimo->prox = novo;
         novo->ant = pd->ultimo;
         pd->ultimo = novo;
      }
      else
      {
         novo->prox = atual;
         novo->ant = anterior;
         anterior->prox = novo;
         atual->ant = novo;
      }
   }

   pd->quantidade++;
   return 1;
}

#endif