#ifndef NUMBER_LIST_TEMPLATE_2_H
#define NUMBER_LIST_TEMPLATE_2_H
#include <iostream>

// definition of the ListNode class template 
template<class T>
class ListNode
{
public:
  T value;
  ListNode<T>* next;
  
  /* Constructor */
  ListNode(T num)
  {
    value = num;
    next = nullptr;
  }
  
  /* Overload operator */
  // << operator 
  friend std::ostream& operator<<(std::ostream& out, const ListNode<T>& obj)
  {
    out << obj.value;
    return out;
  }
  // >> operator 
  friend std::istream& operator>>(std::istream& in, ListNode<T>& obj)
  {
    in >> obj.value;
    return in;
  }
  // should overload =, +, -, *, /, as well as relational operator
  // so the container is more like the array   
  
};

// definition of the NumberList class template 
template<class T>
class NumberList 
{
private:
  ListNode<T>* head;
  
  /* Function */
  int CountNodes(ListNode<T>* ptr, int num = 1);
  void RDisplay(const ListNode<T>* ptr) const;
  
  
public:
  /* Constructor */
  NumberList()
  { head = nullptr; }
  
  // copy constructor 
  NumberList(const NumberList& obj);
  
  /* Destructor */
  ~NumberList();
  
  /* Linked list operation */
  void PushBack(T num);
  void PushFront(const ListNode<T>& obj);
  void PopBack();
  void PopFront();
  void InsertNode(T num);
  void InsertNode(const ListNode<T>& obj, int position);
  void DeleteNode(T num);
  void DisplayList() const;
  void Erase(int position);
  ListNode<T>* Begin()
  { return head; }
  ListNode<T>* End();  
  void Reverse();
  int Search(const ListNode<T>& obj) const;
  void MergeArray(T* array, int size);
  int Size() const;
  int NumNodes();
  void ReverseDisplay() const; // display the list nodes in reverse order
  
  
  /* Overload operator */
  // overload the [] operator 
  // if invalid subscript used, throw an exception
  // the return type is reference to the node data type 
  ListNode<T>& operator[](const int& index);
};

/* Private function */
template<class T>
int NumberList<T>::CountNodes(ListNode<T>* ptr, int num)
{
  if (ptr->next == nullptr)
    return num;
  else 
    return CountNodes(ptr->next, ++num);
}

template<class T>
void NumberList<T>::RDisplay(const ListNode<T>* ptr) const
{
  if (ptr == nullptr)
    return;
  else 
    RDisplay(ptr->next);
  
  std::cout << ptr->value << " ";
}

/* Function declaration */
// copy constructor 
// first let head = nullptr;
// define a navigation pointer, to traverse obj
// for each node, allocate a new node that is identical to it 
template<class T>
NumberList<T>::NumberList(const NumberList<T>& obj)
{
  head = nullptr;
  
  // define two navigation pointer and new_node pointer
  ListNode<T>* ptr_obj = obj.head; // to navigate the original list 
  ListNode<T>* ptr_this = nullptr; // to navigate in this copied list
  ListNode<T>* new_node = nullptr; // to allocate new node 
  
  // check if obj is empty, if so do nothing
  if (ptr_obj == nullptr)
    return;
  
  // the list is not empty, build the first node 
  new_node = new ListNode<T>(ptr_obj->value);
  head = new_node;
  ptr_this = head;
  ptr_obj = ptr_obj->next;
  
  // build the rest list 
  while (ptr_obj != nullptr)
  {
    // allocate a new node 
    new_node = new ListNode<T>(ptr_obj->value);
    // store to the list 
    ptr_this->next = new_node;
    // update the position of the two navigation pointers 
    ptr_this = ptr_this->next;
    ptr_obj = ptr_obj->next;
  }
}

