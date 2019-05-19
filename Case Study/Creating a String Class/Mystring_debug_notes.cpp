#include "Mystring.h"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <vector>

/* Static variable definition */
int Mystring::destructor_call_num = 0;
int Mystring::constructor_call_num = 0;

/* Working functions for C-string */
//string size 
int Mystring::StrSize(const char *str) const
{
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	return counter;
}

//string concatnate, make sure str1 has enough room for str2
void Mystring::StrCat(char *string1, const char *string2)
{
	int counter = 0;
	while (string1[counter] != '\0')
		counter++;
	//at this point, string1[counter] = '\0'

	int i = 0; //another counter to copy string2 to string 1
	while (string2[i] != '\0')
		string1[counter + i] = string2[i++];

	string1[counter + i] = '\0'; //add a null character at the end of the array	
}

//string copy function, destination will be cleared, make sure destination has enough room
void Mystring::StrCpy(char *destination, const char *source)
{
	int i = 0;
	while (source[i] != '\0')
		destination[i] = source[i++];
	destination[i] = '\0';	
}

//string compare function, 1: string1 is after string2; -1: string1 is before string2; 0: string1 == string2
int Mystring::StrCmp(const char *string1, const char *string2)
{
	int i = 0;
	while (string1[i] != '\0' && string2[i] != '\0')
	{
		if (string1[i] > string2[i])
			return 1;
		else if (string1[i] < string2[i])
			return -1;
		else
			i++;
	}

	//after the while loop, one of the string come to end,check the final result
	if (string1[i] == string2[i])
		return 0;
	else if (string1[i] > string2[i])
		return 1;
	else
		return -1;
}

//string search, return the subscript of where the keyword begins. If no match found, return -1, underflow to the largest unsigned
int Mystring::StrStr(char *array, char *keyword, int x)
{
	int size_array = StrSize(array);
	int size_keyword = StrSize(keyword);
	
	for (int i = x; i<(size_array - size_keyword); i++)
	{
		int j;
		for (j = 0; j<size_keyword; j++)
			if (!(array[i + j] == keyword[j]))
				break;
		if (j == size_keyword)
			return i;
	}
	//if program proceeds here, it means no match can be found, return nullptr
	return -1;	
}

