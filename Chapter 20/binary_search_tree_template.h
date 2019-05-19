#ifndef BINARY_SEARCH_TREE_TEMPLATE_H
#define BINARY_SEARCH_TREE_TEMPLATE_H
#include "dynamic_queue_template.h"
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
class BinarySearchTree {
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
  // base case: when the parameter is pointing to nullptr, return nullptr
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
  
  // count() function 
  // a recursive function that accepts a pointer to TreeNode
  // will count the number of non-nullptr nodes
  // base case: if the pointer passed in is pointing to nullptr, return 0 
  int count(const TreeNode<T>* node_ptr) const;
  
  // count_leaf() function 
  // a recursive function that accepts a pointer to TreeNode
  // will count the number of leaf node in the tree 
  // base case: if the pointer passed in is pointing to a leaf node, return 1
  int count_leaf(const TreeNode<T>* node_ptr) const;
  
  // height() function 
  // a recursive function that accepts a pointer to TreeNode
  // will count the height of the subtree pointed by the parameter pointer 
  // base case 1: if the pointer is nullptr, return 0 (height is 0)
  // base case 2: if the pointer is leaf node, it means the height is 1 (only itself), return 1
  // otherwise, compare the height between its left and right subtree, return the value of the higher one plus 1 (1 is for itself)
  int height(const TreeNode<T>* node_ptr) const;
  
  // add_to_queue() function 
  // a recursive function that accepts: 1, a pointer to TreeNode; 2, a reference to a dynamic_queue_template object
  // will add values stored in tree to the queue via "in order"
  // first add left branch to the queue, then add *this node, then add right branch to the queue 
  // base case: if the pointer is nullptr, return 
  void add_to_queue(DynamicQueue<T>& que, const TreeNode<T>* node_ptr);
  
  // get_width() function 
  // a recursive function that accepts: 1, a pointer to TreeNode; 2, an integer indicate the target level
  // this function will return the number of node at the provided level in a tree which is pointed by the pointer (the subtree)
  int get_width(const TreeNode<T>* node_ptr, int level);
  
public:
  /***** Constructor *****/
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
  
  
  /***** Operations *****/
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
  
  // NodeCount() function 
  // an interface to count the number of node in the tree 
  // will call private recursive function count(), and pass the root to it (tree_pointer)
  int NodeCount() const;
  
  // NodeNum() function 
  // will return the private member variable node_num_ directly 
  int NodeNum() const 
  { return node_num_; }
  
  // LeafCount() function 
  // an interface to count the number of leaf in the tree 
  // will call private recursive function count_leaf(), and pass the root to it (tree_pointer)
  int LeafCount() const
  { return count_leaf(tree_pointer); }
  
  // Height() function 
  // an interface to count the height of the tree 
  // will call private recursive function height(), and pass the root to it (tree_pointer)
  int Height() const 
  { return height(tree_pointer); }
  
  // ConvertQueue() function 
  // an interface to copy value stored in nodes to a queue, via in-order (ascending order)
  // accepts a reference of DynamicQueue<T> object
  // will call private recursive function add_to_queue() and pass the root to it (tree_pointer)
  void ConvertQueue(DynamicQueue<T>& que)
  {
    add_to_queue(que, tree_pointer);
  }
  
  // MaxWidth() function 
  // find out the maximum node by calling private member function get_width for each level 
  int MaxWidth();
  
  
  /***** Overload operator *****/
  // overload = 
  const BinarySearchTree<T> operator=(const BinarySearchTree<T>& right);

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
  if (val >= node_ptr->value) // when the value is equal or greater than the node value, should be inserted to right of the node 
      add(node_ptr->right, val);
  
