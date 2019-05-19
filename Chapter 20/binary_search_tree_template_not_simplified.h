#ifndef BINARY_SEARCH_TREE_TEMPLATE_H
#define BINARY_SEARCH_TREE_TEMPLATE_H
#include <iostream>

// declaration of node class 
template <class T>
class TreeNode
{
public:
  // variables 
  T value;
  TreeNode<T>* left; // point to the left child
  TreeNode<T>* right; // point to the right child
  
  // constructor 
  // accepts a value, copy to the member variable
  // make two pointers point to nullptr
  TreeNode(T var)
  {
    value = var;
    left = nullptr;
    right = nullptr;
  }
 
  
};

/* Operator overloading */
// << 
// overload << so it can be used to display value of a TreeNode
template <class T>
std::ostream& operator<<(std::ostream& out, const TreeNode<T>& obj)
{
  out << obj.value;
  return out;
}

// specification of Binary search tree class 
template <class T>
class BinarySearchTree
{
private:
  TreeNode<T>* tree_pointer; // should point to the root node
  int node_num_; // hold the number of nodes in the tree, will be updated in adding or deleting operation

  /* Private member function */
  // copy() function 
  // a recursive function that accepts a pointer to a TreeNode (node_ptr)
  // its basic operation is to create a TreeNode using value in its parameter pointer
  // then it should call itself to copy the left branch of node_ptr 
  // then it should call itself to copy the right branch of node_ptr
  // then it should return the pointer to the newly created node, thus the created nodes can be linked together
  TreeNode<T>* copy(const TreeNode<T>* node_ptr);
  
  
  // add() function
  // a recursive function that accepts a pointer and a T value
  // it will insert the value to the proper position indicated by the pointer 
  void add(TreeNode<T>*& node_ptr, T val);
  
  // search() function 
  // a recursive function that accepts a pointer and a T value 
  // it will find out if there is a match for value in branch pointed by the pointer 
  bool search(TreeNode<T>* node_ptr, T val);
  
  // remove() function 
  // a recursive function that accepts a pointer and a T value 
  // it will find out if there is a match for the value in the branch pointed by the pointer 
  // once the match found, it will remove it from tree and remove it from memory 
  // if the node has one child, its subtree will be linked with its parent 
  // if the node has two children, its right subtree will be linked with its parent
  // then its left subtree will be attached to the right subtree 
  bool remove(TreeNode<T>*& node_ptr, T val);
  
  // remove_memory() function 
  // a recursive function that accepts a pointer to TreeNode
  // will release the memory space for all the nodes in its subtree, and itself 
  // delete left subtree -> delete right tree -> delete itself
  // this function should be called by the destructor to completely destroy the entire tree 
  void remove_memory(TreeNode<T>* node_ptr);
  
  
  // display() function (in-order traversal: left-this node-right) 
  // a recursive function that accepts a pointer
  // it will display all node branched from the position pointed by the pointer 
  // it works by first display all its left node (less than it), then display itself, then display all its right node
  // base case: if the pointer points to nullptr, do nothing but returns
  void display(const TreeNode<T>* node_ptr) const;
  
  // display() function (pre-order traversal: this node-left-right)
  // a recursive function that accepts a pointer to TreeNode
  // similar with the above display() function, the only difference is the order it displays 
  void display_pre_order(const TreeNode<T>* node_ptr) const;
  
  // display() function (post-order traversal: left-right-this)
  // a recursive function that accepts a pointer to TreeNode
  // similar with the above display() function, the only difference is the order it displays 
  void display_post_order(const TreeNode<T>* node_ptr) const;
  
public:
  /* Constructor */
  // default constructor
  BinarySearchTree()
  {
    tree_pointer = nullptr;
    node_num_ = 0;
  }
  
  // copy constructor
  // will replicate the tree (just the value, not the memory address)
  BinarySearchTree(const BinarySearchTree<T>& obj)
  {
    tree_pointer = copy(obj.tree_pointer);
    node_num_ = obj.node_num_;
  }
  
