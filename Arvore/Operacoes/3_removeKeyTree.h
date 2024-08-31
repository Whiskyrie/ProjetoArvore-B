#ifndef REMOVE_INFO_TREE_H
#define REMOVE_INFO_TREE_H

void removeFromLeaf(pBTreeNode node, int idx, FuncaoLiberacao fl)
{
    fl(node->keys[idx]);
    for (int i = idx + 1; i < node->num_keys; ++i)
    {
        node->keys[i - 1] = node->keys[i];
    }
    node->num_keys--;
}

void removeFromNonLeaf(pBTreeNode node, int idx, int t, FuncaoComparacao fc, FuncaoLiberacao fl)
{
    void *k = node->keys[idx];

    if (node->children[idx]->num_keys >= t)
    {
        void *pred = findPredecessor(node->children[idx]);
        node->keys[idx] = pred;
        removeKeyFromNode(node->children[idx], pred, t, fc, fl);
    }
    else if (node->children[idx + 1]->num_keys >= t)
    {
        void *succ = findSuccessor(node->children[idx + 1]);
        node->keys[idx] = succ;
        removeKeyFromNode(node->children[idx + 1], succ, t, fc, fl);
    }
    else
    {
        mergeNodes(node, idx, t);
        removeKeyFromNode(node->children[idx], k, t, fc, fl);
    }
}

void removeKeyFromNode(pBTreeNode node, void *k, int t, FuncaoComparacao fc, FuncaoLiberacao fl)
{
    int idx = 0;
    while (idx < node->num_keys && fc(k, node->keys[idx]) > 0)
    {
        idx++;
    }

    if (idx < node->num_keys && fc(k, node->keys[idx]) == 0)
    {
        if (node->is_leaf)
        {
            removeFromLeaf(node, idx, fl);
        }
        else
        {
            removeFromNonLeaf(node, idx, t, fc, fl);
        }
    }
    else
    {
        if (node->is_leaf)
        {
            return;
        }

        bool flag = (idx == node->num_keys);

        if (node->children[idx]->num_keys < t)
        {
            fill(node, idx, t);
        }

        if (flag && idx > node->num_keys)
        {
            removeKeyFromNode(node->children[idx - 1], k, t, fc, fl);
        }
        else
        {
            removeKeyFromNode(node->children[idx], k, t, fc, fl);
        }
    }
}

void removeKeyTree(pBTree tree, void *key, FuncaoComparacao fc, FuncaoLiberacao fl)
{
    if (tree->root == NULL)
    {
        return;
    }

    removeKeyFromNode(tree->root, key, tree->t, fc, fl);

    if (tree->root->num_keys == 0)
    {
        pBTreeNode tmp = tree->root;
        if (tree->root->is_leaf)
        {
            tree->root = NULL;
        }
        else
        {
            tree->root = tree->root->children[0];
        }
        free(tmp->keys);
        free(tmp->children);
        free(tmp);
    }
}
#endif // REMOVE_INFO_TREE_H
