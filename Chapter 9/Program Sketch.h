/* Chapter 9 */

/*********************/
/***Program Example***/
/*********************/


9-1. Show address operator
The address operator can be used to display the address of a variable
Code
{
#include <iostream>

int main()
{
	int x;
	std::cout << "Before assigning value, the address of x is: " << &x << std::endl;
	x = 2;
	std::cout << "After assigning the value, the address of x is: " << &x << std::endl;

	return 0;
}

}

9-2. Use Pointer Variable to Store and Print the Address of Another Variable
Code
{
#include <iostream>

int main()
{
	int* ptr = nullptr; //You should initialize it!!
	int num = 10;
	ptr = &num;
	
	std::cout << "The address of variable num is: " << ptr << std::endl;
	
	return 0;
}


}

9-3. Use the indirection operator
Code
{
#include <iostream>

int main()
{
	double num = 250.09;
	double* ptr_double = nullptr; //define and initialize a pointer
	ptr_double = &num; //assign the memory address of variable num to pointer ptr_double
	*ptr_double += 1; //dereference the pointer, and operate on the dereferenced pointer
	std::cout << "After operation: " << num << " " << *ptr_double << ". The memory address is: ";
	std::cout << ptr_double << std::endl;
	
	return 0;
	
}

}

9-4. Demonstrate Pointer Can Point to Different Variables
Code
{

#include <iostream>

int main()
{
	int num1 = 10, num2 = 25;
	int* ptr = nullptr;
	
	std::cout << "Before operating: " << num1 << " " << num2 << std::endl;
	ptr = &num1; //link pointer to num1
	*ptr += 5; //operate the value stored in the memory address pointer points to
	ptr = &num2; //disconnect pointer with num1, re-link to num2
	*ptr -= 5;
	std::cout << "After operating: " << num1 << " " << num2 << std::endl;
	
	return 0;
}

}

9-5. Array Name Being Used with Indirection Operator
Code
{

#include <iostream>

int main()
{
	int num[5] = { 1,2,3,4,5 };
	
	std::cout << *num << std::endl;
	
	return 0;
}

}

9-6. Access entire content of an array using pointer and indirection operator
	define: int num[5] = { 1,2,3,4,5 };
The name of the array is a constant pointer, it always points to the starting memory address of the array (i.e. *num == num[0] == 1);

If you add 1 to the pointer variable (num+1), you are actually adding 1*sizeof(data type) to the pointer variable, that means the memory address will become the second element in the array. In this way, you can access the entire array by adding the subscript of each element to the pointer.

When working with arrays, just remember: num[i] = *(num+i);

Code
{

#include <iostream>

int main()
{
	int num[5] = { 1,2,3,4,5 };
	for(int i=0; i<5; i++)
		std::cout << *(num+i) << " ";
	std::cout << "\n";
	
	int* ptr_int = nullptr;
	ptr_int = num + 3;
	std::cout << *ptr_int << std::endl;
	return 0;
}

}

9-7. Pointers can be used as array names, and access array elements by pointer name and subscript (like: ptr[4]).
Code
{

#include <iostream>

int main()
{
	double num[5] = { 0.1,0.2,0.3,0.4,1.25 };
	double* ptr_double = nullptr;
	ptr_double = num;
	
	for(int i=0; i<5; i++)
		std::cout << ptr_double[i] << " ";
	std::cout << "\n";
	
	return 0;
}


}

> When assigning an array's address to a pointer, no address operator is required, because the name of an array and the pointer have the same variable type: pointer variable.

9-8. Link a pointer to individual array element's memory address
	int num[5] = { 1,2,3,4,5 };
Unlike the array name, num[i] is a "normal" variable, its memory address is the corresponding array element's memory address. You can use a pointer link to this address, at this time, you should use address operator to get the address of the variable.

Code
{

#include <iostream>

int main()
{
	int num[5] = { 1,2,3,4,5 };
	int* ptr_int = nullptr;
	ptr_int = &num[0];
	
	std::cout << *ptr_int << " " << *(ptr_int+1) << std::endl;
	
	return 0;
}


}


9-9. Use increment and decrement operator on pointers
When you use increment or decrement operator on pointers, you actually increase or decrease sizeof(data_type) on that pointer. Next code shows an example:

Code
{

#include <iostream>

int main()
{
	int num[5] = { 1,2,3,4,5 };
	int* ptr_int = nullptr;
	
	ptr_int = &num[4]; //link to array
	
	for(int i=0; i<5; i++)
	{
		std::cout << *ptr_int << " ";
		ptr_int--;
	}
	
	std::cout << "\n";
	
	return 0;
	
}



}

Allowable arithmetic operations are:
> ++ - -: used to increment or decrement a pointer value;
> add or subtract an integer from a pointer variable (+ -, +=, -=);
> a pointer may be subtracted from another pointer;

Code: pointer arithmetic-pointer subtraction and addition
{
/*
This program has some problems, can't get the subtraction of pointers
*/
#include <iostream>

int main()
{
	int num[5] = { 1,2,3,4,5 };
	int *ptr1 = nullptr, *ptr2 = nullptr;
	ptr1 = &num[3];
	ptr2 = &num[4];
	int* ptr3 = ptr2 - ptr1;
	
	std::cout << *ptr3 << std::endl;
	
	return 0;
}

}


9-10. Use a pointer to step through an array (first to last, then last to first). Use "memory address compare" to control the range.

Code
{

#include <iostream>

int main()
{
	int set[5] = { 1,2,3,4,5 }, *num = set; //a pointer is defined and linked to array
	
	//first to last
	std::cout << "Forward:\n";
	while (num <= &set[4]) //while the memory address is within the scope of the array
	{
		std::cout << *num << " ";
		num++; //update the pointer, so it points to the next element
	}
	
	//pointer num not points to the memory address after the last element of the array, it should be reduced one to begin backward process
	num -= 1;
	//last to first
	std::cout << "\n\nBackward:\n";
	while (num >= set)
	{
		std::cout << *num << " ";
		num--; //update
	}
	
	std::cout << "\n";
	
	return 0;
}


}


9-11. Pointers and memory addresses as function parameters
9-12. Using arrays.
Demonstrate how to define a function that accepts memory address as parameter, and show how to call the function.
Code
{

#include <iostream>

void get_number(double *num);
void double_value(double *num);
void subtract(double *num);
void divide_by2(double *num);

int main()
{
	double set[5];
	double *num = set;
	
	//call a get_num function to input the number
	std::cout << "Please input 5 numbers: ";
	get_number(num);
	
	while (num <= &set[4])
	{
		double_value(num);
		std::cout << *num << " ";
		num++;
	}
	
	std::cout << "\n\n\n";
	num = set;
	
	for (int i=0; i<5; i++)
	{
		subtract(&num[i]);
		std::cout << num[i] << " ";
	}
	
	std::cout << "\n\n\n";
	
	for (int i=0; i<5; i++)
	{
		divide_by2(num+i);
		std::cout << *(num+i) << " ";
	}
}

void get_number(double *num)
{
	for(int i=0;i<5;i++)
	{
		std::cin >> *(num+i);
	}
}

void double_value(double *num)
{
	*num *= 2;
}

void subtract(double *num)
{
	*num -= 1;
}

void divide_by2(double *num)
{
	*num /= 2;
}

}