  // destructor 
  // release all allocated memory of the TreeNode
  // call a recursive private member function remove_memory() to delete all node 
  ~BinarySearchTree();
  
  
  /* Operations */
  // Insert function
  // will insert a node into the tree
  // should be inserted into the right position (based on the binary search rule)
  void Add(T val);
  
  // Search node function
  // accepts a T variable
  // Search the binary tree to find out if there is a node containing this the value of this T variable 
  // return true if node found, return false otherwise 
  bool Search(T val);
  
  // Delete node function 
  // accepts a T variable 
  // Search the binary tree to find out if there is a node matches this T variable 
  // if matching node is found, remove it from the binary tree, then return true 
  // if matching node is not found, do nothing to the binary tree and return false 
  bool Delete(T val);
  
  // size() 
  // return the number of node in the tree object
  int size() const
  {
    return node_num_;
  }
  
  // Display() function (in order)
  // will call private member function display() and pass tree_pointer to it 
  void Display() const;
  
  // Display() function (pre-order)
  // will call private member function display_pre_order() and pass tree_pointer to it 
  void DisplayPreOrder() const;
  
  // Display() function (post-order)
  // will call private member function display_post_order() and pass tree_pointer to it
  void DisplayPostOrder() const;
};

/** Private member function **/
// copy() function 
// a recursive function that accepts a pointer to a TreeNode (node_ptr)
// its basic operation is to create a TreeNode using value in its parameter pointer
// then it should call itself to copy the left branch of node_ptr 
// then it should call itself to copy the right branch of node_ptr
// then it should return the pointer to the newly created node, thus the created nodes can be linked together
template <class T>
TreeNode<T>* BinarySearchTree<T>::copy(const TreeNode<T>* node_ptr)
{
  // base case
  if (node_ptr == nullptr)
    return nullptr;
  
  // create a node 
  TreeNode<T>* ptr = new TreeNode<T> (node_ptr->value);
  // copy left branch of the node 
  ptr->left = copy(node_ptr->left);
  // copy right branch of the node 
  ptr->right = copy(node_ptr->right);
  // copy completed, return 
  return ptr;
}
  
  
// add() function
// a recursive function that accepts a pointer and a T value
// it will insert the value to the proper position indicated by the pointer 
template <class T>
void BinarySearchTree<T>::add(TreeNode<T>*& node_ptr, T val)
{
  // base case 1: if the target position is empty (nullptr), insert to it
  if (node_ptr == nullptr)
  {
    TreeNode<T>* ptr = new TreeNode<T>(val);
    node_ptr = ptr;
    node_num_++;
    return;
  }
  
  // now deal with situation that the node is not nullptr   
  if (val > node_ptr->value) // when the value is greater than the node value, should be inserted to right of the node 
  {
    // base case 2: there is no node in the right of the node (only one base case for inserting to right)
    if (node_ptr->right == nullptr)
    {
      TreeNode<T>* ptr = new TreeNode<T>(val);
      node_ptr->right = ptr;
      node_num_++;
      return;
    }
    
    // recursively add 
    else 
      add(node_ptr->right, val);
  }
  
  else if (val < node_ptr->value) // when the value is smaller than the node value, should be inserted to left of the node
  {
    // base case 3: there is no node in the left of the node 
    if (node_ptr->left == nullptr)
    {
      TreeNode<T>* ptr = new TreeNode<T>(val);
      node_ptr->left = ptr;
      node_num_++;
      return;
    }
    
    // recursively add 
    else
      add(node_ptr->left, val);
  }
  
  else // when the value is equal to the node value, insert to right
  {
    TreeNode<T>* ptr = new TreeNode<T>(val);
    ptr->right = node_ptr->right;
    node_ptr->right = ptr;
    node_num_++;
    return;
  }
  
}

