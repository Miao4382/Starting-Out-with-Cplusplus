#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <iostream>

template<class T>
class NumberList
{
private:
  // declaring a structure for the list 
  struct ListNode
  {
    T value; // hold the value in one node
    ListNode* next; // a pointer of the same type, to point to the next node 
  };
  
  // define a list head pointer
  ListNode* head;
  
public:
  /* Constructor */
  // default constructor 
  // the head will point to nullptr, this is an empty linked list 
  NumberList()
  { head = nullptr; }
  
  /* Destructor */
  // deletes all nodes of the linked list (list head: head)
  ~NumberList();
  
  /* Linked list operations */
  void AppendNode(T num);
  void InsertNode(T num);
  void DeleteNode(T num);
  void DisplayList() const;
};


/* Function declaration */

/* Destructor */
// deletes all nodes of the linked list (list head: head)
template <class T>
NumberList<T>::~NumberList()
{
  if (head != nullptr)
  {
    ListNode* ptr = head;
    ListNode* previous_ptr = nullptr;
    
    while (ptr != nullptr)
    {
      previous_ptr = ptr;
      ptr = ptr->next;
      delete previous_ptr;
      previous_ptr = nullptr;
    }
    
    delete previous_ptr;
    previous_ptr = nullptr;
  }
    
}

/* Linked list operations */
template <class T>
void NumberList<T>::AppendNode(T num)
{
  ListNode* new_node = new ListNode;
  ListNode* node_ptr;
  
  new_node->value = num;
  new_node->next = nullptr;
  
  if (head == nullptr) // an empty list 
  {
    head = new_node;
  }
  else
  {
    // find the last node 
    node_ptr = head;
    while (node_ptr->next != nullptr)
      node_ptr = node_ptr->next;
    
    node_ptr->next = new_node;
  }
  
}

template <class T>
void NumberList<T>::InsertNode(T num)
{
  ListNode* new_node = new ListNode;
  
  // store value
  // the pointer should be assigned after proper position found
  new_node->value = num;
  
  // check if the list empty
  if (!head)
  {
    head = new_node;
    head->next = nullptr;
    return;
  }
  
  // check if only one node in the list 
  // default order: ascending order
  if(!head->next)
  {
    if (head->value >= new_node->value)
    {
      new_node->next = head;
      head = new_node;
    }
    else 
    {
      head->next = new_node;
      new_node->next = nullptr;
    }
    
    return;
  }
  
  /* more than one node */
  // determine the sorting mode: ascending, descending or all element equal 
  ListNode* ptr_1;
  ListNode* ptr_2;
  ptr_1 = head;
  ptr_2 = head->next;
  int sort_mode = 2; // flag, 1: ascending; 0: all equal; -1: descending; 2: not determined yet
  while (sort_mode == 2)
  {
    if (ptr_1->value > ptr_2->value)
    {
      sort_mode = -1; // descending order
    }
    else if (ptr_1->value < ptr_2->value)
    {
      sort_mode = 1; // ascending order 
    }
    else 
    {
      if (!ptr_2->next) // means ptr_2 is the last element 
      {
        sort_mode = 0;
        break;
      }
      
      // ptr_2 is not the last element, move to next position and continue 
      ptr_1 = ptr_1->next;
      ptr_2 = ptr_2->next;
    }
  }
  
  // relocate ptr_1 and ptr_2
  ptr_1 = nullptr;
  ptr_2 = head;
    
  // insert the new_node to the list based on the sorting mode 
  switch (sort_mode)
  {
  // ascending 
  case 1:        
    // find the right position 
    while (ptr_2 != nullptr && ptr_2->value < num)
    {      
      ptr_1 = ptr_2;
      ptr_2 = ptr_2->next;
    }
    
    // after the above while loop, right position found
    // if the first node matches, insert to first node
    if (ptr_1 == nullptr)
    {
      head = new_node;
      new_node->next = ptr_2;
    }
    
    // if not the first node, the right position is between ptr_1 and ptr_2 
    else 
    {
      ptr_1->next = new_node;
      new_node->next = ptr_2;
    }
    
    
    break;
  
  // descending  
  case -1: 
    // find out the right position 
    while (ptr_2 != nullptr && ptr_2->value > num)
    {
      // update position 
      ptr_1 = ptr_2;
      ptr_2 = ptr_2->next;
    }
    
    // right position found 
    // if first node matches, insert to first node 
    if (ptr_1 == nullptr)
    {
      head = new_node;
      new_node->next = ptr_2;
    }
    
    else 
    {
      ptr_1->next = new_node;
      new_node->next = ptr_2;
    }
    
    break;
  
  // all element are equal, by default, insert in ascending order 
  case 0:
    if (head->value >= new_node->value) // new_node should be the first 
    {
      new_node->next = head;
      head = new_node;
      return;
    }
    
    else 
      AppendNode(new_node->value); // append to the end of the list 
    
    
  }
  
  
  
    
}

// delete node function
// search a node with value num, and delete it
// if no match found, print message
template <class T>
void NumberList<T>::DeleteNode(T num)
{
  /* Check if the list is empty */
  if (!head)
    return;
  
  /* Define two navigation pointers */
  ListNode* ptr = head;
  ListNode* previous_ptr = nullptr;
  
  /* Check if the first node is the target */
  if (head->value == num)
  {
    head = head->next;
    delete ptr;
    return;
  }
  
  /* Check middle node */
  while (ptr != nullptr && ptr->value != num)
  {
    previous_ptr = ptr;
    ptr = ptr->next;
  }
  
  // if ptr is not the nullptr, not the end, match found 
  if (ptr)
  {
    previous_ptr->next = ptr->next;
    delete ptr;
    return;
  }
  
  std::cout << "No match with a value of " << num << "found.\n";
 
}

template <class T>
void NumberList<T>::DisplayList() const
{
  ListNode* node_ptr = head;
  
  // notify empty list 
  if (!node_ptr)
    std::cout << "Empty list!\n";
  // display list 
  else 
  {
    while (node_ptr->next)
    {
      std::cout << node_ptr->value << "\n";
      node_ptr = node_ptr->next;
    }
    
    // display the last node
    std::cout << node_ptr->value << "\n";
  }
}



#endif