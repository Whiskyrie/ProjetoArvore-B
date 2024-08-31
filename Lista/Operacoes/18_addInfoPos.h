#ifndef ADD_INFO_POS_H
#define ADD_INFO_POS_H

int addInfoPos(pDLista lista, size_t pos, void *info)
{
    if (lista == NULL || pos < 1 || pos > lista->quantidade + 1)
    {
        return 0;
    }
    Noh *novo = (Noh *)malloc(sizeof(Noh));
    if (novo == NULL)
    {
        return 0;
    }
    novo->info = info;

    if (pos == 1)
    {
        novo->ant = NULL;
        novo->prox = lista->primeiro;
        if (lista->primeiro != NULL)
        {
            lista->primeiro->ant = novo;
        }
        else
        {
            lista->ultimo = novo;
        }
        lista->primeiro = novo;
    }
    else if (pos == lista->quantidade + 1)
    {
        novo->prox = NULL;
        novo->ant = lista->ultimo;
        lista->ultimo->prox = novo;
        lista->ultimo = novo;
    }
    else
    {
        Noh *atual = lista->primeiro;
        for (size_t i = 1; i < pos; i++)
        {
            atual = atual->prox;
        }
        novo->ant = atual->ant;
        novo->prox = atual;
        atual->ant->prox = novo;
        atual->ant = novo;
    }
    lista->quantidade++;
    return 1;
}

#endif // ADD_INFO_POS_H