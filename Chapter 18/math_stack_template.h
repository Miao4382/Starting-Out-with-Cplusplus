#ifndef MATH_STACK_TEMPLATE_H
#define MATH_STACK_TEMPLATE_H

#include "number_stack_template.h"
template<class T>
class MathStack : public NumberStack<T>
{
public:
  /* Constructors */
  // normal constructor
  MathStack(int size) : NumberStack<T>(size)
  {}
  // copy constructor 
  MathStack(const MathStack& obj);
  
  /* MathStack operations */
  void Add();
  void AddAll();
  void Sub();
  void Mult();
  void MultAll();
  void Div();
  void Mod();    
};

// copy constructor 
template<class T>
MathStack<T>::MathStack(const MathStack& obj) : NumberStack<T>(obj.stack_size_)
{
  // copy content in obj to *this 
  for (int i = 0; i <= obj.top_; i++)
    stack[i] = obj.stack[i];
  
  // set top_ 
  top_ = obj.top_;
}

  
template<class T>
void MathStack<T>::Add()
{
  T temp_1, temp_2;
  Pop(temp_1);
  Pop(temp_2);
  
  Push(temp_1 + temp_2);
}

template<class T>
void MathStack<T>::AddAll()
{
  T temp; // to hold the popped value 
  T sum = 0; // to hold the running total, this template is only for those entity that support the math operator used: +, -, *, /
  
  while (!IsEmpty()) // add all element until the stack is empty 
  {
    Pop(temp);
    sum = sum + temp;
  }
  
  Push(sum); // store the added result
}


template<class T>
void MathStack<T>::Sub()
{
  T temp_1, temp_2;
  Pop(temp_1);
  Pop(temp_2);
  
  Push(temp_1 - temp_2);  
}

template<class T>
void MathStack<T>::Mult()
{
  T temp_1, temp_2;
  Pop(temp_1);
  Pop(temp_2);
  
  Push(temp_1 * temp_2);  
}

template<class T>
void MathStack<T>::MultAll()
{
  T temp; // to hold the popped value 
  T product = 1; // to hold the running total, this template is only for those entity that support the math operator used: +, -, *, /
  
  while (!IsEmpty()) // add all element until the stack is empty 
  {
    Pop(temp);
    product = product * temp;
  }
  
  Push(product); // store the added result  
}

template<class T>
void MathStack<T>::Div()
{
  T temp_1, temp_2;
  Pop(temp_1);
  Pop(temp_2);
  
  Push(static_cast<T>(temp_2 / temp_1));
}

template<class T>
void MathStack<T>::Mod()
{
  T temp_1, temp_2;
  Pop(temp_1);
  Pop(temp_2);
  
  Push(temp_1 % temp_2);
}


#endif