

class TreeNode {
public:
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

class BST {
public:
  TreeNode *search(int key, TreeNode *root) {
    if (!root)
      return nullptr;
    if (key > root->data)
      return search(key, root->right);
    else if (key < root->data)
      return search(key, root->left);
    else
      return root;
    return nullptr;
  }
  TreeNode *minNode(TreeNode *root) {
    while (root && root->left) {
      root = root->left;
    }
    return root;
  }
  TreeNode *deleteNode(int key, TreeNode *root) {
    if (!root)
      return nullptr;
    if (root->data < key)
      root->left = deleteNode(key, root->left);
    else if (root->data > key)
      root->right = deleteNode(key, root->right);
    else {
      TreeNode *temp = nullptr;
      if (!root->left) {
        temp = root->right;
        delete root;
        return temp;
      }
      if (!root->right) {
        temp = root->left;
        delete root;
        return temp;
      }
    temp = minNode(root->right); // inorder successor
    root->data = temp->data;
    root->right = deleteNode(temp->data, root->right);
    return root;
  }
  return root;
}
}
;