9-13. Passing a nonconstant argument into a pointer to a constant
The memory address of a constant item can only be stored in a pointer to a constant. However, a pointer to a constant can also store the memory address of a nonconstant argument. Following program demonstrates the idea.
Code
{

#include <iostream>

void display_array(const int *pointer);

int main()
{
	const int num1[5] = { 1,2,3,4,5 };
	const int *ptr1 = num1;
	int num2[5] = { 6,7,8,9,10 };
	int *ptr2 = num2;
	
	//display the constant array
	display_array(ptr1);
	
	//switch ptr1, link to a nonconstant array
	ptr1 = num2;
	
	//print the non-constant array, using a pointer to constant
	display_array(ptr1);
	
	//pass a pointer to nonconstant to the function to see if it works
	display_array(ptr2);
	
	return 0;
}

void display_array(const int *ptr)
{
	for (int i=0; i<5; i++)
		std::cout << ptr[i] << " ";
	std::cout << std::endl;
}


}

9-14. Practice dynamic memory allocation
1) Checkpoint
Use new operator to request a new memory space to store data:
	int *ptr = nullptr;
	ptr = new int [100]; //request new memory space for 100 int elements, the address is stored in ptr after this statement.
Use delete operator to free the newly allocated memory space.
	delete[] ptr; //delete consecutive memory space for arrays
	delete ptr; //delete single memory space for variables

2) Objective
Asks for sales figures for any number of days. The figures are stored in a dynamically allocated array and then totaled and averaged.

3) Code
{

#include <iostream>
#include <iomanip>

void input(double sale[], int days);
double total(double sale[], int days);
double average(double total_sale, int days);

int main()
{
	int days;
	double *sale = nullptr;
	
	//ask the user for how many days she want to input data
	std::cout << "How many days you want to input data: ";
	std::cin >> days;
	
	//request a memory space large enough to hold the data
	sale = new double [days];
	
	//call input function to input the sales figure for each days
	input(sale, days);
	
	//call total function to calculate total
	double total_sale;
	total_sale = total(sale, days);
	
	//call average function to calculate average
	double average;
	average = total_sale/days;
	
	//display result
	std::cout << std::setprecision(2) << std::fixed; //set the format
	std::cout << "The sales figure is as follows:\n";
	for (int i=0; i<days; i++)
		std::cout << "Days: " << i+1 <<"  Sales: $" << sale[i] << std::endl;
	std::cout << "\n\n";
	
	std::cout << "Total sale: $" << total_sale << std::endl;
	std::cout << "Average sale: $" << average << std::endl;
	
	//free memory
	delete[] sale;
	sale = nullptr; //sale should be point to null again in case of memory corruption
	
	return 0;
}

//input function
void input(double sale[], int days)
{
	for (int i=0; i<days; i++)
	{
		std::cout << "What is the sales figure for day " << i+1 << ": ";
		std::cin >> sale[i];
	}
}

//total function
double total(double sale[], int days)
{
	double total = 0;
	for (int i=0; i<days; i++)
	{
		total += sale[i];
	}
	
	return total;
}

//average function
double average(double total_sale, int days)
{
	return total_sale/days;
}



}

/* Example function */
Objective: create a program, it uses a linear search algorithm to find the first number 65 stored in an int array. This program should call a function which returns pointer to int (the pointer to the element containing number 65)

Code
{

#include <iostream>
#include <ctime>
#include <cstdlib>


const int NUM = 100;

//function prototype
void set_initiate(int *set);
int *find_A(int *set);

int main()
{	
	int *set = new int[NUM]; //request a int memory space (NUM)
	set_initiate(set); //call initialization function to initialize the array
	int *letter_A_position = nullptr; //define a pointer to store the memory address of first letter A
	
	//call function to find out A
	letter_A_position = find_A(set);
	
	//print out result 
	std::cout << "The address is: " << letter_A_position << ", and the letter is: ";
	std::cout << *letter_A_position << std::endl;
	std::cout << "It is element " << letter_A_position - set << std::endl;
	
	//release the allocated memory
	delete[] set;
	
	return 0;		
	
}

void set_initiate(int *set)
{
	//seed random number
	int seed;
	seed = time(0);
	srand(seed);
	//define the range of random intacter: A ~ Z
	const int N_min = 65, N_max = 90;
	//initialize the array with random letter
	for (int i=0; i<NUM; i++)
		set[i] = rand()%(N_max-N_min+1)+N_min;		
}

int *find_A(int *set)
{
	int *ptr_c = set; //set shouldn't be changed because its the first memory address of the dynamically allocated array
	while (*ptr_c != 65)
		ptr_c++;
	
	return ptr_c;
}


}

This program is not complete, because if there is no 65 exist, the program will crush. Should write some parts that determine whether there is the number in the set.

/* Example function */
Objective: show the possibility that request a chunk of memory and return the address of that memory space.
Code:
{

# include <iostream>

int *create_int_array(int size);

int main()
{
	int *num = nullptr, size = 100;
	//call create_int_array function to create an array
	num = create_int_array(size);
	
	//try
	num[0] = 1;
	std::cout << num[0] << std::endl;
	return 0;
}

int *create_int_array(int size)
{
	/*
	This function can create a int array, it asks for the size of the array to be created, and return the memory address
	*/
	int *ptr = new int [size];
	return ptr;
}


}


9-15. Use a function to get a pointer to an array of random numbers
The function accept an int argument as the size of the random array.
Code:
{

#include <iostream>
#include <ctime>
#include <cstdlib>

int *get_random_numbers(int size, int N_min, int N_max);

int main()
{
	int size; //variable to hold the size of the array
	int *num = nullptr; //define the pointer that will store the address for the random array
	int N_min, N_max; //minimum and maximum number in the random array
	//ask for size, minimum and maximum number of the array
	std::cout << "Please input the size of the array: ";
	std::cin >> size;
	std::cout << "Please input the minimum number of the array: ";
	std::cin >> N_min;
	std::cout << "Please input the maximum number of the array: ";
	std::cin >> N_max;	
	
	//call function to generate the random array, use num pointer to hold the memory address
	num = get_random_numbers(size, N_min, N_max);
	
	//print out the array
	std::cout << "The array is:\n";
	for (int i=0; i<size; i++)
		std::cout << num[i] << " ";
	std::cout << "\n";
	
	return 0;
}

//random number generator
int *get_random_numbers(int size, int N_min, int N_max)
{
	//seed the random numbers
	int seed;
	seed = time(0);
	srand(seed);
	
	//request a chunk of memory
	int *ptr = new int [size];
	
	//initialize random numbers
	for(int i=0; i<size; i++)
		ptr[i] = rand()%(N_max-N_min+1) + N_min;
	
	//return the array address
	return ptr;
	
}


}

9-16. Duplicate a array
1) objective
> Accept an array and its size as arguments.
> Dynamically allocate a new array that is the same size as the argument array.
> Copy the elements of the argument array to the new array.
> Return a pointer to the new array.

2) Code
{

#include <iostream>
const int SIZE = 5;

int *duplicate(int num[], int size);

int main()
{
	int num0[SIZE] = { 1,2,3,4,5 }; //this is the array that is to be copied
	int *num_copy = nullptr; //define a pointer to hold copied array address
	
	//call duplicate function to copy the array
	num_copy = duplicate(num0, SIZE);
	
	//print the original array
	std::cout << "The original array is: ";
	for (int i=0; i<SIZE; i++)
		std::cout << num0[i] << " ";
	std::cout << "\n";
	
	//print the duplicated array
	std::cout << "The duplicated array is: ";
	for (int i=0; i<SIZE; i++)
		std::cout << num_copy[i] << " ";
	std::cout << "\n";	
}

//duplicate function
int *duplicate(int num[], int size)
{
	//request memory chunk
	int *ptr = new int [size];
	
	//copy term one by one
	for (int i=0; i<size; i++)
		ptr[i] = num[i];
	
	//return the address of the newly allocated data
	return ptr;
}

}