// search() function 
// a recursive function that accepts a pointer and a T value 
// it will find out if there is a match for value in branch pointed by the pointer 
template <class T>
bool BinarySearchTree<T>::search(TreeNode<T>* node_ptr, T val)
{
  // base case 1: encountered an empty branch, which means there is no match, return false 
  if (node_ptr == nullptr)
    return false;
  
  // base case 2: found a matching node 
  if (node_ptr->value == val)
    return true;
  
  // continue to search recursively
  if (val > node_ptr->value)
    return search(node_ptr->right, val);
  else 
    return search(node_ptr->left, val);
}

// remove() function 
// a recursive function that accepts a pointer and a T value 
// it will find out if there is a match for the value in the branch pointed by the pointer 
// once the match found, it will remove it from tree and remove it from memory 
// if the node has one child, its subtree will be linked with its parent 
// if the node has two children, its right subtree will be linked with its parent
// then its left subtree will be attached to the right subtree
template <class T>
bool BinarySearchTree<T>::remove(TreeNode<T>*& node_ptr, T val)
{
  // base case 1: if node_ptr is nullptr, which means no match till the end, remove unsuccessful, return false 
  if (node_ptr == nullptr)
    return false;
    
  // base case 2: if node_ptr is pointing to the node to be deleted
  if (val == node_ptr->value)
  {
    // if the node has only one child 
    if (node_ptr->left == nullptr || node_ptr->right == nullptr)
    {
      TreeNode<T>* ptr = nullptr;
      if (node_ptr->left == nullptr)
      {
        ptr = node_ptr->right;
        delete node_ptr;
        node_ptr = ptr;
        node_num_--;
      }
      else 
      {
        ptr = node_ptr->left;
        delete node_ptr;
        node_num_--;
        node_ptr = ptr;
      }      
      
      return true; // node remove successfully, return true 
    }
    
    // if the node has two children 
    TreeNode<T>* ptr_l = node_ptr->left;
    TreeNode<T>* ptr_r = node_ptr->right;
    delete node_ptr; // release memory 
    node_ptr = ptr_r;
    node_num_--;
    
    TreeNode<T>* ptr = ptr_r->left; // traversing pointer, to find out the smallest node
    if (ptr == nullptr)
    {
      ptr_r->left = ptr_l;
      return true;
    }
    
    else 
    {
      while (ptr->left != nullptr)
        ptr = ptr->left;
      
      ptr->left = ptr_l; // attach the left subtree after the smallest node in right subtree      
      return true; // remove successfully      
    }

  }
  
  // if this node is not the one, continue searching and deleting 
  if (val > node_ptr->value)
    return remove(node_ptr->right, val);
  else 
    return remove(node_ptr->left, val);
}

// remove_memory() function 
// a recursive function that accepts a pointer to TreeNode
// will release the memory space for all the nodes in its subtree, and itself 
// delete left subtree -> delete right tree -> delete itself
// this function should be called by the destructor to completely destroy the entire tree 
template <class T>
void BinarySearchTree<T>::remove_memory(TreeNode<T>* node_ptr)
{
  // base case 
  if (node_ptr == nullptr)
    return;
  
  // delete all memory allocated for its left branch 
  remove_memory(node_ptr->left);
  // delete all memory allocated for its right branch 
  remove_memory(node_ptr->right);
  // delete itself 
  delete node_ptr;
}


// display() function 
// a recursive function that accepts a pointer
// it will display all node branched from the position pointed by the pointer 
// it works by first display all its left node (less than it), then display itself, then display all its right node
// base case: if the pointer points to nullptr, do nothing but returns
template <class T>
void BinarySearchTree<T>::display(const TreeNode<T>* node_ptr) const
{
  // base case 
  if (node_ptr == nullptr)
    return;
  
  // display all node on its left 
  display(node_ptr->left);
  // display itself
  std::cout << node_ptr->value << " ";
  // display all node on its right
  display(node_ptr->right);
}
  
