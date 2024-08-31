#ifndef MERGE_LIST_H
#define MERGE_LIST_H

pDLista mergeLists(pDLista lista1, pDLista lista2, FuncaoComparacao fc)
{
    pDLista pNovaLista = createList();
    pNoh atual1 = lista1->primeiro;
    pNoh atual2 = lista2->primeiro;

    while (atual1 != NULL && atual2 != NULL)
    {
        if (fc(atual1->info, atual2->info) <= 0)
        {
            addInfo(pNovaLista, atual1->info);
            atual1 = atual1->prox;
        }
        else
        {
            addInfo(pNovaLista, atual2->info);
            atual2 = atual2->prox;
        }
    }

    // Adiciona os elementos restantes da lista1, se houver
    while (atual1 != NULL)
    {
        addInfo(pNovaLista, atual1->info);
        atual1 = atual1->prox;
    }

    // Adiciona os elementos restantes da lista2, se houver
    while (atual2 != NULL)
    {
        addInfo(pNovaLista, atual2->info);
        atual2 = atual2->prox;
    }

    return pNovaLista;
}

#endif