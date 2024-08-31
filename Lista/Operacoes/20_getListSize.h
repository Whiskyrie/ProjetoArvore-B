#ifndef GET_LIST_SIZE_H
#define GET_LIST_SIZE_H

int getSizeList(pDLista lista)
{
    return (lista == NULL) ? 0 : lista->quantidade;
}

#endif // GET_LIST_SIZE_H