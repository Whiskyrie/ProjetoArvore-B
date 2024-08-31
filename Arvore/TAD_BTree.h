#ifndef TAD_BTREE_H
#define TAD_BTREE_H
#include <stdbool.h>

#define MAX_KEYS 3 // Minimum degree of the B-tree

typedef struct BTreeNode
{
    void **keys;
    struct BTreeNode **children;
    int num_keys;
    bool is_leaf;
} BTreeNode, *pBTreeNode;

typedef struct BTree
{
    pBTreeNode root;
    int t; // Minimum degree of the B-tree
} BTree, *pBTree;

// Function pointer types
typedef int (*FuncaoComparacao)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef void *(*FuncaoAlocacao)(void *);
typedef void (*FuncaoLiberacao)(void *);

// Function declarations
pBTree createTree(int t);
pBTreeNode createNode(int t, bool is_leaf);

void addKeyTree(pBTree tree, void *key, FuncaoComparacao fc, FuncaoAlocacao fa);
void insertNonFull(pBTreeNode node, void *key, int t, FuncaoComparacao fc, FuncaoAlocacao fa);
void splitChild(pBTreeNode parent, int index, pBTreeNode child, int t);
bool searchKeyTree(pBTree tree, void *key, FuncaoComparacao fc);
void removeKeyTree(pBTree tree, void *key, FuncaoComparacao fc, FuncaoLiberacao fl);
void removeKeyFromNode(pBTreeNode node, void *k, int t, FuncaoComparacao fc, FuncaoLiberacao fl);
void printTree(pBTree tree, FuncaoImpressao fi);
void destroyTree(pBTree tree, FuncaoLiberacao fl);
void fill(pBTreeNode node, int idx, int t);
void borrowFromPrev(pBTreeNode node, int idx);
void borrowFromNext(pBTreeNode node, int idx);
void *findPredecessor(pBTreeNode node);
void *findSuccessor(pBTreeNode node);
void mergeNodes(pBTreeNode node, int idx, int t);

#endif // TAD_BTREE_H