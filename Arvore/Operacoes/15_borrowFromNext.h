#ifndef BORROW_FROM_NEXT_H
#define BORROW_FROM_NEXT_H

void borrowFromNext(pBTreeNode node, int idx)
{
    pBTreeNode child = node->children[idx];
    pBTreeNode sibling = node->children[idx + 1];

    // Key from parent goes to the last position in child
    child->keys[child->num_keys] = node->keys[idx];

    // First key from sibling goes to parent
    node->keys[idx] = sibling->keys[0];

    // Shifting all keys in sibling one step behind
    for (int i = 1; i < sibling->num_keys; ++i)
        sibling->keys[i - 1] = sibling->keys[i];

    // Moving the child pointers one step behind
    if (!child->is_leaf)
    {
        child->children[child->num_keys + 1] = sibling->children[0];
        for (int i = 1; i <= sibling->num_keys; ++i)
            sibling->children[i - 1] = sibling->children[i];
    }

    child->num_keys += 1;
    sibling->num_keys -= 1;
}

#endif // BORROW_FROM_NEXT_H