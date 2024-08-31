#ifndef FILL_H
#define FILL_H


void fill(pBTreeNode node, int idx, int t) {
    if (idx != 0 && node->children[idx - 1]->num_keys >= t)
        borrowFromPrev(node, idx);
    else if (idx != node->num_keys && node->children[idx + 1]->num_keys >= t)
        borrowFromNext(node, idx);
    else {
        if (idx != node->num_keys)
            mergeNodes(node, idx, t);
        else
            mergeNodes(node, idx - 1, t);
    }
}

#endif