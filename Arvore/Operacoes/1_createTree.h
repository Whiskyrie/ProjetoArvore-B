#ifndef CRIAR_ARVORE_BTREE_H
#define CRIAR_ARVORE_BTREE_H

/* --------------------------*/
pBTree createTree(int t)
{
    pBTree tree = (pBTree)malloc(sizeof(BTree));
    if (tree == NULL)
        return NULL;

    tree->root = NULL;
    tree->t = t;

    return tree;
}
#endif