//integer to C_string function
char* Mystring::to_c_str(int num)
{
	//when num == 0
	if (num == 0)
	{
		char *string = new char[2];
		string[0] = '0';
		string[1] = '\0';
		return string;
	}

	//if the number is not zero
	//figure out how long is the number
	int num_copy;
	if (num < 0)
		num_copy = -num; //if number is negative, first calculate the absolute value.
	else
		num_copy = num;

	int size = 0;
	while (num_copy % 10 != 0)
	{
		num_copy /= 10;
		size++;
	}
	size -= 1;

	//now, size represents the number of digit, which means the magnitude of the number being transformed. For example, if number is 123, then size = 2 (10^2)
	//now, you need to request a memory space to store the string. The size should be size+2.
	int additional_lot;
	if (num < 0)
		additional_lot = 3;
	else
		additional_lot = 2;

	char *string = new char[size + additional_lot];

	//to get the divide digit
	int digit = 1;
	for (int i = 0; i<size; i++)
		digit *= 10;

	//to transform the number to string
	int i;
	num_copy = num;
	if (num < 0)
	{
		for (i = 1; i <= size + 1; i++)
		{
			string[i] = -num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[0] = '-'; //place the negative sign in front of the string 
		string[i] = '\0';
		//return address of the string
		return string;
	}
	else
	{
		for (i = 0; i <= size; i++)
		{
			string[i] = num_copy / digit + 48;
			num_copy %= digit;
			digit /= 10;
		}
		string[i] = '\0';
		//return address of the string
		return string;
	}
	
}


/* Memory allocation */
void Mystring::AllocateMemory(int num) //will allocate memory big enough to hold num characters, increase stepsize = 2^4
{
	if (array_capacity != 0) //if there is pre-allocated memory
	{
		delete[] str; //delete pre-allocated memory
		array_capacity = 0; //reset capacity
	}
	
	while (array_capacity - 1 < num)
		array_capacity += 16;
	array_capacity--; //exclude '\0'
	
	/* Allocate memory space */
	str = new char [array_capacity+1];

	/* Initialize with null */
	for (int i=0; i<array_capacity+1; i++)
		str[i] = '\0';
}


/* Constructor */
//1-default constructor
Mystring::Mystring()
{
	constructor_call_num++;
	std::cout << "constructor-1 called: " << constructor_call_num << "\n";
	array_capacity = 15; //default capacity of str
	str = new char [array_capacity+1]; //create a memory space, extra 1 is for the '\0'
	for (int i=0; i<array_capacity+1; i++) //initialize each element with '\0'
		str[i] = '\0';
}

//2-initialize with a string literal
Mystring::Mystring(const char *initial)
{
	constructor_call_num++;
	std::cout << "constructor-2 called: " << constructor_call_num << "\n";

	int initial_size = StrSize(initial); //hold the size of input
	array_capacity = 0;
	
	//Allocate enough memory 
	AllocateMemory(initial_size);
	
	//copy initial content into str
	StrCpy(str, initial);	
	
}

// 3
//initialize with first num characters in initial, start from position indicated by start
//if initial is not that long, copy to the end 
//default start index is zero
Mystring::Mystring(const char *initial, int num, int start)
{
	constructor_call_num++;
	std::cout << "constructor-3 called: " << constructor_call_num << "\n";

	/* Check input */
	if (start < 0 || num < 0)
	{
		std::cout << "Invalid start_position or length input, program shutting down...\n";
		exit(0);
	}
	
	/* Variable definition */
	array_capacity = 0;
	int char_num; //number of characters to be stored
	bool exceed; //flag, true: initial is not that long; false = initial is long enough
	
	/* Determine whether initial is long enough or nor */
	if (StrSize(initial) >= start+num)
		exceed = false;
	else 
		exceed = true;
	
	/* Determine number of characters to be stored in str */
	if (exceed)
	{
		char_num = StrSize(initial) - start;
	}
	else
		char_num = num;
	
	/* Determine memory space needed */
	array_capacity = 0;
	AllocateMemory(char_num);
	
	/* Copy content */
	int i = 0;
	for (i; i<char_num; i++)
		str[i] = initial[i+start];
	str[i] = '\0';
	
}

//4-initialize with multiple letter, amount: num 
Mystring::Mystring(char letter, int num)
{
	constructor_call_num++;
	std::cout << "constructor-4 called: " << constructor_call_num << "\n";

	/* find out enough space */
	array_capacity = 0;
	while (array_capacity - 1 < num)
		array_capacity += 16;
	array_capacity--; //exclude '\0'
	
	/* Allocate memory space */
	str = new char [array_capacity+1];

	/* Copy letter to str */
	int i=0;
	for (i; i<num; i++)
		str[i] = letter;
	
	/* add a '\0' at the end */
	str[i] = '\0';
}

//5-copy constructor, initialize with a Mystring object
Mystring::Mystring(const Mystring &obj)
{
	constructor_call_num++;
	std::cout << "constructor-5 called: " << constructor_call_num << "\n";

	array_capacity = obj.array_capacity;
	str = new char [array_capacity+1];
	//copy content
	StrCpy(str, obj.str);
}

//6-initialize with  num characters in another Mystring object, beginning at start (default = 0)
Mystring::Mystring(const Mystring &obj, int num, int start)
{
	constructor_call_num++;
	std::cout << "constructor-6 called: " << constructor_call_num << "\n";

	/* Check input */
	if (start < 0 || num < 0)
	{
		std::cout << "Invalid start_position or length input, program shutting down...\n";
		exit(0);
	}

	/* Variable definition */
	array_capacity = 0;
	int char_num; //number of characters to be stored
	bool exceed; //flag, true: obj.str is not that long; false = obj.str is long enough
	
	/* Determine whether obj.str is long enough or nor */
	if (StrSize(obj.str) >= start+num)
		exceed = false;
	else 
		exceed = true;
	
	/* Determine number of characters to be stored in str */
	if (exceed)
	{
		char_num = StrSize(obj.str) - start;
	}
	else
		char_num = num;
	
	/* Determine memory space needed */
	array_capacity = 0;
	AllocateMemory(char_num);
	
	/* Copy content */
	int i = 0;
	for (i; i<char_num; i++)
		str[i] = obj.str[i+start];
	str[i] = '\0';	
}

//7-initialize with integer
Mystring::Mystring(int num)
{
	constructor_call_num++;
	std::cout << "constructor-7 called: " << constructor_call_num << "\n";

	//define a pointer to hold the address storing the C_string version of the integer
	char *initial = to_c_str(num);
	
	int size = StrSize(initial);
	AllocateMemory(size);
	
	//copy initial to str 
	StrCpy(str, initial);
	
	//release initial, which is dynamically allocated in to_c_str() function 
	delete[] initial;
}

/* Destructor */
//release memory 
Mystring::~Mystring()
{
	destructor_call_num++;
	std::cout << "Destructor called: " << destructor_call_num << "\n";
	delete[] str;
}


/* Accessor */
int Mystring::size() const 
{
	int counter = 0;
	while (str[counter] != '\0')
		counter++;
	
	return counter;
}

int Mystring::capacity() const 
{
	return array_capacity;
}

char Mystring::GetChar(int index) //return index-th element
{
	if (index >= StrSize(str))
	{
		std::cout << "Mystring subscript out of range! Program shutting down...\n";
		exit(0);
	}
	return str[index];
}


/* String Member Functions */
	// Mystring.append()
//appends num copies of ch to str 
Mystring Mystring::append(int num, char ch) 
{
	//create a temporary C-string containing num number of ch 
	char *temp_ch = new char [num+1];
	for (int i=0; i<num; i++)
		temp_ch[i] = ch;
	temp_ch[num] = '\0';
	
	//create a new C-string object to hold current content stored in this Mystring 
	char *temp_str = new char [array_capacity];
	StrCpy(temp_str, str);
	
	//calculate total size and allocate memory
	int total_size = StrSize(str) + num;
	AllocateMemory(total_size);
	//copy content in temp_str back in str
	StrCpy(str, temp_str);
	//append content in temp_ch back in str
	StrCat(str, temp_ch);
	
	//release temp_str space
	delete[] temp_str;
	delete[] temp_ch;
	
	return *this;
}

//appends Mystring object to *this str
Mystring Mystring::append(const Mystring &obj, int x)
{
	if (x > StrSize(obj.str))
	{
		std::cout << "Out of range error occurs, program exiting...\n";
		exit(0);
	}
	
	//calculate length of the transferred string
	int str_len = StrSize(obj.str)-x+1;
	//allocate a new C-string, store the content of transferred string into this C-string
	char *temp_str = new char [str_len];
	int i=0;
	for (i; i<str_len; i++)
		temp_str[i] = obj.str[i+x];
	
	//append to *this str
	if (StrSize(temp_str) == 0)
		return *this; //do nothing if the string size in temp_str is zero
	*this += temp_str;
	
	//release the space
	delete[] temp_str;
	
	return *this;
}

//appends Mystring object to *this str, including third parameter, which is the length of the appended sub-string 
Mystring Mystring::append(const Mystring &obj, int x, int n)
{
	//check boundary
	if (x > StrSize(obj.str))
	{
		std::cout << "Out of range error occurs, program exiting...\n";
		exit(0);
	}
	
	//calculate the length from x to end in obj.str
	int str_len = StrSize(obj.str)-x;
	bool exceed;
	if (n > str_len || n < 0)
		exceed = true;
	else 
		exceed = false;
	
	if (exceed)
	{
		append(obj, x);
	}
	else 
	{
		//allocate a new C-string, store the content of transferred string into this C-string
		char *temp_str = new char [n+1]; //+1 is for the '\0'
		int i=0;
		for (i; i<n; i++)
			temp_str[i] = obj.str[i+x];
		temp_str[i] = '\0';
		
		//append to *this str
		if (StrSize(temp_str) == 0)
			return *this; //do nothing if the string size in temp_str is zero
		*this += temp_str;
		
		//release the space
		delete[] temp_str;				
	}
	
	return *this;
	
}


	// Mystring.assign()
//assigns n copies of ch to *this string 
Mystring& Mystring::assign(int n, const char ch)
{
	Mystring temp;
	temp.append(n, ch);
	*this = temp;
	
	return *this;
}

// assign a Mystring to *this string
Mystring& Mystring::assign(const Mystring &obj)
{
	*this = obj;
	return *this;
}

//assigns first n characters to *this string
Mystring& Mystring::assign(const Mystring &obj, int n)
{
	Mystring temp;
	temp.append(obj, 0, n);
	*this = temp;
	return *this;
}

//assign n chs to *this string, start from x in obj
Mystring& Mystring::assign(const Mystring &obj, int x, int n)
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	Mystring temp;
	temp.append(obj, x, n);
	*this = temp;
	
	return *this;
}

	// Mystring.back()
