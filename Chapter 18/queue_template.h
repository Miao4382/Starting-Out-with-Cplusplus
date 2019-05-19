#ifndef QUEUE_TEMPLATE_H
#define QUEUE_TEMPLATE_H


template <class T>
class StaticQueue
{
protected:
  T* queue; // a pointer to hold the array of the data 
  int size_; // hold the current number of elements in queue 
  int capacity_; // hold the total size of the queue '
  int front_; // hold the subscript of the front element, which is the "oldest"
  int back_; // hold the subscript of the back element, which is the "newest"

public:
  /* Constructor */
  // normal constructor 
  // accepts an integer, which will be used as the total size of the queue
  // initialize member variables
  StaticQueue(int var);
  
  // copy constructor
  // copy the array 
  // copy the member variable (except the pointer)
  StaticQueue(const StaticQueue<T>& obj);
  
  /* Destructor */
  // should release the allocated memory space
  ~StaticQueue()
  { delete[] queue; }
  
  /* Member function */
  // empty() function, see if the queue is empty 
  // if the size_ == 0, then return true, otherwise, return false 
  bool Empty() const;
  // Full() function, see if the queue is full
  // if the size_ == capacity, then return true, otherwise, return false  
  bool Full() const;
  
  
  // size() function
  // return the current number of elements stored in *this queue
  int Size() const
  { return size_; }
  
  // capacity() function 
  // return the total capacity for *this queue 
  int Capacity() const 
  { return capacity_; }
  
  // Front() function 
  // if size_ is not 0:
  //    returns a reference to the next element (oldest element) of the queue 
  // if size_ is 0:
  //    throw an exception 
  T& Front()
  {
    if (size_ == 0)
      throw "Size is 0! Operation illegal!\n";
    
    return queue[front_];
  }
  
  // Back() function 
  // returns a reference to the newest element of the queue (if size_ != 0)
  // throw an exception (if size_ == 0)
  T& Back()
  {
    if (size_ == 0)
      throw "Size is 0! Operation illegal!\n";
    
    return queue[back_];
  }
  
  // Push() function 
  // add a new element at the end of the queue 
  // before adding, should check if size_ == capacity_. If so, the queue is full, and an error occurs
  // size_ and back_ should be updated 
  // "warp around" the back 
  void Push(const T& obj);
  
  // Pop() function 
  // removes the next element in the queue 
  // reduce size_ by one 
  // update front_
  void Pop();
};

/* Constructor */
// normal constructor 
// accepts an integer, which will be used as the total size of the queue
// initialize member variables
// throw an exception if the provided integer is equal or less than zero
template <class T>
StaticQueue<T>::StaticQueue(int var)
{
  if (var <= 0)
    throw "Unable to instantiate queue with capacity equal or less than zero.\n";
  
  queue = new T [var];
  size_ = 0;
  capacity_ = var;
  front_ = -1;
  back_ = -1;
}

// copy constructor
// copy the array 
// copy the member variable (except the pointer)
template <class T>
StaticQueue<T>::StaticQueue(const StaticQueue<T>& obj)
{
  queue = new T [obj.capacity_];
  
  for (int i = 0; i < obj.capacity_; i++)
    queue[i] = obj.queue[i];
  
  size_ = obj.size_;
  capacity_ = obj.capacity_;
  front_ = obj.front_;
  back_ = obj.back_;
}

/* Member function */
// empty() function, see if the queue is empty 
// if the size_ == 0, then return true, otherwise, return false 
template <class T>
bool StaticQueue<T>::Empty() const
{
  if (size_ == 0)
    return true;
  
  return false;
}

// Full() function, see if the queue is full
// if the size_ == capacity, then return true, otherwise, return false  
template <class T>
bool StaticQueue<T>::Full() const
{
  if (size_ == capacity_)
    return true;
  
  return false;
}
  
// Push() function 
// add a new element at the end of the queue 
// before adding, should check if size_ == capacity_. If so, the queue is full, and an error occurs
// size_ and back_ should be updated 
// "warp around" the back 
template <class T>
void StaticQueue<T>::Push(const T& obj)
{
  if (size_ == capacity_)
    throw "Queue is full!\n";
  
  // add the first element 
  if (size_ == 0)
  {
    queue[0] = obj;
    front_ = 0;
    back_ = 0;
    size_++;
  }  
   
  else // add other element 
  {
    // update back_
    back_ = (back_ + 1) % capacity_;
    
    // assign value 
    queue[back_] = obj;
    
    // update size_
    size_++;    
  }

}

// Pop() function 
// removes the next element in the queue 
// reduce size_ by one 
// update front_
template <class T>
void StaticQueue<T>::Pop()
{
  // if queue is empty, throw exception 
  if (size_ == 0)
    throw "Empty queue!\n";
  
  // if queue has only one element
  if (size_ == 1)
  {
    front_ = -1;
    back_ = -1;
    size_ = 0;
    return;
  }
  
  // if queue has more than one element 
  front_ = (++front_) % capacity_;
  size_--;
}

#endif