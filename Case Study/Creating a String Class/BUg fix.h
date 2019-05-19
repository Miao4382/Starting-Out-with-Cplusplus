Bug-1 (found when I work with the first problem in chapter 14)
Problem:
the goal for that exercise is to make a class that can store integer value and print letter version for that integer value. I found that sometimes the program will crush when I input some integer value. For example:
if number = 100, the program works fine;
if number = 101, 102, the program will crush.

So, I set out for a journey to find out exatly what is going on with this bug.

method nad process:
I used std::cout << "here\n"; method to locate the step that goes wrong.
Then I write the "program running note" to find out the detail of what is going wrong. 
 "program running note" is to print what the program is doing on screen to have an idea of what step goes wrong.
 
 Then I find that, if I disable the delete[] str; expression in destructor, program can work fine. So, the problem might be:
 1) the destructor has deleted a memory address twice (this is also a "bad" memory example)
 2) the destructor deleted a "bad" memory space. "bad" means you wrote data to or read data from an illegal address, for example, std::string str = "1234", and you have expression like: str[5], or str[5] = 'a';
 
 Then I continue to dig.
 I found that, the program crushes when it trying to delete temporary Mystring objects during a certain stage of the program. (So it is trying to delete some "bad" memory).
 (These temp Mystring objects are the ones that created for the return data of operator +, =, review the appendix I for details I found for the working process of these operators)
 
 example:
 number = 100; str = "one hundred "; delete succeed.
 number = 101; str = "one hundred one"; delete failed.
 number = 102; str = "one hundred two"; delete failed.
 number = 103; str = "one hundred three"; delete succeed.

I found that, if str.size() == str.capacity(), delete will fail. This means there is something wrong with the memory space allocated to the str.

I checked the AllocateMemory() function in Mystring class, it will allocate enough memory to the str variable in Mystring. If I increase the memory space allocated to the str, it will solve some problem (but not all).

For this reason, I believe that the problem is related to the memory allocation. Possibly that when the size() is equal to capacity(), something will go wrong.

But the true bug still remain hidden. So I decide to trace the program bit by bit.
I found that, when the program return a value, if the return type is not reference, the copy constructor will be called to generate a copy of the return data (if the return data is the Mystring object). I followed the way of the copy constructor, and found the final bug: error in memory allocationg in copy constructor:

The array_capacity in Mystring class is to represent the memory space allocated for none '\0' character.
For example, if currently the memory space for a Mystring object is 32, the array_capacity should be 31 because you have to exclude the last '\0' character.

For this reason, when you allocate new memory space for the Mystring object, the final memory space should be array_capacity+1. 

However, in Mystring's copy constructor, I wrote:
	str = new char [array_capacity];
Apparently I forgot that array_capacity is not the actual size str needs, it needs array_capacity+1. So when size() == capacity(), you are missing the extra space for '\0', this will cause a problem when future codes are trying to assign '\0' to the extra address. 
This problem will not show up immediately when program writes data to the illegal memory address (because I don't have code for monitoring that), but will cause the program to crush when the delete compand trying to delete "bad" memory.

Back to example:

1) number = 100; str = "one hundred "; delete succeed.
2) number = 101; str = "one hundred one"; delete failed.
3) number = 102; str = "one hundred two"; delete failed.
4) number = 103; str = "one hundred three"; delete succeed.

the reason why 2) 3) not working is because, "one" and "two" are both length 3. before adding them, size() = 12, capacity() = 15, after adding them, size() = 15, capacity() = 15, real capacity() = 16 (add '\0'). However, the copy constructor create the return value with a capacity of only 15, and then write '\0' to the 16-th slot, which is illegal. So the memory space is corrupted. When delete[] is called to delete these memory space, error will occur.









Appendix I: construct and destruct process during calling of operator function 
example (this shows how the bug crushes the program)

value = value + "five";

where value is a Mystring object.
First, program will deal with operator+: value.operator+("five");
The definition of operator+ for Mystring + C-string is as follows. Calling of constructor and destructor will be added as notes beside each step 

Mystring Mystring::operator+ (const char *right) //return type is Mystring
{
	Mystring temp; //default constructor called 
	
	int total_size = StrSize(str) + StrSize(right);
	temp.AllocateMemory(total_size);
	
	StrCpy(temp.str, str);
	StrCat(temp.str, right);
	
	//return result 
	return temp; //copy constructor called to copy temp to returned object
				 //if memory allocation in copy constructor is new char [array_capacity], already has an error (the memory space has already be corrupted, problem will show up when this memory space is deleted)
				 //destructor called for destroying temp (because temp is defined here)
}

Then the returned object will be passed by reference to value.operator=() (it is not deleted yet):

const Mystring Mystring::operator= (const Mystring &right) //return type: const Mystring 
{
	array_capacity = right.array_capacity;
	AllocateMemory(array_capacity);

	/* Copy content */
	StrCpy(str, right.str);
	
	
	return *this; //when returning *this, copy constructor will be called again, copy *this to the return of operator=
				  //then the program will check if there is any other entity (within this statement) needs the return of operator= and operator+, if not, this statement completes, before going to next line, the system will destroy the created return object of operator= and operator+, so the destructor is called and error will occur, therefore the program crushes.
}