/* Checkpoint 9-11 */
Code:
{
#include <iostream>
#include <iomanip>
using namespace std;
// Write your function prototype here.
void convert(double *measurement);

int main()
{
	double measurement;
	cout << "Enter a length in inches, and I will convert\n";
	cout << "it to centimeters: ";
	cin >> measurement;
	convert(&measurement);
	cout << fixed << setprecision(4);
	cout << "Value in centimeters: " << measurement << endl;
	return 0;
}

void convert(double *measurement)
{
	*measurement *= 2.54;
}



}

9-17. Use smart pointer
1) Description
> smart pointer can automatically free the dynamically allocated memory once the memory is no use. 
> To use a smart pointer, you have to include <memory> header file.
> There are three kinds of smart memory: unique_ptr, shared_ptr, weak_ptr;
> The definition of unique_ptr is: unique_ptr<int> ptr(new int);

2) Objective: define a smart pointer, use it to input and output a variable

3) Code
{
#include <iostream>
#include <memory>

int main()
{
	std::unique_ptr<int> ptr(new int);
	*ptr = 5;
	
	std::cout << *ptr << tsd::endl;
	
	return 0;
}	
	


}

4) Code-II: call a function to request memory, and return the address, using smart pointer
{

#include <iostream>
#include <memory>

int *create_variable();

int main()
{
	std::unique_ptr<int> num = nullptr;
	num = create_variable();
	std::cout << *num << std::endl;
	return 0;
}

std::unique_ptr<int> create_variable()
{
	std::unique_ptr<int> ptr(new int);
	*ptr = 5;
	return ptr;
}

}
PS: function return type should be the same as the unique pointer: std::unique_ptr<int> function_name();


9-18. Practice unique pointer array technique
Code
{

#include <iostream>
#include <memory>

int main()
{
	//ask for size of the array
	std::cout << "What is the size you want: ";
	int size;
	std::cin >> size;
	
	//allocate memory for the array
	std::unique_ptr<int[]> num(new int[size]);
	
	//input number
	for(int i=0; i<size; i++)
	{
		std::cout << "Please input number " << i+1 << ": ";
		std::cin >> num[i];
	}
	
	//print out the array
	std::cout << "The numbers you inputted were:\n";
	for(int i=0; i<size; i++)
		std::cout << num[i] << std::endl;
	std::cout << "\n";
	
	return 0;
}


}

9-19. Case study: demonstrate how an array of pointers can be used to display the contents of a second array in sorted order, without sorting the second array

1) Problem description
{
The United Cause, a charitable relief agency, solicits donations from businesses. The local United Cause office received the following donations from the employees of CK Graphics, Inc.:
	$5, $100, $5, $25, $10, $5, $25, $5, $5, $100, $10, $15, $10, $5, $10
The donations were received in the order they appear. The United Cause manager has asked you to write a program that displays the donations in ascending order, as well as in their original order.

}

2) Trial widget
2-1) An array of pointers
{
/* This demonstrate the building of an array of pointers, which is used to store a series of arrays.*/
Code
{
#include <iostream>

int main()
{
	//define an array, the data type in the array is pointers that can point to int data
	int *num[5];
	int set[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
		num[i] = &set[i];

	std::cout << *num[3] << num[0] << std::endl;

	//pointer of a memory address, pointer's pointer
	int **ptr = num;
	std::cout << *ptr << std::endl;
	return 0;
}
}

}

3) Steps and pseudocode
{
> create an array to store all the donations
> create another array ("you can't use smart pointers here because smart pointer only work with requested memory space?") to store pointers (a pointer array)
> link the pointers to each donation element
> sort the pointer array based on value of dereferenced pointer (its the amount of donation they point to), the content in each array will not change (the memory address), but the order will change
> display the sorted, dereferenced pointer array and the original array

}

4) Code
{

#include <iostream>

void synchro(int *donation, int **ptr);
void selection_sort(int **ptr);

int main()
{
	//create the original array
	int donation[15] = { 5,100,5,25,10,5,25,5,5,100,10,15,10,5,10 };
	
	//create an array to store pointer to integer
	int *ptr[15]; //when you define the pointer array, you should initialize it with something, if there is nothing to assign yet, you should to initialize them with nullptr, in this way, the memory won't be corrupted.
	
	//call a synchro function to link each element in donation with each element in ptr[]
	synchro(donation, ptr);
	
	//call a sort function to sort the pointer array
	selection_sort(ptr);
	
	//print out result
		//print out the sorted data
	std::cout << "The sorted donations are: \n";
	for(int i=0; i<15; i++)
		std::cout << "$ " << *ptr[i] << std::endl;
	std::cout << "\n";
		//print out the original data
	std::cout << "The original data is as follows:\n";
	for (int i=0; i<15; i++)
		std::cout << "$ " << donation[i] << std::endl;
	std::cout << "\n";
}

void synchro(int *donation, int **ptr)
{
	//use a loop to link each other
	for(int i=0; i<15; i++)
		ptr[i] = &donation[i];
}

//pay attention that the min variable should have data type of pointer. Just keep in mind that min has the same data type as the sorted data. (same in original selection sorting)
void selection_sort(int **ptr)
{
	int start_scan = 0;
	do
	{
		int *min = ptr[start_scan];
		int min_index = start_scan;
		for(int i=start_scan; i<15; i++)
			if(*min > *ptr[i])
			{
				min = ptr[i];
				min_index = i;
			}
		//exchange
		ptr[min_index] = ptr[start_scan];
		ptr[start_scan] = min;
		
		//update the start_scane position
		start_scan++;
		
	} while (start_scan < 14);
}

}


/************************/
/***Program Challenges***/
/************************/

1. Array Allocator
{
	
Code:
{

int *array_creater(int num)
{
	int *array_address = new int[num];
	return array_address;
}


}

}

2. Test Scores #1
{

2-1) Task analysis
{

> ask user to input a number
> create an array with a size of number (dynamically memory allocation)
> input scores, input check: range of score is between 0 ~ 100
> sort the score (by calling appropriate function)
> average the score (by calling appropriate function)
> displayed sorted score and average

(use pointer notation rather than array notation whenever possible)

}