//return the last character in Mystring
char Mystring::back() 
{
	return str[StrSize(str)-1];
}

	// Mystring.c_str()
//convert str into a C-string, return the pointer to the C-string
char *Mystring::c_str()
{
	//allocate a memory space to hold the C-string
	char *temp = new char [StrSize(str)+1];
	//copy content in str to temp[]
	StrCpy(temp, str);
	//return pointer to this C-string 
	return temp;
}

	// Mystring.clear()
//clear content in str, not influencing memory space allocated 
void Mystring::clear()
{
	for (int i=0; i<StrSize(str); i++)
		str[i] = '\0';
}
	
	// Mystring.compare()
//normal compare 
int Mystring::compare(const Mystring &str2)
{
	if (*this > str2)
		return 1;
	else if (*this == str2)
		return 0;
	else 
		return -1;
}
	
//advanced compare, start from x, continue for n character
int Mystring::compare(int x, int n, const Mystring &str2)
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	Mystring temp;
	temp.append(str2, x, n);
	
	if (*this > temp)
		return 1;
	else if (*this == temp)
		return 0;
	else 
		return -1;
}

	// Mystring.copy()
//copy substring of str2 to *this, start from x, for n characters
Mystring Mystring::copy(const Mystring &str2, int x, int n)
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	Mystring temp;
	temp.append(str2, x, n);
	
	*this = temp;
	
	return *this;
}
	
	// Mystring.empty()
