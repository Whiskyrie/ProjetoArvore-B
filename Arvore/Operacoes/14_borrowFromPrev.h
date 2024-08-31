#ifndef BORROW_FROM_PREV_H
#define BORROW_FROM_PREV_H

void borrowFromPrev(pBTreeNode node, int idx)
{
    pBTreeNode child = node->children[idx];
    pBTreeNode sibling = node->children[idx - 1];

    // Shift all keys in child one step ahead
    for (int i = child->num_keys - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];

    // If not leaf, shift all its child pointers one step ahead
    if (!child->is_leaf)
    {
        for (int i = child->num_keys; i >= 0; --i)
            child->children[i + 1] = child->children[i];
    }

    // Set child's first key to keys[idx - 1] from the current node
    child->keys[0] = node->keys[idx - 1];

    // Moving sibling's last child as child's first child
    if (!child->is_leaf)
        child->children[0] = sibling->children[sibling->num_keys];

    // Moving the key from the sibling to the parent
    node->keys[idx - 1] = sibling->keys[sibling->num_keys - 1];

    child->num_keys += 1;
    sibling->num_keys -= 1;
}

#endif