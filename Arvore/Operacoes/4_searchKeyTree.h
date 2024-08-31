#ifndef BUSCAR_INFO_BTREE_H
#define BUSCAR_INFO_BTREE_H

bool searchKeyInNode(pBTreeNode node, void *key, FuncaoComparacao fc)
{
    int i = 0;
    while (i < node->num_keys && fc(key, node->keys[i]) > 0)
    {
        i++;
    }

    if (i < node->num_keys && fc(key, node->keys[i]) == 0)
    {
        return true;
    }

    if (node->is_leaf)
    {
        return false;
    }

    return searchKeyInNode(node->children[i], key, fc);
}

bool searchKeyTree(pBTree tree, void *key, FuncaoComparacao fc)
{
    if (tree->root == NULL)
    {
        return false;
    }
    return searchKeyInNode(tree->root, key, fc);
}

#endif // BUSCAR_INFO_BTREE_H