2-2) Code
{

#include <iostream>

double *create_array(int total_num);
void selection_sort(double **score_ptr, int size);
double average_score(double *score, int size);
void display(double **score_ptr, double average, double *score, int size);

int main()
{
	//ask for a number
	std::cout << "How many scores to be entered: ";
	int total_num;
	std::cin >> total_num;
	
	//call a function to allocate the array and fill the array, return the starting address of the array
	double *score = nullptr;
	score = create_array(total_num);
	
	//create an array of pointer and link them to each element in the score array
	double **score_ptr = new double *[total_num];
	for(int i=0; i<total_num; i++)
		*(score_ptr+i) = &(*(score+i)); //link the address of each element in score[] to score_ptr[]
	
	//call a function to sort score_ptr[] array, so the address pointing to the lowest score will be first element in score_ptr[]
	selection_sort(score_ptr, total_num);
	
	//call average function to calculate average, return
	double average;
	average = average_score(score, total_num);
	
	//display the result
	display(score_ptr, average, score, total_num);
	
	//release memory
	delete[] score;
	
	return 0;
	
}

//create array function (by dynamically memory allocation)
double *create_array(int total_num)
{
	//allocate memory space
	double *ptr = new double [total_num];
	//input score
	std::cout << "Begin input scores:\n";
	for(int i=0; i<total_num; i++)
	{
		std::cout << "What is the score for student " << i+1 << ": ";
		std::cin >> *(ptr+i);
		while (*(ptr+i) <0 || *(ptr+i) > 100 )
		{
			std::cout << "Invalid input, please input again: ";
			std::cin >> *(ptr+i);
		}
	}
	
	//after inputting, return memory address
	return ptr;
	
}

//selection sort function to sort the score address
void selection_sort(double **score_ptr, int size)
{
	int start_scan = 0;
	do
	{
		double *min = *(score_ptr+start_scan); //sort the pointer array
		int min_index = start_scan;
		//go over the score and find out the minimum
		for(int i=start_scan+1; i<size; i++)
			if (*min > *(*(score_ptr+i)))
			{
				min = *(score_ptr+i);
				min_index = i;
			}
		//exchange memory address stored in score_ptr array
		*(score_ptr+min_index) = *(score_ptr+start_scan);
		*(score_ptr+start_scan) = min;
		//update the start_scan position
		start_scan++;							
	} while (start_scan < size-1);
}

//average function
double average_score(double *score, int size)
{
	double total=0;
	//use a loop to calculate total
	for(int i=0; i<size; i++)
		total += *(score+i);
	//return average
	return total/size;
}

//display function
void display(double **score_ptr, double average, double *score, int size)
{
	std::cout << "Test scores (from lowest to highest):\n";
	//use a loop to display all the info, use (*score_ptr - score + 1) as the student id
	for(int i=0; i<size; i++)
	{
		std::cout << "Student " << (*(score_ptr+i) - score) + 1 << ": " << *(*(score_ptr+i)) << "\n";
	}
	std::cout << "\n";
	//print out the average score
	std::cout << "The average score is: " << average << std::endl;
}


}


}

3. Drop lowest Scores
{

3-1) Task analysis
Modify the problem 2 above to drop the lowest score when calculating the average score

3-2) Code
{

#include <iostream>

double *create_array(int total_num);
void selection_sort(double **score_ptr, int size);
double average_score(double *score, int size, double **score_ptr);
void display(double **score_ptr, double average, double *score, int size);

int main()
{
	//ask for a number
	std::cout << "How many scores to be entered: ";
	int total_num;
	std::cin >> total_num;
	
	//call a function to allocate the array and fill the array, return the starting address of the array
	double *score = nullptr;
	score = create_array(total_num);
	
	//create an array of pointer and link them to each element in the score array
	double **score_ptr = new double *[total_num];
	for(int i=0; i<total_num; i++)
		*(score_ptr+i) = &(*(score+i)); //link the address of each element in score[] to score_ptr[]
	
	//call a function to sort score_ptr[] array, so the address pointing to the lowest score will be first element in score_ptr[]
	selection_sort(score_ptr, total_num);
	
	//call average function to calculate average, return
	double average;
	average = average_score(score, total_num, score_ptr);
	
	//display the result
	display(score_ptr, average, score, total_num);
	
	//release memory
	delete[] score;
	delete[] score_ptr;
	
	return 0;
	
}

//create array function (by dynamically memory allocation)
double *create_array(int total_num)
{
	//allocate memory space
	double *ptr = new double [total_num];
	//input score
	std::cout << "Begin input scores:\n";
	for(int i=0; i<total_num; i++)
	{
		std::cout << "What is the score for student " << i+1 << ": ";
		std::cin >> *(ptr+i);
		while (*(ptr+i) <0 || *(ptr+i) > 100 )
		{
			std::cout << "Invalid input, please input again: ";
			std::cin >> *(ptr+i);
		}
	}
	
	//after inputting, return memory address
	return ptr;
	
}

//selection sort function to sort the score address
void selection_sort(double **score_ptr, int size)
{
	int start_scan = 0;
	do
	{
		double *min = *(score_ptr+start_scan); //sort the pointer array
		int min_index = start_scan;
		//go over the score and find out the minimum
		for(int i=start_scan+1; i<size; i++)
			if (*min > *(*(score_ptr+i)))
			{
				min = *(score_ptr+i);
				min_index = i;
			}
		//exchange memory address stored in score_ptr array
		*(score_ptr+min_index) = *(score_ptr+start_scan);
		*(score_ptr+start_scan) = min;
		//update the start_scan position
		start_scan++;							
	} while (start_scan < size-1);
}

//average function. In order to drop the lowest score, this function should accept the sorted score_ptr as parameter, so it knows which is the lowest score
double average_score(double *score, int size, double **score_ptr)
{
	double total=0;
	//use a loop to calculate total
	for(int i=0; i<size; i++)
		total += *(score+i);
	//return average
	return (total-*(*(score_ptr)))/(size-1);
}

//display function
void display(double **score_ptr, double average, double *score, int size)
{
	std::cout << "Test scores (from lowest to highest):\n";
	//use a loop to display all the info, use (*score_ptr - score + 1) as the student id
	for(int i=0; i<size; i++)
	{
		std::cout << "Student " << (*(score_ptr+i) - score) + 1 << ": " << *(*(score_ptr+i)) << "\n";
	}
	std::cout << "\n";
	//print out the average score
	std::cout << "The average score is: " << average << std::endl;
	std::cout << "(With lowest score dropped).\n";
}



}


}

4. Test Scores #2
{

4-1) Task analysis
{
> modify problem 2, so the user will input name-score pairs. Names and scores are stored in two arrays.
> When displaying the sorted score, student name should also be displayed

}

4-2) gadget test
4-2-1) Is (ptr1-ptr2) an integer? Can it be used as subscript in array?
Code
{

#include <iostream>

int main()
{
	int num[5] = { 1,2,3,4,5 };
	int *ptr1 = &num[0], *ptr2 = &num[2];
	std::cout << num[ptr2-ptr1] << std::endl;
	
	return 0;
}
//The result shows: (ptr2 - ptr1) is an integer, and it can be used as subscript in array

}