//returns true if *this str is empty	
bool Mystring::empty()
{
	if (StrSize(str) == 0)
		return true;
	else 
		return false;
}
	
	// Mystring.erase()
Mystring& Mystring::erase(int x, int n) //erase n characters start from x	
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	//copy substring before the erased section
	Mystring temp_before;
	temp_before.append(*this, 0, x);
	
	//copy substring after the erased section
	Mystring temp_after;
	temp_after.append(*this, x+n, StrSize(str)-1);
	
	//update *this
	*this = temp_before + temp_after;
	
	return *this;
}
	
	// Mystring.find()
unsigned Mystring::find(const Mystring &obj, int x) //search if *this string contains a substring obj, starts at x in *this
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	return StrStr(str, obj.str, x);
}

	// Mystring.front()
char Mystring::front() //returns the first character in the str 
{
	if (StrSize(str) == 0)
	{
		std::cout << "Out of range error occurred! Program exiting...\n";
		exit(0);
	}
	return str[0];
}

	// Mystring.insert()
//insert several ch in position x, default number is 1
Mystring Mystring::insert(int x, char ch, int n) 
{
	if (x > StrSize(str))
	{
		x = StrSize(str);
	}
	
	//create the inserted string
	char *temp_str = new char [n+1];
	for (int i=0; i<n; i++)
		temp_str[i] = ch;
	temp_str[n] = '\0';
	
	//create the temp_str before insert section 
	Mystring temp_before;
	temp_before.append(*this, 0, x);
	//create the temp_str after the insert section 
	Mystring temp_after;
	temp_after.append(*this, x);
	
	//update *this
	*this = temp_before + temp_str + temp_after;
	
	//release memory
	delete[] temp_str;
	
	return *this;
}

//insert a Mystring object or C-string in position x, default position is x=0
Mystring Mystring::insert(const Mystring &obj, int x)
{
	if (x > StrSize(str))
	{
		x = StrSize(str);
	}	

	//create the temp_str before insert section 
	Mystring temp_before;
	temp_before.append(*this, 0, x);
	//create the temp_str after the insert section 
	Mystring temp_after;
	temp_after.append(*this, x);
	
	//update *this
	*this = temp_before + obj + temp_after;	
	
	return *this;
}


	// Mystring.replace()
Mystring& Mystring::replace(int x, int n, const Mystring &obj) //insert obj into x in *this str, and n characters in *this str will be replaced by characters in obj
{
	if (x > StrSize(str))
	{
		std::cout << "Out of range error occurred. Program is exiting...\n";
		exit(0);
	}
	
	//erase n characters from x in *this
	erase(x, n);
	
	//insert obj to x 
	insert(obj, x);
	
	return *this;
}

	// Mystring.resize()
void Mystring::resize(int n, char ch) //resize *this, if n is greater than current size, fill with ch (default '\0'); if n is smaller than current size, truncate to n
{
	if (n < 0)
	{
		std::cout << "Out of range error occured. Program is exiting...\n";
		exit(0);
	}
	
	if (n > StrSize(str)) //should resize the memory space
	{
		//create a string that should be added to *this
		char *temp_str = new char [n-StrSize(str)+1];
		for (int i=0; i<(n-StrSize(str)); i++)
			temp_str[i] = ch;
		temp_str[n-StrSize(str)] = '\0';
		
		//add to *this 
		*this += temp_str;
		
		//release memory
		delete[] temp_str;
	}
	
	else //truncate
	{
		for (int i=n; i<StrSize(str); i++)
			str[i] = '\0';
	}
}

	// Mystring.substr
