#ifndef ADD_INFO_IN_MIDDLE_H
#define ADD_INFO_IN_MIDDLE_H

void addInfoInMiddle(pDLista pd, void *info, size_t pos)
{

    if (pd == NULL)
    {
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }

    if (pd->quantidade == 0)
    {
        addInfo(pd, info);
        return;
    }

    if (pos > pd->quantidade)
    {
        addInfo(pd, info);
        return;
    }

    if (pos == 1)
    {
        addInfoAtBeginning(pd, info);
        return;
    }

    size_t contador = 1;
    pNoh ant, atual;
    atual = pd->primeiro;
    ant = NULL;
    while (contador < pos)
    {

        ant = atual;
        atual = atual->prox;
        contador++;
    }

    /* aloca memoria para guardar a nova info */
    pNoh pNovo = malloc(sizeof(Noh));

    /* guarda a informacao no campo "info" do novo noh alocado */
    pNovo->info = info;

    ant->prox = pNovo;
    pNovo->prox = atual;
    pd->quantidade++;
}

#endif
