#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class Mystring
{
private:
	/* Member variables */
	char *str; //hold the memory space dynamically allocated to store the address of a string
	int array_capacity; //hold the capacity of the object, capacity is the memory space allocated to str
	
	/* Working functions for C-string */
	int StrSize(const char *str) const; //accepts a pointer to C-string, returns an int, showing the size of the C-string, number of characters not including the null terminator
	void StrCat(char *string1, const char *string2); //string concatenate function, attach str2 to str1, str1 should be worked so it has enough room for the appending
	void StrCpy(char *destination, const char *source); //copy source to destination, content in destination will be cleared
	int StrCmp(const char *string1, const char *string2); //string compare. Return value: 1: string1 is after string2; -1: string1 is before string2; 0: string 1 == string 2
	int StrStr(char *array, char *keyword, int x=0); //string search, return the subscript of where the keyword begins. If no match found, return -1, underflow to the largest unsigned. Search start from x=0.
	char *to_c_str(int num); //integer to C_string function
	
	/* Memory allocation */
	void AllocateMemory(int num); //will allocate memory big enough to hold num characters, increase stepsize = 2^4
	
public:
	/* Constructor */
	Mystring(); //default constructor, create a string that hold 15 characters, allocate 15+1 space, the extra one is for the null terminator
	Mystring(const char *initial); //define and initialize with a "str" (string literal)
	Mystring(const char *initial, int num, int start=0); //initialize with first num characters in initial, start from position indicated by start, if initial is not that long, copy to the end, default start index is zero
	Mystring(char letter, int num=1); //initialize with multiple letter, amount: num
	Mystring(const Mystring &obj); //copy constructor
	Mystring(const Mystring &obj, int num, int start=0); //initialize with num characters in another Mystring object, start at start. If obj.str is not long enough, copy to the end
	Mystring(int num); //initialize with integer
	
	/* Destructor */
	~Mystring();
	
	
	/* Accessor */
	int size() const; //return size of the object, number of characters, not including end-null
	int capacity() const; //return capacity of the object, memory size allocated to the str 
	char GetChar(int index); //return index-th element
	
	
	/* String Member Functions */
	// Mystring.append()
	Mystring append(int num, char ch); //appends num copies of ch to str 
	Mystring append(const Mystring &obj, int x=0); //appends Mystring object to str, also accepts "C-string", start from the x-th character, default x = 0.
	Mystring append(const Mystring &obj, int x, int n); //appends Mystring object to str, also accepts "C-string", start from the x-th character, total length is n, if obj is not long enough, append to the end
	
	// Mystring.assign()
	Mystring& assign(int n, const char ch); //assigns n copies of ch to *this string
	Mystring& assign(const Mystring &obj); //assigns Mystring to *this string 
	Mystring& assign(const Mystring &obj, int n); //assigns first n characters to *this string
	Mystring& assign(const Mystring &obj, int x, int n); //assign n chs to *this string, start from x in obj
	
	// Mystring.back()
	char back(); //return the last character in Mystring
	
	// Mystring.c_str()
	char *c_str(); //convert str into a C-string, return the pointer to the C-string
	
	// Mystring.clear()
	void clear(); //clear content in str, not influencing memory space allocated
	
	// Mystring.compare()
	int compare(const Mystring &str2);
	int compare(int x, int n, const Mystring &str2); //start from x, continue for n character
	
	// Mystring.copy()
	Mystring copy(const Mystring &str2, int x, int n); //copy substring of str2 to *this, start from x, for n characters
	
	// Mystring.empty()
	bool empty(); //returns true if *this str is empty
	
	// Mystring.erase()
	Mystring& erase(int x, int n); //erase n characters start from x
	
	// Mystring.find()
	unsigned find(const Mystring &obj, int x=0); //search if *this string contains a substring obj, starts at x in *this
	
	// Mystring.front()
	char front(); //returns the first character in the str 
	
	// Mystring.insert()
	Mystring insert(int x, char ch, int n=1); //insert several ch in position x, default number is 1
	Mystring insert(const Mystring &obj, int x = 0); //insert a Mystring object in position x, default position is x=0
	
	// Mystring.replace()
	Mystring& replace(int x, int n, const Mystring &obj); //insert obj into x in *this str, and n characters in *this str will be replaced by characters in obj
	
	// Mystring.resize()
	void resize(int n, char ch = '\0'); //resize *this, if n is greater than current size, fill with ch (default '\0'); if n is smaller than current size, truncate to n
	
	// Mystring.substr(int x, int n)
	Mystring substr(int x, int n) const; //return a substring of *this 
	Mystring substr(int x) const; //return a substring of *this 
	
	// Mystring.swap()
	void swap(Mystring &right); //swap *this and right 
	
	/* Operator */
	// =
	const Mystring operator= (const Mystring &right);
	const Mystring operator= (const char* initial);
	// []
	char& operator[] (unsigned int index);
	const char operator[] (unsigned int index) const; 
	// += and +
	Mystring operator+= (const Mystring &right); //Mystring += Mystring
	Mystring operator+= (const char ch); //Mystring += char
	Mystring operator+ (const Mystring &right); //Mystring + Mystring
	Mystring operator+ (const char *right); //Mystring + C-string
	Mystring operator+ (const char ch); //Mystring + char
	
	/* Friend */
	// <<
	friend std::ostream& operator<< (std::ostream &out, const Mystring &obj);
	// +
	friend Mystring operator+ (const char* lhs, const Mystring &rhs); //C-string + Mystring
	friend Mystring operator+ (const char ch, const Mystring &obj); //char + Mystring
	// -
	friend Mystring operator- (Mystring &lhs, const Mystring &right); //Mystring - Mystring
	// >>
	friend std::istream& operator>> (std::istream &in, Mystring &obj);
	// getline() function 
	friend std::istream& getline(std::istream &in, Mystring &obj, char delim = '\n');
	// relational operator
	friend bool operator> (const Mystring &lhs, const Mystring &rhs);
	friend bool operator== (const Mystring &lhs, const Mystring &rhs);
	friend bool operator>= (const Mystring &lhs, const Mystring &rhs);
	friend bool operator< (const Mystring &lhs, const Mystring &rhs);
	friend bool operator<= (const Mystring &lhs, const Mystring &rhs);
	friend bool operator!= (const Mystring &lhs, const Mystring &rhs);
	
};



#endif