//two parameter version 
Mystring Mystring::substr(int x, int n) const //return a substring of *this 
{
	Mystring temp;
	temp.append(*this, x, n);
	return temp;
}
//one parameter version 
Mystring Mystring::substr(int x) const
{
	Mystring temp;
	temp.append(*this, x);
	return temp;	
}

	// Mystring.swap()
void Mystring::swap(Mystring &right) //swap *this and right 
{
	Mystring temp = *this;
	*this = right;
	right = temp;
}


/* Operator */
// = //
//(Mystring = Mystring)
const Mystring Mystring::operator= (const Mystring &right)
{
	std::cout << "\n\nEntering operator= domain, string stored in rhs Mystring object will be assigned to lhs Mystring object\n";
	array_capacity = right.array_capacity;
	AllocateMemory(array_capacity);

	/* Copy content */
	StrCpy(str, right.str);
	std::cout << "Copy completed. *this has become:\n";
	std::cout << *this << "\n";
	std::cout << "Size: " << size() << "\n";
	std::cout << "Capacity: " << capacity() << "\n";
	std::cout << "Exiting operator= domain, a copied version of *this will be returned\nSince there is no other function accepting this return value, all return values are going to be deleted: return value generated during each operator's return. Destructor will be called to delete each of them.\n";
	return *this;
}

//(Mystring = C-string)
const Mystring Mystring::operator= (const char* initial)
{	
	//allocate memory and update array_capacity
	AllocateMemory(StrSize(initial));
	
	//copy content in initial into the str
	StrCpy(str, initial);
	
	//return 
	return *this;
}

// []
char& Mystring::operator[] (unsigned int index)
{
	if (index < 0) //boundary check
	{
		std::cout << "Mystring subscript out of range! Programming shutting down...\n";
		exit(0);
	}
	
	if (index >= static_cast<unsigned>(StrSize(str))) //re-size, fill the new slot with space
	{
		resize(index+1, ' ');
		return str[index];
	}
	return str[index];	
}

const char Mystring::operator[] (unsigned int index) const
{
	if (index >= static_cast<unsigned>(StrSize(str))) //boundary check
	{
		return '\0';
	}
	return str[index];		
}

// +
//+=: Mystring += Mystring
Mystring Mystring::operator+= (const Mystring &right)
{
	Mystring temp; //define a temporary container 
	int total_size = StrSize(str) + StrSize(right.str); //calculate the total number of characters needed 
	temp.AllocateMemory(total_size); //allocate memory
	
	//copy the content in *this object into temp
	StrCpy(temp.str, str);
	//concatenate content in right into temp
	StrCat(temp.str, right.str);
	
	//update *this string
	*this = temp;
	
	//return result
	return temp;
}

//Mystring += char
Mystring Mystring::operator+= (const char ch) 
{
	char temp[2] = { ch, '\0'};
	
	*this = *this + temp;
	return *this;
}

//Mystring + Mystring
Mystring Mystring::operator+ (const Mystring &right)
{
	std::cout << "Program is going to define a temp Mystring:\n";
	Mystring temp; //define a temporary container 
	std::cout << "Define complete. Program is going to calculate total_size of the temp should have:\n";
	int total_size = StrSize(str) + StrSize(right.str); //calculate the total number of characters needed 
	std::cout << "Total size calculation complete, total size = " << total_size << "\n";
	std::cout << "Begin allocate enough memory for temp:\n";
	temp.AllocateMemory(total_size); //allocate memory
	std::cout << "Memory allocation complete\n";

	//copy the content in *this object into temp
	std::cout << "Begin copy current string in value to temp\n";
	StrCpy(temp.str, str);
	std::cout << "Copy of current string in value to temp complete.\n";
	//concatenate content in right into temp
	std::cout << "Begin concatnate string in rhs (+) Mystring object to temp\n";
	StrCat(temp.str, right.str);
	std::cout << "Concatnate complete.\n";

	//return result
	std::cout << "Returning temp value. Return type is Mystring, copy constructor will be called to copy temp to return data. Then temp will be destroyed.\n";
	return temp;
}

