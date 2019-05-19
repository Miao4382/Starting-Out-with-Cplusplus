// exchange two element
template <class T>
void Swap(T& value_1, T& value_2)
{
  T temp = value_1;
  value_1 = value_2;
  value_2 = temp;
}

// Partition function
// it accepts an array, the start and end index of the function 
// the function will pick a pivot first, then partition the array so all the elements before the pivot are smaller (or larger) than the pivot, all the elements after the pivot are larger (or smaller) than the pivot
// then it returns the subscript of the pivot element in the array
// the function does the actual work of sorting
// first, determine a pivot based on a certain rule, for example, the value in the middle will be used as the pivot 
// then, swap the pivot element with the first element in the array. This is to move the pivot to the head of the array. This can make it easy to place the remaining element before or after the pivot
// scan through the array (from start + 1 to end). Partition the array. Take an ascending array as an example:
// initialize the pivot value and the pivot index (= start). The pivot index should point to the element that has the following properties: the left element is smaller than the pivot value; the right element is larger than the element;
// Scan the array, if an element is greater than the pivot value, do nothing (because the pivot is on the head, so all the elements are on the right of the pivot by default); if an element is smaller than the pivot, first increment the pivot_index, then swap the smaller element and the element being pointed by pivot_index (after the increment, now this element should be the first that is greater than pivot)
// after the scan, swap array[start] with array[pivot_index]. array[start] contains the actual pivot value, array[pivot_index] contains the last element that is smaller than pivot
// to this point, the array is partitioned, return the pivot value for additional partition of the array (by the recursive QuickSort function)
template <class T>
int Partition(T* set, int start, int end)
{
  int mid = (start + end) / 2;
  Swap(set[start], set[mid]);
  
  int pivot_value = set[start];
  int pivot_index = start;
  
  // go over the array and sort 
  for (int scan = start + 1; scan <= end; scan++)
  {
    if (set[scan] < pivot_value)
    {
      pivot_index++;
      Swap(set[pivot_index], set[scan]);
    }
  }
  
  Swap(set[start], set[pivot_index]);
  
  return pivot_index;
}

// QuickSort() function
// this is a recursive function
// it accepts: a pointer to an array, the start and end subscript
// this function will sort the array from position dictated by [start, end]
// first it calls partition function to split the array into two sub-arrays
// then it calls itself twice to sort the two sub-arrays: one is smaller than the pivot value, and one is larger than the pivot value
// base case: when the sub-array has only one element (start_index is no longer smaller than end_index)
// the problem is simplified each time the array is divided into two sub-arrays
template <class T>
void QuickSort(T* set, int start, int end)
{
  if (start < end)
  {
    int pivot = Partition(set, start, end); // do the splitting and sorting 
    QuickSort(set, start, pivot - 1); // sort the first sublist 
    QuickSort(set, pivot + 1, end); // sort the second sublist 
  }
}