4-3) Code
{

#include <iostream>
#include <string>

double *create_array_score(int total_num, std::string *name);
void selection_sort(double **score_ptr, int size);
double average_score(double *score, int size);
void display(double **score_ptr, double average, double *score, int size, std::string *name);

int main()
{
	//ask for a number
	std::cout << "How many scores to be entered: ";
	int total_num;
	std::cin >> total_num;
	
	//create an array of string to store the names of the student
	std::string *name = new std::string [total_num];
	
	//call a function to allocate the array and fill the array, return the starting address of the array. Fill the name[] array at the same time
	double *score = nullptr;
	score = create_array_score(total_num, name);
	
	//create an array of pointer and link them to each element in the score array
	double **score_ptr = new double *[total_num];
	for(int i=0; i<total_num; i++)
		*(score_ptr+i) = &(*(score+i)); //link the address of each element in score[] to score_ptr[]
	
	//call a function to sort score_ptr[] array, so the address pointing to the lowest score will be first element in score_ptr[]
	selection_sort(score_ptr, total_num);
	
	//call average function to calculate average, return
	double average;
	average = average_score(score, total_num);
	
	//display the result
	display(score_ptr, average, score, total_num, name);
	
	//release memory
	delete[] score;
	delete[] score_ptr;
	delete[] name;
	
	return 0;
	
}

//create array function (by dynamically memory allocation)
double *create_array_score(int total_num, std::string *name)
{
	//allocate memory space
	double *ptr = new double [total_num];
	//input score
	std::cout << "Begin input student names and scores:\n";
	for(int i=0; i<total_num; i++)
	{
		std::cout << "What is the name for student " << i+1 << ": ";
		std::cin.ignore();
		getline(std::cin, *(name+i));
		std::cout << "What is the score for " << *(name+i) << ": ";
		std::cin >> *(ptr+i);
		while (*(ptr+i) <0 || *(ptr+i) > 100 )
		{
			std::cout << "Invalid input, please input again: ";
			std::cin >> *(ptr+i);
		}
	}
	
	//after inputting, return memory address
	return ptr;
	
}

//selection sort function to sort the score address
void selection_sort(double **score_ptr, int size)
{
	int start_scan = 0;
	do
	{
		double *min = *(score_ptr+start_scan); //sort the pointer array
		int min_index = start_scan;
		//go over the score and find out the minimum
		for(int i=start_scan+1; i<size; i++)
			if (*min > *(*(score_ptr+i)))
			{
				min = *(score_ptr+i);
				min_index = i;
			}
		//exchange memory address stored in score_ptr array
		*(score_ptr+min_index) = *(score_ptr+start_scan);
		*(score_ptr+start_scan) = min;
		//update the start_scan position
		start_scan++;							
	} while (start_scan < size-1);
}

//average function
double average_score(double *score, int size)
{
	double total=0;
	//use a loop to calculate total
	for(int i=0; i<size; i++)
		total += *(score+i);
	//return average
	return total/size;
}

//display function. name[] string array is included to display names
void display(double **score_ptr, double average, double *score, int size, std::string *name)
{
	std::cout << "Test scores (from lowest to highest):\n";
	//use a loop to display all the info, use (*score_ptr - score + 1) as the student id
	for(int i=0; i<size; i++)
	{
		std::cout << *(name+(*(score_ptr+i) - score)) << ": " << *(*(score_ptr+i)) << "\n";
	}
	std::cout << "\n";
	//print out the average score
	std::cout << "The average score is: " << average << std::endl;
}



}


}

5. Pointer Rewrite
{

5-1) Task analysis
rewrite the function using reference variables, and test it in a complete program

5-2) Code
{

#include <iostream>
//function prototype
int doSomething_reference(int &x, int &y);
int doSomething_pointer(int *x, int *y);

int main()
{
	//define two variables
	int a = 10, b = 20;
	//define two pointers that points to the two integers
	int *ptr1 = &a, *ptr2 = &b;
	//define two int container to store the result of different function
	int result_reference, result_pointer;
	//run reference function to see result
	result_reference = doSomething_reference(a,b);
	//re-set variable value
	a = 10;
	b = 20;
	//run pointer function to see result
	result_pointer = doSomething_pointer(ptr1, ptr2);
	//display result
	std::cout << "Reference function result: " << result_reference << std::endl;
	std::cout << "Pointer function result: " << result_pointer << std::endl;
	
	return 0;
}

//reference version
int doSomething_reference(int &x, int &y)
{
	int temp = x;
	x = y * 10;
	y = temp * 10;
	return x + y;
}

//pointer version
int doSomething_pointer(int *x, int *y)
{
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}

}

}

6. Case Study Modification #1
{

1) Task analysis
Modify program 9-19 so it can work with any number of donations. The program should dynamically allocate the donations array and ask the user to input its value.

2) gadget test
2-1) Dynamically allocate an array of pointers
Code
{

#include <iostream>

int main()
{
	int total = 5;
	int **num = new int *[total];
	int number[5] = { 1,2,3,4,5 };

	for (int i = 0; i < 5; i++)
		*(num+i) = &number[i];

	std::cout << *num[0] << std::endl;

	return 0;
}
//test successful, actually this technique has been demonstrated in problem 2 already

}

3) Code
{

#include <iostream>

void synchro(int *donation, int **ptr, int size);
void selection_sort(int **ptr, int size);
int *create_donation_array(int size);

int main()
{
	//ask for the total number of donations
	std::cout << "How many donations you'll input: ";
	int total_number;
	std::cin >> total_number;
	
	//define a pointer to store the donation array, and call a function to dynamically create such array. The array should be filled in that function too
	int *donation = nullptr;
	donation = create_donation_array(total_number);
	
	//create an array to store pointer to integer, using dynamically allocated memory
	int **ptr = new int *[total_number]; //when you define the pointer array, you should initialize it with something, if there is nothing to assign yet, you should to initialize them with nullptr, in this way, the memory won't be corrupted.
	
	//call a synchro function to link each element in donation with each element in ptr[]
	synchro(donation, ptr, total_number);
	
	//call a sort function to sort the pointer array
	selection_sort(ptr, total_number);
	
	//print out result
		//print out the sorted data
	std::cout << "The sorted donations are: \n";
	for(int i=0; i<total_number; i++)
		std::cout << "$ " << *ptr[i] << std::endl;
	std::cout << "\n";
		//print out the original data
	std::cout << "The original data is as follows:\n";
	for (int i=0; i<total_number; i++)
		std::cout << "$ " << donation[i] << std::endl;
	std::cout << "\n";
}

//create the donation array
int *create_donation_array(int size)
{
	int *ptr = new int [size];
	for(int i=0; i<size; i++)
	{
		std::cout << "What is the amount for donation " << i+1 << ": ";
		std::cin >> ptr[i];
	}
	//after inputting the amount, return the pointer to main
	return ptr;
}

//synchronize function
void synchro(int *donation, int **ptr, int size)
{
	//use a loop to link each other
	for(int i=0; i<size; i++)
		ptr[i] = &donation[i];
}

//pay attention that the min variable should have data type of pointer. Just keep in mind that min has the same data type as the sorted data. (same in original selection sorting)
void selection_sort(int **ptr, int size)
{
	int start_scan = 0;
	do
	{
		int *min = ptr[start_scan];
		int min_index = start_scan;
		for(int i=start_scan; i<size; i++)
			if(*min > *ptr[i])
			{
				min = ptr[i];
				min_index = i;
			}
		//exchange
		ptr[min_index] = ptr[start_scan];
		ptr[start_scan] = min;
		
		//update the start_scane position
		start_scan++;
		
	} while (start_scan < size-1);
}


}

}

7. Case Study Modification #2
{

1) Task analysis
Modify the sorting rule, so the array is sorted in descending order

