#ifndef DESTROY_TREE_H
#define DESTROY_TREE_H

void destroyNode(pBTreeNode node, FuncaoLiberacao fl)
{
   if (node == NULL)
      return;

   if (!node->is_leaf)
   {
      for (int i = 0; i <= node->num_keys; i++)
      {
         destroyNode(node->children[i], fl);
      }
   }

   for (int i = 0; i < node->num_keys; i++)
   {
      fl(node->keys[i]);
   }

   free(node->keys);
   free(node->children);
   free(node);
}

void destroyTree(pBTree tree, FuncaoLiberacao fl)
{
   if (tree == NULL)
      return;

   destroyNode(tree->root, fl);
   free(tree);
}

#endif // IS_LEAF_H