#ifndef TESTSCORE_H
#define TESTSCORE_H

template <class T>
class TestScore
{
private:
  int size_; // hold the size of the score array
  T* ptr; // hold the array address
public:
  /* Constructor */
  TestScore(T* score, int s);
  
  /* Exception class */
  class InvalidScore
  {
  private:
    int index_; // hold the index of the first invalid score 
  public:
    /* Constructor */
    // store the subscript
    InvalidScore(int i);
    
    /* Accessor */
    // get the invalid index 
    int index() const;
  };
  
  /* Functions */
  // Average() function
  // will return the average score 
  // use size_ to calculate
  // when doing the running total, if an invalid score is found, throw InvalidScore(i)
  T Average() const;
};

/* Constructor */
// calculate the size of the array
template <class T>
TestScore<T>::TestScore(T* score, int s)
{
  size_ = s;
  ptr = score;
}

/* Exception-Constructor */
// store the subscript
template <class T>
TestScore<T>::InvalidScore::InvalidScore(int i)
{
  index_ = i;
}

/* Exception-Accessor */
// get the invalid index 
template <class T>
int TestScore<T>::InvalidScore::index() const
{ return index_; }

/* Functions */
// Average() function
// will return the average score 
// use size_ to calculate
// when doing the running total, if an invalid score is found, throw InvalidScore(i)
template <class T>
T TestScore<T>::Average() const
{
  T total = 0;
  for (int i = 0; i < size_; i++)
  {
    if (ptr[i] < 0 || ptr[i] > 100)
      throw InvalidScore(i);
    
    total += ptr[i];
  }
  
  return total / static_cast<double>(size_);
    
}
  
#endif