#ifndef PRINT_TREE_H
#define PRINT_TREE_H

#define ESPACO 5

void printNodeRecursive(pBTreeNode node, int level, FuncaoImpressao fi)
{
    if (node == NULL)
    {
        printf("%*s | \n", level * ESPACO, "");
        return;
    }

    if (node->num_keys == 0)
    {
        printf("%*s | \n", level * ESPACO, "");
        return;
    }

    // Imprimir todos os filhos à esquerda do nó atual
    printNodeRecursive(node->children[0], level + 1, fi);

    // Imprimir o nó atual
    printf("%*s[ ", level * ESPACO, "");
    for (int i = 0; i < node->num_keys; i++)
    {
        fi(node->keys[i]);

        if (i < node->num_keys - 1)
        {
            printf(" | ");
        }
    }
    printf(" ]\n");

    // Imprimir os filhos à direita de cada chave
    for (int i = 0; i < node->num_keys; i++)
    {
        printNodeRecursive(node->children[i + 1], level + 1, fi);
    }
}

void printTree(pBTree tree, FuncaoImpressao fi)
{
    if (tree->root == NULL)
    {
        printf("The B-tree is empty.\n");
        return;
    }
    printNodeRecursive(tree->root, 0, fi);
}

#endif // PRINT_TREE_H
