#ifndef SPLIT_NODE_H
#define SPLIT_NODE_H

void splitChild(pBTreeNode parent, int index, pBTreeNode child, int t)
{
  pBTreeNode new_child = createNode(t, child->is_leaf);
  new_child->num_keys = t - 1;

  for (int j = 0; j < t - 1; j++)
  {
    new_child->keys[j] = child->keys[j + t];
  }

  if (!child->is_leaf)
  {
    for (int j = 0; j < t; j++)
    {
      new_child->children[j] = child->children[j + t];
    }
  }

  child->num_keys = t - 1;

  for (int j = parent->num_keys; j >= index + 1; j--)
  {
    parent->children[j + 1] = parent->children[j];
  }

  parent->children[index + 1] = new_child;

  for (int j = parent->num_keys - 1; j >= index; j--)
  {
    parent->keys[j + 1] = parent->keys[j];
  }

  parent->keys[index] = child->keys[t - 1];
  parent->num_keys++;
}

#endif // SPLIT_NODE_H