2) Code
{

#include <iostream>

void synchro(int *donation, int **ptr, int size);
void selection_sort(int **ptr, int size);
int *create_donation_array(int size);

int main()
{
	//ask for the total number of donations
	std::cout << "How many donations you'll input: ";
	int total_number;
	std::cin >> total_number;
	
	//define a pointer to store the donation array, and call a function to dynamically create such array. The array should be filled in that function too
	int *donation = nullptr;
	donation = create_donation_array(total_number);
	
	//create an array to store pointer to integer, using dynamically allocated memory
	int **ptr = new int *[total_number]; //when you define the pointer array, you should initialize it with something, if there is nothing to assign yet, you should to initialize them with nullptr, in this way, the memory won't be corrupted.
	
	//call a synchro function to link each element in donation with each element in ptr[]
	synchro(donation, ptr, total_number);
	
	//call a sort function to sort the pointer array
	selection_sort(ptr, total_number);
	
	//print out result
		//print out the sorted data
	std::cout << "The sorted donations are: \n";
	for(int i=0; i<total_number; i++)
		std::cout << "$ " << *ptr[i] << std::endl;
	std::cout << "\n";
		//print out the original data
	std::cout << "The original data is as follows:\n";
	for (int i=0; i<total_number; i++)
		std::cout << "$ " << donation[i] << std::endl;
	std::cout << "\n";
}

//create the donation array
int *create_donation_array(int size)
{
	int *ptr = new int [size];
	for(int i=0; i<size; i++)
	{
		std::cout << "What is the amount for donation " << i+1 << ": ";
		std::cin >> ptr[i];
	}
	//after inputting the amount, return the pointer to main
	return ptr;
}

//synchronize function
void synchro(int *donation, int **ptr, int size)
{
	//use a loop to link each other
	for(int i=0; i<size; i++)
		ptr[i] = &donation[i];
}

//pay attention that the max variable should have data type of pointer. Just keep in maxd that max has the same data type as the sorted data. (same in original selection sorting)
void selection_sort(int **ptr, int size)
{
	int start_scan = 0;
	do
	{
		int *max = ptr[start_scan];
		int max_index = start_scan;
		for(int i=start_scan; i<size; i++)
			if(*max < *ptr[i])
			{
				max = ptr[i];
				max_index = i;
			}
		//exchange
		ptr[max_index] = ptr[start_scan];
		ptr[start_scan] = max;
		
		//update the start_scane position
		start_scan++;
		
	} while (start_scan < size-1);
}


}

}

8. Mode Function
{

1) Task analysis
write a function to accept two arguments: 1. an array of integers (all positive); 2. the size of the array. The function should then determine the mode of the array. If no element occurs more than once, the function should return -1. If the mode is found, return the mode.

Steps (the objective is changed)
{
	> ask user to input the maximum, minimum number of a random array, and the size of it
	> generate a random array based on user's input
	> create an array of pointers, and link with the array
	> sort the pointer array, so the value it points to is in ascending order
	> use a function to find out the repeat time of each unique term, record this information in two correlated vector: repeat_time and item.
	> go over the vector that stores the repeat time to find out the highest repeat time
	> go over the vector that stores the repeat time again, if one term matches the highest repeat time, print out the corresponding unique term
}

2) gadget trial
2-1) given an array with descending or ascending order, find out the repeat times for each unique term. For example, given array { 1,1,2,3,3,3,4,4,5,5,5,5 }, the function will show 1: 2 times, 2: 1 time, 3: 3 times, 4: 2 times, 5: 4 times.
Code
{

#include <iostream>
#include <vector>

int main()
{
	const int NUM = 10;
	int num[NUM] = { 1,1,1,2,3,3,4,5,6,7 };
	//define two vectors to store 1) the repeat time of each unique element; 2) each unique element that is in the array
	std::vector<int> repeat_time, item;

	int start_position = 0;
	do
	{
		int counter = 0;
		int i;
		for (i = start_position; i < NUM; i++)
		{
			if (num[start_position] == num[i])
			{
				counter++;
			}
			else
			{
				repeat_time.push_back(counter);
				item.push_back(num[start_position]);
				start_position += counter;
				break;
			}
		}
		if (i == 10) //when i equals 10, it means the last run ends by check condition in for loop header (!(i<NUM), rather than check condition in if header (!(num[start_position] == num[i]))
		//thus, you need to record the last element
		{
			repeat_time.push_back(counter);
			item.push_back(num[start_position]);
			start_position += counter;
		}
	} while (start_position < NUM);

	//print out result
	for (int i = 0; i < item.size(); i++)
		std::cout << "Number: " << item[i] << ". Repeat times: " << repeat_time[i] << std::endl;
	return 0;
}

}

2-2) Try a function, whose return type is the memory address of an array of pointers
Code
{

#include <iostream>

int ** pointer_build(int size); //return type is an array of pointer

int main()
{
	int **ptr = nullptr;
	int num[5] = { 1,2,3,4,5 }, size = 5;
	ptr = pointer_build(size);

	for (int i = 0; i < size; i++)
		*(ptr + i) = &(*(num + i));

	std::cout << **ptr << std::endl;
}

int ** pointer_build(int size)
{
	int **ptr = new int*[size];
	return ptr;
}

}


3) Code: a complete version, can find out all mode of an integer array
{

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//function prototype
void get_data(int &N_min, int &N_max, int &size);
int *random_array_generator(int N_min, int N_max, int size);
int **pointer_generator(int size, int *num);
void selection_sort(int **ptr, int size);
void analyze_data(int **ptr, int size, std::vector<int> &repeat_time, std::vector<int> &item);
void analyze_result(std::vector<int> repeat_time, std::vector<int> item);

int main()
{
	//ask for maximum, minimum number in the random array, and the size of it
	int N_min, N_max, size;
	get_data(N_min, N_max, size);
	
	//call a function to generate an int array, and initiate it with random number. The function should return the address of the array
	int *num = nullptr; //to hold the array
	num = random_array_generator(N_min, N_max, size);
	
	//call a function to create an array of pointers that link to the random array
	int **ptr = nullptr; //define a container to store the first memory address of  the array of pointers
	ptr = pointer_generator(size, num); //transfer the pointer array to ptr
	
	//sort the pointer array, so the value it points to is in ascending order
	selection_sort(ptr, size);
	
	//define two vectors to store the repeat time and each unique term in the num array
	std::vector<int> repeat_time, item;
	
	//call a function to fill the repeat_time and item vector
	analyze_data(ptr, size, repeat_time, item);
	
	/* Call a function to first find out the maximum repeat_time, then print out the items that this maximum repeat_time. These are the mode of the array. Finally print out the repeated times for these modes. If no item appear more than onec, print the information that all numbers are evenly distributed */
	analyze_result(repeat_time, item);
	
	//print the array
	for (int i=0; i<size; i++)
		std::cout << *(num+i) << " ";
	std::cout << std::endl;
	
	return 0;
}

//input data
void get_data(int &N_min, int &N_max, int &size)
{
	std::cout << "Please input the minimum number in the random number array: ";
	std::cin >> N_min;
	std::cout << "Please input the maximum number in the random number array: ";
	std::cin >> N_max;
	std::cout << "How many numbers in the array: ";
	std::cin >> size;
	while (size <=0)
	{
		std::cout << "Error! numbers of elements should be at least one, please input again: ";
		std::cin >> size;
	}
}

//create the target random array
int *random_array_generator(int N_min, int N_max, int size)
{
	//allocate a memory space for size int units
	int *ptr = new int [size]; 
	
	//seed the random number
	int seed = time(0);
	srand(seed);
	
	//use a loop to initialize the random array
	for (int i=0; i<size; i++)
		*(ptr+i) = rand()%(N_max-N_min+1)+N_min;
	
	//return memory address
	return ptr;
}

//create an array of pointer points to the random array
int **pointer_generator(int size, int *num)
{
	//create an array of pointers with the size given
	int **ptr = new int *[size];
	
	//link each pointer with each element in the random array
	for(int i=0; i<size; i++)
		*(ptr+i) = &(*(num+i));
	
	//return the address for the pointer array
	return ptr;
}

//sort the pointer array (based on an ascending order of the value these pointers point to)
void selection_sort(int **ptr, int size)
{
	int start_scan = 0;
	do
	{
		//define minimum, mimimum should be the addressm *min is the value
		int *min = *(ptr+start_scan);
		int min_index = start_scan;
		
		//go over the remaining array to find out the minimum
		for (int i=start_scan+1; i<size; i++)
			if(*min > *(*(ptr+i)))
			{
				min = *(ptr+i);
				min_index = i;
			}
		//after finding the minimum, exchange minimum with start_scan
		*(ptr+min_index) = *(ptr+start_scan);
		*(ptr+start_scan) = min;
		
		//update the start_scan position
		start_scan++;
	} while (start_scan < size-1);
}

//analyze the data, fill the repeat_time and item vector
void analyze_data(int **ptr, int size, std::vector<int> &repeat_time, std::vector<int> &item)
{
	int start_position = 0;
	do
	{
		int counter = 0, i;
		
		//count the repeat time and store data
		for(i = start_position; i<size; i++)
		{
			if (*(*(ptr+start_position)) == *(*(ptr+i)))
			{
				counter++;
			}
			else
			{
				repeat_time.push_back(counter);
				item.push_back(*(*(ptr+start_position)));
				start_position += counter;
				break;
			}
		}
		
		//if i == 10, the above loop terminated by for, not else, so no data is recorded for the last element (because data recording happens in else section), we need to record it here
		if (i == size)
		{
			repeat_time.push_back(counter);
			item.push_back(*(*(ptr+start_position)));
			start_position += counter;			
		}
	} while (start_position < size);
	
	//after the above code, required data has been recorded in repeat time and item, and they are correlated.
}

//analyze the repeat_time vector and item vector to print out the final result: the mode, and the repeated times
void analyze_result(std::vector<int> repeat_time, std::vector<int> item)
{
	int high_repeat_time = repeat_time[0];
	
	//use a loop to find out the highese repeat time
	for (int i=0; i<repeat_time.size(); i++)
		if (high_repeat_time < repeat_time[i])
		{
			high_repeat_time = repeat_time[i];
		}
	
	//if highest repeat time is 1, this means all numbers are evenly distributed
	if(high_repeat_time == 1)
	{
		std::cout << "All numbers are evenly distributed! Thus no mode.\n";
		return;
	}
	
	//if not return, go over the repeat_time vector to find out the mode term
	std::cout << "The mode for this array is: \n";
	for(int i=0; i<repeat_time.size(); i++)
		if (repeat_time[i] == high_repeat_time)
		{
			std::cout << item[i] << std::endl;
		}
	std::cout << "Number of mode repeats: " << high_repeat_time << std::endl;
}



}

