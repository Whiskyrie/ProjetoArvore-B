#ifndef FIND_PREDECESSOR_H
#define FIND_PREDECESSOR_H

void* findPredecessor(pBTreeNode node) {
    // Keep moving to the right-most child until we reach a leaf
    while (!node->is_leaf) {
        node = node->children[node->num_keys];
    }
    // Return the last key in the leaf
    return node->keys[node->num_keys - 1];
}


#endif // FIND_PREDECESSOR_H