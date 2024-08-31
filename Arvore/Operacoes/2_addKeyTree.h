#ifndef ADD_INFO_TREE_H
#define ADD_INFO_TREE_H

void addKeyTree(pBTree tree, void *key, FuncaoComparacao fc, FuncaoAlocacao fa)
{
    if (tree->root == NULL)
    {
        tree->root = createNode(tree->t, true);
        tree->root->keys[0] = fa(key);
        tree->root->num_keys = 1;
    }
    else
    {
        if (tree->root->num_keys == (2 * tree->t - 1))
        {
            pBTreeNode new_root = createNode(tree->t, false);
            new_root->children[0] = tree->root;
            splitChild(new_root, 0, tree->root, tree->t);

            int i = 0;
            if (fc(key, new_root->keys[0]) > 0)
            {
                i++;
            }
            insertNonFull(new_root->children[i], key, tree->t, fc, fa);

            tree->root = new_root;
        }
        else
        {
            insertNonFull(tree->root, key, tree->t, fc, fa);
        }
    }
}

#endif // ADD_INFO_TREE_H
