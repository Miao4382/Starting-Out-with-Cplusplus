#ifndef SEARCHABLE_VECTOR_H
#define SEARCHABLE_VECTOR_H

#include "simple_vector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{
public:
  /* Constructor */
  // default constructor
  SearchableVector();
  // constructor with an integer argument
  SearchableVector(int s);
  // constructor with an integer and a T type argument 
  SearchableVector(int s, T value);
  // copy constructor 
  SearchableVector(const SearchableVector& obj);
  
  /* Function */
  int Find(const T keyword) const;
  
};

/* Constructor */
// default constructor
template <class T>
SearchableVector<T>::SearchableVector() : SimpleVector<T>()
{ }

// constructor with an integer argument
template <class T>
SearchableVector<T>::SearchableVector(int s) : SimpleVector<T>(s)
{ }

// constructor with an integer and a T type argument 
template <class T>
SearchableVector<T>::SearchableVector(int s, T value) : SimpleVector<T>(s, value)
{ }

// copy constructor 
template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector& obj) : SimpleVector<T>(obj.size())
{
  for (int i = 0; i < this->size(); i++)
    this->operator[](i) = obj[i];
}

/* Function */
template <class T>
int SearchableVector<T>::Find(const T keyword) const
{
  for (int i = 0; i < this->size(); i++)
    if (this->operator[](i) == keyword)
      return i;
  return -1;
}

#endif