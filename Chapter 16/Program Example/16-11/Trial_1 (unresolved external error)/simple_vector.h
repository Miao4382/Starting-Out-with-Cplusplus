#ifndef SIMPLE_VECTOR_H
#define SIMPLE_VECTOR_H

#include <iostream>
#include <new> // for bad_alloc exception
#include <cstdlib> // for the exit() function

template <class T>
class SimpleVector
{
private:
  T* list; // a pointer to hold the dynamically allocated memory space for the array
  int size_; // hold the size of the list, will be updated when the size changed (element added or deleted)
  void MemError(); // called in exception handler, handle the memory allocation error 
  void SubError(); // called in exception handler, handle the subscript access error 
  void PopError(); // called in exception handler, handle the pop back error (pop_back() is called when size_ == 0)
  
public:
  /* Constructor */
  // default constructor
  // initialize the size_ to 0 (no element provided)
  // initialize the pointer to nullptr
  SimpleVector();
  
  // constructor 
  // the parameter is an integer value, it is the size to be allocated
  // allocate an array with the size (indicated by the parameter) 
  // the above step might fail, do it in a try/catch block, catch bad_alloc 
  // if no bad_alloc thrown:
  //    assign size_ with the parameter value
  // if bad_alloc thrown:
  //    goto the exception handler
  SimpleVector(int s);
  
  // constructor 
  // accept an integer (size) and an value, which is type T 
  // allocate an array with the size 
  // assign size_ with the size, initialize each element with the value provided in the parameter 
  // if memory allocation failed: goto the exception handler
  SimpleVector(int s, T value);
  
  // copy constructor 
  // allocate new memory space (same as the obj)
  // perform member-wise assignment to the new created array
  // if memory allocation failed: goto the exception handler 
  SimpleVector(const SimpleVector& obj);
  
  /* Destructor */
  // release the allocated memory space to prevent memory leak
  ~SimpleVector();
  
  /* Member function */
  // push_back()
  // this function accepts an argument of type T, it will be added to the end of the array
  // the content of the whole array will be transferred to a temp array, and the original content will be cleared
  // size_ is used to determine the current length of the array
  // after transferring original content to temp array, increment size_ by 1
  // new memory space big enough for holding the original content plus the newly added variable will be allocated 
  // original content and the newly added content will be transferred to the newly allocated space
  // release the memory space for the temp array 
  void push_back(T var);
  
  // pop_back()
  // will delete the last element in the array
  // just decrement the size_ variable, so user can't access the content by [] operator (because of the range check)
  // if size_ is 0, throw exception 
  void pop_back();
  
  // size() 
  // to return the size of the array 
  int size() const 
  { return size_; }
  
  /* Overload operators */
  // [] 
  // if the index is beyond the scope indicated by size_, throw exception
  T& operator[] (const int &index);
  
  
};



#endif