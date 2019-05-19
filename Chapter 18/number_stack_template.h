#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H
#include <iostream>

template<class T>
class NumberStack
{
protected:
  T * stack;
  int stack_size_; // mark the size of the stack (the maximum size)
  int size_; // mark the current number of elements in the stack 
  int top_; // mark the top of the stack (this is the subscript for the last-in element)
public:
  /* Constructor */
  // normal constructor
  NumberStack(int size);
  // copy constructor 
  NumberStack(const NumberStack<T>& obj);

  /* Destructor */
  ~NumberStack();

  /* Stack operations */
  bool IsFull() const;
  bool IsEmpty() const;
  void Pop(T& var);
  void Push(T var);
  int Size() const;
  int Capacity() const;
  void DisplayUsage() const;
};

/* Constructor */
template<class T>
NumberStack<T>::NumberStack(int size)
{
  if (size <= 0)
  {
    stack = nullptr;
    stack_size_ = 0;
    top_ = -1;
    size_ = 0;
  }
  else
  {
    stack = new T[size];
    stack_size_ = size;
    top_ = -1;
    size_ = 0;
  }

}

// copy constructor 
template<class T>
NumberStack<T>::NumberStack(const NumberStack<T>& obj)
{
  if (obj.stack_size_ == 0)
    NumberStack(0); // call the constructor, pass 0 to make an empty stack 
  else
  {
    NumberStack(obj.stack_size_);
    for (int i = 0; i <= obj.top_; i++)
      stack[i] = obj.stack[i];

    // set the top of the stack 
    top_ = obj.top_;
    
    // set the size_ 
    size_ = obj.size_;
  }

}

/* Destructor */
template<class T>
NumberStack<T>::~NumberStack()
{
  delete[] stack;
}

/* Stack operations */
template<class T>
bool NumberStack<T>::IsFull() const
{
  if (size_ == stack_size_)
    return true;
  return false;
}

template<class T>
bool NumberStack<T>::IsEmpty() const
{
  if (size_ == 0)
    return true;
  return false;
}

template<class T>
void NumberStack<T>::Pop(T& var)
{
  if (IsEmpty())
    throw "Stack empty!\n";

  var = stack[top_];
  top_--;
  size_--;
}

template<class T>
void NumberStack<T>::Push(T var)
{
  if (IsFull())
    throw "Stack full!\n";

  top_++;
  size_++;
  stack[top_] = var;
}

template<class T>
int NumberStack<T>::Capacity() const
{
  return stack_size_;
}

template<class T>
int NumberStack<T>::Size() const
{
  return size_;
}

template<class T>
void NumberStack<T>::DisplayUsage() const
{
  std::cout << top_ + 1 << " out of " << Size() << " slots are used (" << static_cast<double>(top_ + 1) * 100 / stack_size_ << "%)\n";
}

#endif