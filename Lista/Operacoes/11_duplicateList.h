#ifndef DUPLICATE_LIST_H
#define DUPLICATE_LIST_H

pDLista duplicateList(pDLista pd, FuncaoAlocacao fa)
{
    pDLista pNovaLista = createList();

    pNoh atual = pd->primeiro;
    while (atual != NULL)
    {
        /* aloca memoria e copia do valor do campo info */
        void *auxInfo = fa(atual->info);
        /* adiciona a copia da informacao na nova lista */
        addInfo(pNovaLista, auxInfo);

        atual = atual->prox;
    }
    return pNovaLista;
}

#endif
