#ifndef MERGE_NODES_H
#define MERGE_NODES_H

void mergeNodes(pBTreeNode node, int idx, int t)
{
    pBTreeNode child = node->children[idx];
    pBTreeNode sibling = node->children[idx + 1];

    // Move a key from the current node to the (t-1)th position of the child
    child->keys[t - 1] = node->keys[idx];

    // Copy keys from sibling to child
    for (int i = 0; i < sibling->num_keys; ++i)
    {
        child->keys[i + t] = sibling->keys[i];
    }

    // If not a leaf, copy child pointers from sibling to child
    if (!child->is_leaf)
    {
        for (int i = 0; i <= sibling->num_keys; ++i)
        {
            child->children[i + t] = sibling->children[i];
        }
    }

    // Move keys in the current node
    for (int i = idx + 1; i < node->num_keys; ++i)
    {
        node->keys[i - 1] = node->keys[i];
    }

    // Move child pointers in the current node
    for (int i = idx + 2; i <= node->num_keys; ++i)
    {
        node->children[i - 1] = node->children[i];
    }

    // Update key count of child and the current node
    child->num_keys += sibling->num_keys + 1;
    node->num_keys--;

    // Free memory occupied by sibling
    free(sibling->keys);
    free(sibling->children);
    free(sibling);
}

#endif // MERGE_NODES_H