//Mystring + C-string
Mystring Mystring::operator+ (const char *right)
{
	std::cout << "\n\nNow doing Mystring + C-string:\n";
	std::cout << "Define a temp Mystring:\n";
	Mystring temp; //define a temporary container 
	int total_size = StrSize(str) + StrSize(right); //calculate the total number of characters needed 
	temp.AllocateMemory(total_size); //allocate memory
	
	//copy the content in *this object into temp
	StrCpy(temp.str, str);
	//concatenate content in right into temp
	StrCat(temp.str, right);
	
	//return result 
	std::cout << "Allocation and copy complete, returning temp Mystring, copy constructor will be called. Then temp will be destroyed.\n";
	return temp;
}

//Mystring + char
Mystring Mystring::operator+ (const char ch)
{
	char temp[2];
	temp[0] = ch;
	temp[1] ='\0';
	
	return *this + temp;
}


/* Friend */
// <<
std::ostream& operator<< (std::ostream &out, const Mystring &obj)
{
	out << obj.str;
	return out;
}

// + (C-string + Mystring)
Mystring operator+ (const char* lhs, const Mystring &rhs)
{
	Mystring temp(lhs);
	return temp+rhs;
}
// + (character + Mystring)
Mystring operator+ (const char ch, const Mystring &obj)
{
	char temp[2];
	temp[0] = ch;
	temp[1] = '\0';
	
	return temp + obj;
}

// -
Mystring operator- (Mystring &lhs, const Mystring &rhs)
{
	int keyword_len = lhs.StrSize(rhs.str); //hold the length of keyword, used in erase()
	int start_index = 0;
	int match_index;
	
	while (start_index < lhs.StrSize(lhs.str)-lhs.StrSize(rhs.str))
	{
		match_index = lhs.find(rhs, start_index);
		
		if (match_index == -1)
			break;
		else
		{
			lhs.erase(match_index, keyword_len); //delete the keyword in lhs object
			start_index = match_index; //update search start_index 
		}
	}
	
	return lhs;
}

// >>
std::istream& operator>> (std::istream &in, Mystring &obj)
{	
	std::vector<char> temp; //define a temporary container for inputing character
	char temp_ch; //to temporarily hold a character read from keyboard buffer
	
	/* Skip all leading white space */
	in >> temp_ch;

	
	/* Read from keyboard buffer until the next whitespace */
	temp.push_back(temp_ch); //store into temp vector
	in.get(temp_ch); //read next character in keyboard buffer
	while (!isspace(temp_ch))
	{
		temp.push_back(temp_ch);
		in.get(temp_ch);
	}
	
	/* Determine the size, and allocate memory */
	obj.AllocateMemory(temp.size());
	
	/* Copy content from temp vector to Mystring */
	for (unsigned i=0; i<temp.size(); i++)
		obj.str[i] = temp[i];
	obj.str[temp.size()] = '\0';
	
	return in;
}

// getline() function 
std::istream& getline(std::istream &in, Mystring &obj, char delim)
{
	std::vector<char> temp; //define a temporary container for inputing character
	char temp_ch; //to temporarily hold a character read from keyboard buffer

	in.get(temp_ch); //read from the keyboard buffer
	while (temp_ch != delim) //while delimiter is not met
	{
		temp.push_back(temp_ch); //add to temp vector 
		in.get(temp_ch); //read the next character
	}
	
	/* Determine the size, and allocate memory */
	obj.AllocateMemory(temp.size());
	
	/* Copy content from temp vector to Mystring */
	for (unsigned i=0; i<temp.size(); i++)
		obj.str[i] = temp[i];
	obj.str[temp.size()] = '\0';
	
	return in;	
}

// relational operator
bool operator> (const Mystring &lhs, const Mystring &rhs)
{
	Mystring temp; //used for calling StrCmp function 
	if (temp.StrCmp(lhs.str, rhs.str) == 1)
		return true;
	else
		return false;
}

bool operator== (const Mystring &lhs, const Mystring &rhs)
{
	Mystring temp;
	if (temp.StrCmp(lhs.str, rhs.str) == 0)
		return true;
	else 
		return false;
}

bool operator>= (const Mystring &lhs, const Mystring &rhs)
{
	if (lhs > rhs || lhs == rhs)
		return true;
	else 
		return false;
}

bool operator< (const Mystring &lhs, const Mystring &rhs)
{
	if (!(lhs >= rhs))
		return true;
	else 
		return false;
}

bool operator<= (const Mystring &lhs, const Mystring &rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	else 
		return false;
}

bool operator!= (const Mystring &lhs, const Mystring &rhs)
{
	if (lhs == rhs)
		return false;
	else
		return true;
}
