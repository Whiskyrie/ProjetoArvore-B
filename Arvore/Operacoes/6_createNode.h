#ifndef CREATE_NODE_H
#define CREATE_NODE_H

pBTreeNode createNode(int t, bool is_leaf)
{
   pBTreeNode node = (pBTreeNode)malloc(sizeof(BTreeNode));
   if (node == NULL)
      return NULL;

   node->keys = (void **)malloc(sizeof(void *) * (2 * t - 1));
   node->children = (pBTreeNode *)malloc(sizeof(pBTreeNode) * (2 * t));
   node->num_keys = 0;
   node->is_leaf = is_leaf;

   for (int i = 0; i < 2 * t; i++)
   {
      node->children[i] = NULL;
   }

   return node;
}

#endif // CREATE_NODE_H