// display() function (pre-order traversal: this node-left-right)
// a recursive function that accepts a pointer to TreeNode
// similar with the above display() function, the only difference is the order it displays 
template <class T>
void BinarySearchTree<T>::display_pre_order(const TreeNode<T>* node_ptr) const
{
  // base case 
  if (node_ptr == nullptr)
    return;
  
  // display this node first 
  std::cout << node_ptr->value << " ";
  // display left subtree using pre-order display 
  display_pre_order(node_ptr->left);
  // display right subtree using pre-order display
  display_pre_order(node_ptr->right);
}

// display() function (post-order traversal: left-right-this)
// a recursive function that accepts a pointer to TreeNode
// similar with the above display() function, the only difference is the order it displays 
template <class T>
void BinarySearchTree<T>::display_post_order(const TreeNode<T>* node_ptr) const
{
  // base case 
  if (node_ptr == nullptr)
    return;
  
  // display left subtree in post-order manner
  display_post_order(node_ptr->left);
  // display right subtree in post-order manner 
  display_post_order(node_ptr->right);
  // display this node 
  std::cout << node_ptr->value << " ";
}
  
  
/** Public member function **/
// destructor 
// release all allocated memory of the TreeNode
// call a recursive private member function remove_memory() to delete all node 
template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  remove_memory(tree_pointer);
  std::cout << "Memory released.\n";
}

/* Operations */
// Insert function
// will insert a node into the tree
// should be inserted into the correct position (based on the binary search rule)
// if the value being inserted is equal to an existing value, insert it to the right of the existing value 

template <class T>
void BinarySearchTree<T>::Add(T val)
{
  // if the tree is empty, insert the root node 
  if (tree_pointer == nullptr)
  {
    tree_pointer = new TreeNode<T>(val);
    node_num_++;
    return;
  }
  
  // if the value is equal to the root node value, insert it on the right of root
  else if (tree_pointer->value == val)
  {
    TreeNode<T>* ptr = new TreeNode<T>(val);
    ptr->right = tree_pointer->right;
    tree_pointer->right = ptr;
    node_num_++;
    return;
  }
  
  // if the value should be inserted into the tree other than the root 
  // call the private member function add() to insert 
  // if value < root value, add the value to left of root node 
  // if value > root value, add the value to right of root node
  else if (tree_pointer->value < val)
    add(tree_pointer->right, val);
  else if (tree_pointer->value > val)
    add(tree_pointer->left, val);
}

// Search node function
// accepts a T variable
// Search the binary tree to find out if there is a node containing this the value of this T variable 
// return true if node found, return false otherwise 
template <class T>
bool BinarySearchTree<T>::Search(T val)
{
  // if the tree is empty, return false 
  if (tree_pointer == nullptr)
    return false;
  
  // if the value is equal to the root node value, return true 
  else if (tree_pointer->value == val)
    return true;
  
  // if the value is smaller than root node, search left side
  // otherwise, search right side 
  if (val < tree_pointer->value)
    return search(tree_pointer->left, val);
  else 
    return search(tree_pointer->right, val);
}

// Delete node function 
// accepts a T variable 
// Search the binary tree to find out if there is a node matches this T variable 
// if matching node is found, remove it from the binary tree, then return true 
// if matching node is not found, do nothing to the binary tree and return false 
template <class T>
bool BinarySearchTree<T>::Delete(T val)
{
  // if the tree is empty, return false: deletion failed
  if (tree_pointer == nullptr)
    return false;
  
  // if the tree is not empty, call remove() function to remove 
  return remove(tree_pointer, val);
}

// Display() function 
// will call private member function display() and pass tree_pointer to it 
template <class T>
void BinarySearchTree<T>::Display() const
{
  display(tree_pointer);
}


// Display() function (pre-order)
// will call private member function display_pre_order() and pass tree_pointer to it 
template <class T>
void BinarySearchTree<T>::DisplayPreOrder() const
{
  display_pre_order(tree_pointer);
}

// Display() function (post-order)
// will call private member function display_post_order() and pass tree_pointer to it
template <class T>
void BinarySearchTree<T>::DisplayPostOrder() const
{
  display_post_order(tree_pointer);
}
  
#endif