4) Code: a simpler version, only consider an array that has one mode
{

#include <iostream>

int main()
{
	const int NUM = 10;
	int num[NUM] = { 1,1,2,2,2,3,1,3,1,7 };
	int repeat_times, mode_index, mode_repeat = 0;

	for (int i = 0; i<NUM; i++)
	{
		repeat_times = 0;
		for (int j = 0; j<NUM; j++)
			if (num[i] == num[j])
			{
				repeat_times++;
			}
		if (repeat_times > mode_repeat)
		{
			mode_index = i;
			mode_repeat = repeat_times;
		}
	}

	//print out result
	std::cout << "Mode is " << num[mode_index] << ", repeated: " << mode_repeat << " times.\n";

	return 0;
}

}

}

9. Median Function
{

1) Task analysis
write a function to find out the median of an sorted array.
> for array with even number of elements, the median is the average of the two middle values
> for array with odd number of elements, the median is the middle value
> use pointer notation instead of array notation

2) Code
{

#include <iostream>
double find_median(int *num, int size);

int main()
{
	const int EVEN = 6, ODD = 7;
	int num_even[EVEN] = { 1,2,3,4,5,6 };
	int num_odd[ODD] = { 1,3,5,7,9,11,13 };
	
	//define a variable to hold median
	double median;
	median = find_median(num_even, EVEN);
	
	//print out result
	std::cout << "The median is: " << median << std::endl;
	
	return 0;
}

//find median function
double find_median(int *num, int size)
{
	if (size%2 == 0)
	{
		return 1/2.0*(*(num+size/2)+*(num+size/2-1));
	}
	else
	{
		return *(num+size/2);
	}
}

}

}

10. Reverse Array
{

1) Task Analysis
design a function that has following input:
	a) an int array
	b) the array's size
The function then returns the address of a new array, in which has the reversed elements compared with the original array

2) Code
{

#include <iostream>

int *reverse_array(int *num, int size);

int main()
{
	const int SIZE = 10;
	int num[SIZE] = { 1,6,5,4,3,7,8,2,3,0 };
	
	//define a pointer to hold the reversed array
	int *num_reverse = nullptr;
	num_reverse = reverse_array(num, SIZE);
	
	//print out the original and reversed array
	std::cout << "The original array: ";
	for(int i=0; i<SIZE; i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
	
	std::cout << "The reversed array: ";
	for(int i=0; i<SIZE; i++)
		std::cout << num_reverse[i] << " ";
	std::cout << std::endl;	
}

int *reverse_array(int *num, int size)
{
	//create a space to hold the new array
	int *ptr = new int [size];
	
	//fill the newly created space
	for(int i=0; i<size; i++)
		*(ptr+size-1-i) = *(num+i);
	
	//return the address
	return ptr;
}

}


}

11. Array Expander
{

1) Task analysis
build a function that accepts following parameter
	a) an int array
	b) the size of the array
it will do following things:
	a) create a new array with double size of the original array
	b) copy the array into the array, initialize the remaining element with 0
	c) return the address

2) Code
{

#include <iostream>

int *array_expander(int *num, int size);

int main()
{
	//create an array
	const int SIZE = 10;
	int num[SIZE] = { 5,6,4,22,5,78,6,5,44,91 };
	
	//call function to expand the array
	int *num_expanded = array_expander(num, SIZE);
	
	//print the original and expanded array
	std::cout << "The original array: ";
	for(int i=0; i<SIZE; i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
	
	std::cout << "The expanded array: ";
	for(int i=0; i<2*SIZE; i++)
		std::cout << num_expanded[i] << " ";
	std::cout << std::endl;		
}

int *array_expander(int *num, int size)
{
	//request a double space
	int *ptr = new int [2*size];
	
	//initiate the array
	for(int i=0; i<2*size; i++)
	{
		if (i<size)
			*(ptr+i) = *(num+i);
		else
			*(ptr+i) = 0;
	}
	
	//return the address
	return ptr;
	
}

}

}

12. Element Shifter
{

1) Task analysis
build a function that accepts following parameter
	a) an int array
	b) the size of the array
it will do following things:
	a) create a new array with one more element than the original array
	b) set the first element in the new array as zero, then copy the original array into the created array
	c) return the address

2) Code
{

#include <iostream>

int *array_shifter(int *num, int size);

int main()
{
	const int SIZE = 10;
	int num[SIZE] = { 6,5,3,4,1,8,9,2,5,0 };
	int *num_shifted = array_shifter(num, SIZE);
	
	std::cout << "The original array: ";
	for(int i=0; i<SIZE; i++)
		std::cout << num[i] << " ";
	std::cout << std::endl;
	
	std::cout << "The shifted array: ";
	for(int i=0; i<SIZE+1; i++)
		std::cout << num_shifted[i] << " ";
	std::cout << std::endl;	
}

int *array_shifter(int *num, int size)
{
	//request space
	int *ptr = new int[size+1];
	
	//initialize the first element
	*(ptr) = 0;
	
	//copy the original array to this array
	for(int i=1; i<size+1; i++)
		*(ptr+i) = *(num+i-1);
	
	//return the address
	return ptr;
	
}

}


}