/* Destructor */
template<class T>
NumberList<T>::~NumberList()
{
  // check if the list is empty 
  if (head != nullptr)
  {
    ListNode<T>* ptr;
    ListNode<T>* previous_ptr;
    
    ptr = head;
    previous_ptr = nullptr;
    
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

/* Linked list operation */
template<class T>
void NumberList<T>::PushBack(T num)
{
  // allocate a new ListNode 
  ListNode<T>* new_node = new ListNode<T>(num);
  
  // check if the list is empty 
  if (head == nullptr)
  {
    head = new_node;
    return;
  }
  
  // the list is not empty, define a pointer to navigate the list and find the last one 
  ListNode<T>* ptr = head;
  
  while (ptr->next != nullptr)
    ptr = ptr->next;
  
  ptr->next = new_node;
}

template<class T>
void NumberList<T>::PushFront(const ListNode<T>& obj)
{
  // allocate a new ListNode
  // you have to allocate rather than define because if you define a ListNode object here, when you go out of this block, it will be destroyed 
  ListNode<T>* new_node = new ListNode<T>(obj.value);
  new_node->next = head;
  head = new_node;
}

template<class T>
void NumberList<T>::PopBack()
{
  // if there is no node, do nothing 
  if (head == nullptr)
    return;
  
  // if there is only one node, delete it
  if (head->next == nullptr)
  {
    delete head;
    head = nullptr;
    return;
  }
  
  // if there are two or more than two nodes in the linked list
  // find the last element and the one element before the last element
  ListNode<T>* ptr = End();
  ListNode<T>* previous_ptr = head;
  while ((previous_ptr->next)->next != nullptr)
    previous_ptr = previous_ptr->next;
  
  // delete the last element, make the last but one element as the last element 
  delete ptr;
  previous_ptr->next = nullptr;  
  
}

template<class T>
void NumberList<T>::PopFront()
{
  // if the list is empty, do nothing 
  if (head == nullptr)
    return;
  
  // if there is only one node 
  if (head->next == nullptr)
  {
    delete head;
    head = nullptr;
    return;
  }
  
  // if there are two or more than two nodes in the list 
  ListNode<T>* ptr = head->next;
  delete head;
  head = ptr;
}

template<class T>
ListNode<T>* NumberList<T>::End()
{
  ListNode<T>* ptr = head;
  
  while (ptr->next != nullptr)
    ptr = ptr->next;
  
  return ptr;
}

template<class T>
void NumberList<T>::InsertNode(T num)
{
  ListNode<T>* new_node = new ListNode<T>(num);
  
  // check if the list is empty 
  if (head == nullptr)
  {
    head = new_node;
    return;
  }
  
  // check if only one node in the list 
  // default order: ascending order
  if (head->next == nullptr)
  {
    if (head->value >= new_node->value)
    {
      new_node->next = head;
      head = new_node;
    }
    else 
    {
      head->next = new_node;
    }
    
    return;    
  }
  
  /* more than one node */
  // determine the sorting mode: ascending, descending or all element equal 
  ListNode<T>* ptr_1;
  ListNode<T>* ptr_2;
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
      PushBack(new_node->value); // append to the end of the list       
  }   
    
}

template<class T>
void NumberList<T>::InsertNode(const ListNode<T>& obj, int position)
{
  // check if position is valid
  if (position < 0)
    return;
  
  // create a copy of obj 
  ListNode<T>* new_node = new ListNode<T>(obj.value);
  
  // define two navigation pointers, and a variable to hold index of element pointed by ptr 
  ListNode<T>* previous_ptr = nullptr;
  ListNode<T>* ptr = head;
  int index = 0;
  
  // find the position
  while (ptr != nullptr && index != position)
  {
    previous_ptr = ptr;
    ptr = ptr->next;
    index++;
  }
  
  // if position == 0, insert into the first element 
  if (index == 0)
  {
    new_node->next = head;
    head = new_node;
    return;
  }
  
  // insert the node between previous_ptr and ptr 
  previous_ptr->next = new_node;
  new_node->next = ptr;   
}

template<class T>
void NumberList<T>::DeleteNode(T num)
{
  /* Check if the list is empty */
  if (!head)
    return;
  
  /* Define two navigation pointers */
  ListNode<T>* ptr = head;
  ListNode<T>* previous_ptr = nullptr;
  
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

template<class T>
void NumberList<T>::DisplayList() const
{
  ListNode<T>* node_ptr = head;
  
  while (node_ptr)
  {
    std::cout << node_ptr->value << " ";
    node_ptr = node_ptr->next;
  }
  std::cout << "\n";
}

template<class T>
void NumberList<T>::Erase(int position)
{
  // check if the position is valid or the list is not empty 
  if (position < 0 || head == nullptr)
    return;
  
  // traverse the list to find out the target position 
  int index = 0;
  ListNode<T>* ptr = head;
  ListNode<T>* previous_ptr = nullptr;
  
  while (index != position && ptr->next != nullptr)
  {
    previous_ptr = ptr;
    ptr = ptr->next;
    index++;
  }
  
  // if the first element matches 
  if (previous_ptr == nullptr)
  {
    head = head->next;
    delete ptr;
    return;
  }  
  
  // if match found 
  if (index == position)
  {
    previous_ptr->next = ptr->next;
    delete ptr;
    return;    
  }
  
  // no match found, do nothing     
  
}

template<class T>
void NumberList<T>::Reverse()
{
  // when there is only one node or no node in the list, do nothing 
  if (head == nullptr || head->next == nullptr)
    return;
  
  // when there is only two nodes in the list 
  if ((head->next)->next == nullptr)
  {
    (head->next)->next = head;
    head = head->next;
    (head->next)->next = nullptr;
    return;
  }
  
  // when there is more than two nodes in the list 
  // define three navigation pointers 
  ListNode<T>* previous_ptr = head;
  ListNode<T>* ptr = head->next;
  ListNode<T>* next_ptr = ptr->next;
  
  head->next = nullptr;
  while (next_ptr != nullptr)
  {
    ptr->next = previous_ptr;
    // update the position of the three navigation pointers 
    previous_ptr = ptr;
    ptr = next_ptr;
    next_ptr = next_ptr->next;
  }
  
  // after the loop, next_ptr points to nullptr
  ptr->next = previous_ptr;
  head = ptr;
    
}

template<class T>
int NumberList<T>::Search(const ListNode<T>& obj) const
{
  // if the list is empty, return -1
  if (head == nullptr)
    return -1;
  
  // if the list is not empty
  int index = 0;
  ListNode<T>* ptr = head;
  
  while (ptr != nullptr)
  {
    if (ptr->value == obj.value)
      return index;
    
    // no match, update position
    ptr = ptr->next;
    index++;
  }
  
  // if the function goes there, it means no match found
  return -1;
}

template<class T>
void NumberList<T>::MergeArray(T* array, int size)
{
  for (int i = 0; i < size; i++)
  {
    InsertNode(array[i]);
  }
}

template<class T>
int NumberList<T>::Size() const
{
  int size = 0;
  
  ListNode<T>* ptr = head;
  
  while (ptr != nullptr)
  {
    ptr = ptr->next;
    size++;
  }
  
  return size;
}

template<class T>
int NumberList<T>::NumNodes()
{
  if (head == nullptr)
    return 0;
  else 
    return CountNodes(head);
}

template<class T>
void NumberList<T>::ReverseDisplay() const
{
  if (head == nullptr)
    return;
  else 
    RDisplay(head);
}


template<class T>
ListNode<T>& NumberList<T>::operator[](const int& index)
{
  if (index < 0 || index >= Size())
    throw "Subscript out of range!\n";
  
  // navigate to the target node 
  // after the loop, ptr will point to the target node 
  ListNode<T>* ptr = head;
  for (int i = 0; i != index; i++)
    ptr = ptr->next;
  
  return *ptr;
}

#endif