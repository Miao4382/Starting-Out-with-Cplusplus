#ifndef SORTABLE_VECTOR_H
#define SORTABLE_VECTOR_H
#include "searchable_vector.h"

template <class T>
class SortableVector : public SearchableVector<T>
{
public:
  /* Constructor */
  // default constructor, will call default constructor of searchable_vector 
  SortableVector() : SearchableVector<T>()
  {}
  
  // constructor with an integer argument
  SortableVector(int s);
  // constructor with an integer and a T variable as argument 
  SortableVector(int s, T value);
  // copy constructor 
  SortableVector(const SortableVector& obj);
  
  /* Member function */
  // bubble sorting function 
  // will sort the array using bubble algorithm
  void SortBubble();
  
  // selection sorting function
  // will sort the array using selection sorting algorithm
  void SortSelect();
  
  // sort and search function 
  // accepts a T variable (as the keyword for binary search)
  // this function will sort the array first, then perform a binary search 
  // call SortSelect() member function to sort 
  // call Find() to search the keyword 
  // will return the subscript of the matched term
  // return -1 if no match found
  int SortAndSearch(const T keyword);
};

/* Constructor */
// constructor with an integer argument
template <class T>
SortableVector<T>::SortableVector(int s) : SearchableVector<T>(s)
{}

// constructor with an integer and a T variable as argument 
template <class T>
SortableVector<T>::SortableVector(int s, T value) : SearchableVector<T>(s, value)
{}

// copy constructor 
template <class T>
SortableVector<T>::SortableVector(const SortableVector& obj) : SearchableVector(obj.size_)
{
  for (int i = 0; i < size_; i++)
    this->operator[](i) = obj[i];
}

/* Member function */
// bubble sorting function 
// will sort the array using bubble algorithm
template <class T>
void SortableVector<T>::SortBubble()
{
  bool exchanged;
  
  do 
  {
    exchanged = false;
    
    for (int i = 0; i < size_ - 1; i++)
    {
      if (list[i] > list[i + 1])
      {
        T temp;
        temp = list[i];
        list[i] = list[i + 1];
        list[i + 1] = temp;
        exchanged = true;
      }
    }
  } while (exchanged);
}

// selection sorting function
// will sort the array using selection sorting algorithm
template <class T>
void SortableVector<T>::SortSelect()
{
  int start_index = 0;
  T min;
  int min_index;
  do
  {
    min = list[start_index];
    min_index = start_index;
    
    for (int i = start_index; i < size_; i++)
      if (min > list[i])
      {
        min = list[i];
        min_index = i;
      }
    
    list[min_index] = list[start_index];
    list[start_index] = min;
    
    start_index++;
    
  } while (start_index < size_ - 1);  
  
}

// sort and search function 
// accepts a T variable (as the keyword for binary search)
// this function will sort the array first, then perform a binary search 
// call SortSelect() member function to sort 
// call Find() to search the keyword 
// will return the subscript of the matched term
// return -1 if no match found
template <class T>
int SortableVector<T> :: SortAndSearch(const T keyword)
{
  SortBubble();
  return Find(keyword);
}
  
  
#endif