  else // when the value is smaller than the node value, should be inserted to left of the node
      add(node_ptr->left, val);
  
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
  

// count() function 
// a recursive function that accepts a pointer to TreeNode
// will count the number of non-nullptr nodes
// base case: if the pointer passed in is pointing to nullptr, return 0 
template <class T>
int BinarySearchTree<T>::count(const TreeNode<T>* node_ptr) const
{
  // base case 
  if (node_ptr == nullptr)
    return 0;
  
  // otherwise, return the number of node in left branch, itself and in right branch 
  return count(node_ptr->left) + count(node_ptr->right) + 1;
}  

// count_leaf() function 
// a recursive function that accepts a pointer to TreeNode
// will count the number of leaf node in the tree 
// base case: if the pointer passed in is pointing to a leaf node, return 1
template <class T>
int BinarySearchTree<T>::count_leaf(const TreeNode<T>* node_ptr) const
{
  // base case 1
  if (node_ptr == nullptr)
    return 0;
  // base case 2
  if (node_ptr->left == nullptr && node_ptr->right == nullptr)
    return 1;
  
  // if its not base case, then it is not a leaf node 
  return count_leaf(node_ptr->left) + count_leaf(node_ptr->right);
}

// height() function 
// a recursive function that accepts a pointer to TreeNode
// will count the height of the subtree pointed by the parameter pointer 
// base case 1: if the pointer is nullptr, return 0 (height is 0)
// base case 2: if the pointer is leaf node, it means the height is 1 (only itself), return 1
// otherwise, compare the height between its left and right subtree, return the value of the higher one plus 1 (1 is for itself)
template <class T>
int BinarySearchTree<T>::height(const TreeNode<T>* node_ptr) const
{
  // base case 1
  if (node_ptr == nullptr)
    return 0;
  
  // base case 2
  if (node_ptr->left == nullptr && node_ptr->right == nullptr)
    return 1;
  
  // otherwise, find out the higher subtree 
  if (height(node_ptr->left) > height(node_ptr->right))
    return height(node_ptr->left) + 1;
  else 
    return height(node_ptr->right) + 1;
}

// add_to_queue() function 
// a recursive function that accepts: 1, a pointer to TreeNode; 2, a reference to a dynamic_queue_template object
// will add values stored in tree to the queue via "in order"
// first add left branch to the queue, then add *this node, then add right branch to the queue 
// base case: if the pointer is nullptr, return 
template <class T>
void BinarySearchTree<T>::add_to_queue(DynamicQueue<T>& que, const TreeNode<T>* node_ptr)
{
  // base case 
  if (node_ptr == nullptr)
    return;
  
  // add value in left branch to queue 
  add_to_queue(que, node_ptr->left);
  // add value in *this node
  que.Push(node_ptr->value);
  // add value in right branch to que 
  add_to_queue(que, node_ptr->right);
}

// get_width() function 
// a recursive function that accepts: 1, a pointer to TreeNode; 2, an integer indicate the target level
// this function will return the number of node at the provided level in a tree which is pointed by the pointer (the subtree)
template <class T>
int BinarySearchTree<T>::get_width(const TreeNode<T>* node_ptr, int level) {
  // base case 1: node_ptr == nullptr
  if (node_ptr == nullptr)
    return 0;
  // base case 2: the target level is reached, also node_ptr != nullptr, there is a node here, count as one 
  if (level == 1)
    return 1;
  
  // else, divide the problem. The number of node at level n, is equal to the number of the left child's subtree's node at level n-1 plus the number of the right child's subtree's node at level n-1. The problem is thus simplified (level -> level - 1)
  return get_width(node_ptr->left, level - 1) + get_width(node_ptr->right, level - 1);
}
  
  
/** Public member function **/
// destructor 
// release all allocated memory of the TreeNode
// call a recursive private member function remove_memory() to delete all node 
template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
  remove_memory(tree_pointer);
  // std::cout << "\nMemory released.\n";
}

/* Operations */
// Insert function
// will insert a node into the tree
// should be inserted into the correct position (based on the binary search rule)
// if the value being inserted is equal to an existing value, insert it to the right of the existing value 
// operation done by private member function add()

template <class T>
void BinarySearchTree<T>::Add(T val)
{
  add(tree_pointer, val);
}

// Search node function
// accepts a T variable
// Search the binary tree to find out if there is a node containing this the value of this T variable 
// return true if node found, return false otherwise 
template <class T>
bool BinarySearchTree<T>::Search(T val)
{
  return search(tree_pointer, val);
}

// Delete node function 
// accepts a T variable 
// Search the binary tree to find out if there is a node matches this T variable 
// if matching node is found, remove it from the binary tree, then return true 
// if matching node is not found, do nothing to the binary tree and return false 
template <class T>
bool BinarySearchTree<T>::Delete(T val)
{
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

// NodeCount() function 
// an interface to count the number of node in the tree 
// will call private recursive function count(), and pass the root to it (tree_pointer)
template <class T>
int BinarySearchTree<T>::NodeCount() const
{
  return count(tree_pointer);
}

// MaxWidth() function 
// find out the maximum node by calling private member function get_width for each level 
template <class T>
int BinarySearchTree<T>::MaxWidth() {
  int max_width = 0;
  
  for (int i = 1; i < Height(); i++)
    if (max_width < get_width(tree_pointer, i))
      max_width = get_width(tree_pointer, i);
  
  return max_width;
}
  
  
// overload = 
template <class T>
const BinarySearchTree<T> BinarySearchTree<T>::operator=(const BinarySearchTree<T>& right)
{
  tree_pointer = copy(right.tree_pointer);
  node_num_ = right.node_num_;
  
  return *this;
}
  
  
#endif