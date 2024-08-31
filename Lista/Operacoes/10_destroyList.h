#ifndef DESTROY_LIST_H
#define DESTROY_LIST_H

void destroyListRecursive(pNoh atual)
{
    if (atual == NULL)
        return;
    destroyListRecursive(atual->prox);
    free(atual);
}

/* -------------------------------------*/
void destroyList(pDLista pd)
{
    destroyListRecursive(pd->primeiro);
    pd->primeiro = NULL;
    pd->ultimo = NULL;
    pd->quantidade = 0;
}

#endif
