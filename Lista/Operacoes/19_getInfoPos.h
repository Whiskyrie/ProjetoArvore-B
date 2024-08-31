#ifndef GET_INFO_POS_H
#define GET_INFO_POS_H

void *getInfoPos(pDLista lista, size_t pos)
{
    if (lista == NULL || pos < 1 || pos > lista->quantidade)
    {
        return NULL;
    }
    Noh *atual = lista->primeiro;
    for (size_t i = 1; i < pos; i++)
    {
        atual = atual->prox;
    }
    return atual->info;
}

#endif // GET_INFO_POS_H