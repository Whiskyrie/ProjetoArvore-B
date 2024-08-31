#ifndef INSERT_NON_FULL_H
#define INSERT_NON_FULL_H

void insertNonFull(pBTreeNode node, void *key, int t, FuncaoComparacao fc, FuncaoAlocacao fa)
{
    int i = node->num_keys - 1;

    if (node->is_leaf)
    {
        while (i >= 0 && fc(key, node->keys[i]) < 0)
        {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = fa(key);
        node->num_keys++;
    }
    else
    {
        while (i >= 0 && fc(key, node->keys[i]) < 0)
        {
            i--;
        }

        i++;
        if (node->children[i]->num_keys == (2 * t - 1))
        {
            splitChild(node, i, node->children[i], t);

            if (fc(key, node->keys[i]) > 0)
            {
                i++;
            }
        }
        insertNonFull(node->children[i], key, t, fc, fa);
    }
}

#endif // GET_NEXT_VALUE_H