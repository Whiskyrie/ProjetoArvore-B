#ifndef FIND_SUCESSOR_H
#define FIND_SUCESSOR_H

void* findSuccessor(pBTreeNode node) {
    // Keep moving to the left-most child until we reach a leaf
    while (!node->is_leaf) {
        node = node->children[0];
    }
    // Return the first key in the leaf
    return node->keys[0];
}

#endif