13. Movie Statistics
{

1) Task analysis
> Input an array of movie data. The number of elements in this array is the number of students surveyed, and the value of the elements is the movie saw by each student
> calculate the average of the data
> calculate the mode of the data
> calculate the median of the data
> display result
/* You can use the program already created to calculate the statistical data */

2) gadget tweak
2-1) a function that returns vector
Code
{

#include <iostream>
#include <vector>

std::vector<int> return_vector(int size);

int main()
{
	std::vector<int> numbers;
	int size = 5;
	numbers = return_vector(size);

	for (int i = 0; i < size; i++)
		std::cout << numbers[i] << std::endl;
	std::cout << "\n";

	return 0;
}

std::vector<int> return_vector(int size)
{
	std::vector<int> num;
	for (int i = 0; i < size; i++)
		num.push_back(0);
	return num;
}

}


3) Code
{

#include <iostream>
#include <vector>

//function prototype
int *get_data(int size);
std::vector<int> get_mode(int *num, int size);
int **pointer_generator(int size, int *num);
void selection_sort(int **ptr, int size);
void analyze_data(int **ptr, int size, std::vector<int> &repeat_time, std::vector<int> &item);
void analyze_result(std::vector<int> repeat_time, std::vector<int> item, std::vector<int> &mode);
double calc_average(int *num, int size);
double calc_median(int *num, int size);

int main()
{
	//define a pointer to store the movie data
	int *num = nullptr;

	//ask for size
	int size;
	std::cout << "How many students took the survey: ";
	std::cin >> size;
	while (size <= 0)
	{
		std::cout << "Please input a student number greater than zero: ";
		std::cin >> size;
	}

	//call a function to get array
	num = get_data(size);

	//call a function to get a vector that contains the mode of num[], and the repeat times
	std::vector<int> mode_info; //create a vector to store the mode information
	mode_info = get_mode(num, size);

	//call a function to get the average number
	double average; //to hold average number
	average = calc_average(num, size);

	//call a function to get the median of the array
	double median;
	median = calc_median(num, size);

	//display the result
	std::cout << "\n\nStatistical Result:\n";
	std::cout << "Average: " << average << std::endl;
	std::cout << "Median: " << median << std::endl;
	if (mode_info[0] == -1)
		std::cout << "No mode found because the numbers of movie seen is evenly distributed.\n";
	else
	{
		std::cout << "Mode: " << std::endl;
		for (int i = 0; i<mode_info.size() - 1; i++)
			std::cout << mode_info[i] << " ";
		std::cout << ". Repeat times: " << mode_info[mode_info.size() - 1] << std::endl;
	}

	//exit
	return 0;

}

//get data function
int *get_data(int size)
{


	//request space
	int *ptr = new int[size];
	//input movie data
	for (int i = 0; i<size; i++)
	{
		std::cout << "How movies did student " << i + 1 << " see in a month: ";
		std::cin >> *(ptr + i);
		while (*(ptr + i) < 0)
		{
			std::cout << "Number of movies see per month can't be negative, please input again: ";
			std::cin >> *(ptr + i);
		}
	}

	//return address
	return ptr;

}

//Mode function, it accepts an int array and its size, will return a vector that contains all the mode in the array, the last element in the vector will contain the repeated times of the mode
std::vector<int> get_mode(int *num, int size)
{
	//call a function to create an array of pointers that link to the array
	int **ptr = nullptr; //define a container to store the memory address of the array of pointers
	ptr = pointer_generator(size, num); //transfer the pointer array to ptr	

	//sort the pointer array, so the value it points to is in ascending order
	selection_sort(ptr, size);

	//define two vectors to store the repeat time and each unique term in the num array
	std::vector<int> repeat_time, item;

	//call a function to fill the repeat_time and item vector
	analyze_data(ptr, size, repeat_time, item);

	//call a function to analyze the result: findout out the mode, save the different modes into a vector: mode, and save the repeat times of the mode at the last element of mode[]
	std::vector<int> mode;
	analyze_result(repeat_time, item, mode);

	//now mode vector contains mode information, return it to main function
	return mode;
}

//pointer_generator function
int **pointer_generator(int size, int *num)
{
	//create an array of pointers with the size given
	int **ptr = new int *[size];

	//link each pointer with each element in the random array
	for (int i = 0; i<size; i++)
		*(ptr + i) = &(*(num + i));

	//return the address for the pointer array
	return ptr;
}

//selection sort function, sort the array's pointer array
void selection_sort(int **ptr, int size)
{
	int start_scan = 0;
	do
	{
		//define minimum, mimimum should be the addressm *min is the value
		int *min = *(ptr + start_scan);
		int min_index = start_scan;

		//go over the remaining array to find out the minimum
		for (int i = start_scan + 1; i<size; i++)
			if (*min > *(*(ptr + i)))
			{
				min = *(ptr + i);
				min_index = i;
			}
		//after finding the minimum, exchange minimum with start_scan
		*(ptr + min_index) = *(ptr + start_scan);
		*(ptr + start_scan) = min;

		//update the start_scan position
		start_scan++;
	} while (start_scan < size - 1);
}

//analyze the data, fill the repeat_time and item vector
void analyze_data(int **ptr, int size, std::vector<int> &repeat_time, std::vector<int> &item)
{
	int start_position = 0;
	do
	{
		int counter = 0, i;

		//count the repeat time and store data
		for (i = start_position; i<size; i++)
		{
			if (*(*(ptr + start_position)) == *(*(ptr + i)))
			{
				counter++;
			}
			else
			{
				repeat_time.push_back(counter);
				item.push_back(*(*(ptr + start_position)));
				start_position += counter;
				break;
			}
		}

		//if i == 10, the above loop terminated by for, not else, so no data is recorded for the last element (because data recording happens in else section), we need to record it here
		if (i == size)
		{
			repeat_time.push_back(counter);
			item.push_back(*(*(ptr + start_position)));
			start_position += counter;
		}
	} while (start_position < size);

	//after the above code, required data has been recorded in repeat time and item, and they are correlated.
}

//analyze the repeat_time vector and item vector to save the final result: the mode, and the repeated times into mode vector
void analyze_result(std::vector<int> repeat_time, std::vector<int> item, std::vector<int> &mode)
{
	int high_repeat_time = repeat_time[0];

	//use a loop to find out the highese repeat time
	for (int i = 0; i<repeat_time.size(); i++)
		if (high_repeat_time < repeat_time[i])
		{
			high_repeat_time = repeat_time[i];
		}

	//if highest repeat time is 1, this means all numbers are evenly distributed
	if (high_repeat_time == 1)
	{
		mode.push_back(-1); //if no mode, save -1 to the first element and return.
		return;
	}

	//if not return, go over the repeat_time vector to find out the mode term
	for (int i = 0; i<repeat_time.size(); i++)
		if (repeat_time[i] == high_repeat_time)
		{
			mode.push_back(item[i]); //save the mode item into mode
		}
	//save the high_repeat_time to the last element of the mode
	mode.push_back(high_repeat_time);
}

//average number
double calc_average(int *num, int size)
{
	double total = 0;
	for (int i = 0; i<size; i++)
		total += *(num + i);
	return total / size;
}

//get median
double calc_median(int *num, int size)
{
	if (size % 2 == 0)
	{
		return 1 / 2.0*(*(num + size / 2) + *(num + size / 2 - 1));
	}
	else
	{
		return *(num + size / 2);
	}
}


}


}












