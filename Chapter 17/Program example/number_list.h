#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <iostream>

class NumberList
{
private:
  // declaring a structure for the list 
  struct ListNode
  {
    double value; // hold the value in one node
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
  void AppendNode(double num);
  void InsertNode(double num);
  void DeleteNode(double num);
  void DisplayList() const;
};


#endif