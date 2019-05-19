#ifndef DYNAMIC_STACK_TEMPLATE_H
#define DYNAMIC_STACK_TEMPLATE_H
#include <new>
#include <cstdlib>
#include <iostream>

// StackNode type
template<class T>
class StackNode
{
public:
  T value;
  StackNode<T>* next;
  
  /* Constructor */
  StackNode(T var)
  {
    value = var;
    next = nullptr;
  }
};

template<class T>
class DynamicStack
{
protected:
  StackNode<T>* top; // used to point to the top element
  int size_; // hold the current number of elements in the stack 
  
public:
  /* Constructor */
  // normal constructor
  // should create an empty stack
  DynamicStack();
  // copy constructor
  // each node should be allocated with new 
  DynamicStack(const DynamicStack<T>& obj);
  
  /* Destructor */
  // each node should be deleted
  ~DynamicStack();
  
  /* Stack operations */
  void Push(const StackNode<T>& obj);
  void Pop(T& var);
  bool IsEmpty() const;
  int Size() const;
  
};

/* Constructor */
// normal constructor
// should create an empty stack
template<class T>
DynamicStack<T>::DynamicStack()
{
  top = nullptr;
  size_ = 0;
}

// copy constructor
// each node should be allocated with new 
template<class T>
DynamicStack<T>::DynamicStack(const DynamicStack<T>& obj)
{
  // if obj is empty, assign nullptr to top, assign 0 to size_, then exit 
  if (obj.IsEmpty())
  {
    top = nullptr;
    size_ = 0;
    return;
  }
  
  // if obj is not empty
  // define a pointer to navigate through the obj stack
  // define a pointer to allocate new node
  // define a pointer to navigate through *this stack
  StackNode<T>* ptr_obj = obj.top;
  StackNode<T>* new_node = nullptr;
  StackNode<T>* ptr = nullptr;
  // traverse the obj stack and replicate
  while (ptr_obj != nullptr)
  {
    // allocate a new node
    try
    {
      new_node = new StackNode<T>(ptr_obj->value);
    }
    
    catch (std::bad_alloc)
    {
      std::cout << "Memory allocation failed.\n";
      exit(0);
    }
    
    // if this is the first node in obj 
    if (ptr == nullptr) 
    {
      top = new_node;
      ptr = top;
      // move ptr_obj to next node 
      ptr_obj = ptr_obj->next;
      continue;
    }
    
    // if this is not the first node in obj, attach new_node as the next node of ptr, then move ptr to it 
    ptr->next = new_node;
    ptr = ptr->next;

    // move ptr_obj to the next node 
    ptr_obj = ptr_obj->next;
  }
  
  // set size_ value 
  size_ = obj.size_;
  
}

/* Destructor */
// each node should be deleted
template<class T>
DynamicStack<T>::~DynamicStack()
{
  // define a pointer to navigate through the stack list 
  StackNode<T>* ptr = top;
  StackNode<T>* next_ptr = nullptr;
  
  // traverse the stack list to delete each node, one by one 
  while (ptr != nullptr)
  {
    next_ptr = ptr->next;
    delete ptr;
    ptr = next_ptr;
  }
  
}
  
/* Stack operations */
// Push function, should update size_ as well
template<class T>
void DynamicStack<T>::Push(const StackNode<T>& obj)
{
  StackNode<T>* new_node = nullptr;
  
  try
  { new_node = new StackNode<T>(obj.value); }
  catch (std::bad_alloc)
  {
    std::cout << "Memory allocation failed.\n";
    exit(0);
  }
  
  // add the new_node to the top
  new_node->next = top;
  top = new_node;
  
  // update size_ 
  size_++;
}

// Pop function, should update size_ as well 
template<class T>
void DynamicStack<T>::Pop(T& var)
{
  // check if the stack is empty
  if (IsEmpty())
    throw "Stack empty!\n";
  
  // define a pointer to point to the top element being popped
  StackNode<T>* pop_node = top;
  
  // pop out the node 
  var = pop_node->value;
  
  // re-link top
  top = pop_node->next;
  
  // release memory
  delete pop_node;
  
  // update size_ 
  size_--;
}

template<class T>
bool DynamicStack<T>::IsEmpty() const
{
  if (top == nullptr)
    return true;
  
  return false;
}

template<class T>
int DynamicStack<T>::Size() const
{
  return size_;
}

#endif