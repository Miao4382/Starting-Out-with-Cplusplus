#ifndef DYNAMIC_QUEUE_TEMPLATE_H
#define DYNAMIC_QUEUE_TEMPLATE_H
#include <iostream>
#include <new>
#include <cstdlib>

template <class T>
class QueueNode
{
public:
  T data; // holding data 
  QueueNode<T>* next; // holding the pointer pointing to next element
  
  /* Constructor */
  QueueNode(const T& var)
  {
    data = var;
    next = nullptr;
  }
};

template <class T>
class DynamicQueue
{
private:
  QueueNode<T>* front;
  QueueNode<T>* back;
  int size_;

public:
  /* Constructors */
  // normal constructor
  DynamicQueue();
  // copy constructor 
  DynamicQueue(const DynamicQueue<T>& obj);
  
  /* Destructor */
  ~DynamicQueue();
  
  /* Queue operations */
  bool Empty() const
  {
    if (size_ == 0)
      return true;
    return false;
  }
  
  int Size() const
  { return size_; }
  
  T& Front()
  {
    return front->data;
  }
  
  T& Back()
  {
    return back->data;
  }
  
  // Push() function
  // allocate new node and insert after the newest element
  void Push(const T& var);
  
  // Pop() function 
  // remove the oldest element in queue and delete it from memory
  void Pop();
  // overload
  // accepts a reference, values of the oldest element will be stored to the parameter
  // remove the oldest element in queue and delete it from memory
  void Pop(T& val)
  {
    val = Front();
    Pop();
  }
  
  // Clear() function 
  // remove all element in queue
  void Clear()
  {
    while (size_ != 0)
      Pop();
  }
};

/* Constructors */
// default constructor
template <class T>
DynamicQueue<T>::DynamicQueue()
{
  size_ = 0;
  front = nullptr;
  back = nullptr;
}

// copy constructor 
template <class T>
DynamicQueue<T>::DynamicQueue(const DynamicQueue<T>& obj)
{
  // if obj is empty, call default constructor 
  if (obj.Empty())
  {
    DynamicQueue();
    return;
  }
  
  // if obj is not empty
  // summon a QueueNode pointer to navigate through obj 
  QueueNode<T>* ptr_obj = obj.front;
  while (ptr_obj != nullptr)
  {
    Push(ptr_obj->data);
    ptr_obj = ptr_obj->next;
  }
}

/* Destructor */
template <class T>
DynamicQueue<T>::~DynamicQueue()
{  
  while (size_ != 0)
    Pop();      
}

/* Queue operations */
// Push() function
// allocate new node and insert after the newest element
template <class T>
void DynamicQueue<T>::Push(const T& var)
{
  QueueNode<T>* new_node = nullptr;
  
  // define a pointer pointing to QueueNode
  try
  { new_node = new QueueNode<T>(var); }
  catch (std::bad_alloc)
  {
    std::cout << "Memory allocation failed.\n";
    exit(0);
  }
  
  // if the inserted node is the first node of the queue 
  if (size_ == 0)
  {
    front = new_node;
    back = new_node;
    size_++;
    return;
  }
  
  // if the inserted node is not the first node of the queue
  // insert the new_node after the last node (back)
  back->next = new_node;
  
  // update size and back 
  size_++;
  back = back->next;
}

// Pop() function 
// remove the oldest element in queue and delete it from memory
template <class T>
void DynamicQueue<T>::Pop()
{
  // if the queue is empty, do nothing
  if (size_ == 0)
    return;
  
  // if there is only one node in the queue 
  if (size_ == 1)
  {
    delete front;
    front = nullptr;
    back = nullptr;
    size_--;
    return;
  }
  
  // if there are more than one node in the queue 
  QueueNode<T>* temp = front;
  front = front->next;
  delete temp;
  size_--;
}



#endif